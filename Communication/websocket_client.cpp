#include "websocket_client.h"

const std::vector<cv::Point> maxContour(std::vector<std::vector<cv::Point>> contours) {
	std::vector<cv::Point> c;
	double area, max = -1;
	for(size_t i = 0; i < contours.size(); i++) {
		area = cv::contourArea(contours[i]);
		if(area > max) {
			max = area;
			c = contours[i];
		}
	}

	return c;
}

void on_websocket_message(wpp_client* c, websocketpp::connection_hdl hdl, message_ptr msg) {
    auto payload = msg->get_payload();
    // std::cout << "Message arrived with size: " << payload.size() << std::endl;

    std::vector<char> current_frame_buffer;

    for (int i = 0; i < payload.size(); i++) {
    	current_frame_buffer.push_back(payload[i]);
    }

    // A captured frame can't have less than 1K bytes of size
    if (current_frame_buffer.size() < 1000) {
    	std::cerr << "Frame is not valid!" << std::endl;
    	return;
    }

	cv::Mat src = cv::imdecode(current_frame_buffer, cv::IMREAD_UNCHANGED);
	cv::Mat frame;
	cv::flip(src, frame, 1);

	cv::cvtColor(frame, common::mask->frame, cv::COLOR_BGR2HSV);
	if(!common::mask->lower.isReal() && !common::mask->upper.isReal()) {
		cv::inRange(common::mask->frame, common::mask->lower, common::mask->upper, common::mask->frame);
		cv::erode(common::mask->frame, common::mask->frame, cv::Mat(), cv::Point(-1,-1), 2);
		cv::dilate(common::mask->frame, common::mask->frame, cv::Mat(), cv::Point(-1,-1), 2);
		std::vector<std::vector<cv::Point>> contours;
		cv::findContours(common::mask->frame, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		if(contours.size() > 0) {
			cv::minEnclosingCircle(maxContour(contours), common::ball_center, common::ball_radius);
			float center_x = common::ball_center.x;
			float center_y = common::ball_center.y;
			float radi = common::ball_radius;
			std::cout << "Found at: " << center_x << ", " << center_y << ". Radius: " << radi << std::endl;

			float max_x = 300;
			float max_y = 200;

			center_x = center_x / max_x * 500.0f;
			center_y = center_y / max_y * 500.0f;

			common::ball_x = center_x;
			common::ball_y = center_y;

			common::ball_radius_int = radi;
		}
	}

    common::frames.push_back(current_frame_buffer);

    if (common::frames.size() == 255) {
    	common::frames.erase(common::frames.begin());
    }
}

void listen_websocket(std::string addr) {
    wpp_client client;

    try {
        client.set_access_channels(websocketpp::log::alevel::all);
        client.clear_access_channels(websocketpp::log::alevel::frame_payload);

        client.init_asio();

        client.set_message_handler(bind(&on_websocket_message,&client,::_1,::_2));

        websocketpp::lib::error_code err_code;
        wpp_client::connection_ptr con = client.get_connection("ws://" + addr + ":82", err_code);

        try {
        	std::string request_url = "http://" + addr + "/servo_control?" + "x=" + std::to_string(13) + "&y=" + std::to_string(37);
        	std::cout << "Request URL: " << request_url << std::endl;
			http::Request request(request_url);
			const http::Response response = request.send("GET");
        }
        catch(const std::exception &e) {
    	    std::cout << "Request failed, error: " << e.what() << std::endl;
        }

        if (err_code) {
            std::cout << "Could not create connection because: " << err_code.message() << std::endl;
            return;
        }

        client.connect(con);
        client.run();
    } 
    catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    }
}
