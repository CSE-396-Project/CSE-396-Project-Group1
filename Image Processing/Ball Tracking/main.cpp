#include <vector>
#include <stdio.h>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

typedef struct Mask
{
	Mat frame;
	Scalar lower;
	Scalar upper;
}Mask;

inline uchar bound(int num, int incr)
{
	if(num+incr < 0)
		return 0;
	if(num+incr > 255)
		return 255;
	return num+incr;
}

void onMouseClick(int event, int x, int y, int flags __attribute__((unused)), void* userdata)
{
	if(event == EVENT_LBUTTONUP)
	{
		Mask* mask= (Mask*)userdata;
		Vec3b hsv = mask->frame.at<Vec3b>(y, x);
		mask->lower = Scalar(bound(hsv[0], -10), bound(hsv[1], -50), bound(hsv[2], -50));
		mask->upper = Scalar(bound(hsv[0], +10), bound(hsv[1], +50), bound(hsv[2], +50));
	}
}

vector<Point> maxContour(vector<vector<Point>> contours)
{
	vector<Point> c;
	double area, max = -1;
	for(size_t i = 0; i < contours.size(); ++i)
	{
		area = contourArea(contours[i]);
		if(area > max)
		{
			max = area;
			c = contours[i];
		}
	}
	return c;
}

int main()
{
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;		// 0 = open default camera
	int apiID = CAP_ANY;	// 0 = autodetect default API
	// open selected camera using selected API
	cap.open(deviceID, apiID);
	// check if we succeeded
	if (!cap.isOpened()) 
	{
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}

	Mat frame;
	Mask* mask = new Mask;
	namedWindow("Detector", WINDOW_AUTOSIZE);
	setMouseCallback("Detector", &onMouseClick, mask);

	/**	Optimized for orange
	 * mask->lower = cv::Scalar(0, 96, 105);
	 *	mask->upper = cv::Scalar(21, 255, 255);
	**/
	float radius;
	Point2f center;
	
	while(true)
	{
		// wait for a new frame from camera and store it into 'frame'
		cap.read(frame);

		if (frame.empty())
		{
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}
		// show live and wait for a key with timeout long enough to show images
		if (waitKey(1) == 27)
			break;

		cvtColor(frame, mask->frame, COLOR_BGR2HSV);		
		if(!mask->lower.isReal() && !mask->upper.isReal())
		{
			inRange(mask->frame, mask->lower, mask->upper, mask->frame);
			erode(mask->frame, mask->frame, Mat(), Point(-1,-1), 2);
			dilate(mask->frame, mask->frame, Mat(), Point(-1,-1), 2);
			vector<vector<Point>> contours;
			findContours(mask->frame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
			if(contours.size() > 0)
			{
				minEnclosingCircle(maxContour(contours), center, radius);
				if(200 > radius && radius > 10)
					circle(frame, center, radius, Scalar(0, 255, 255), 2);
			}
		}
		cv::imshow("Detector", frame);
	}
	cap.release();
	cv::destroyWindow("Detector");
	delete mask;
	return 0;
}
