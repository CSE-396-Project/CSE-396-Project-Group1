all: server

server: main.o websocket_client.o http_server.o
	g++ main.o websocket_client.o http_server.o -lpthread -lboost_system -lssl -lcrypto -lcpprest -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -o server

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

websocket_client.o: websocket_client.cpp
	g++ -std=c++17 -c websocket_client.cpp

http_server.o: http_server.cpp
	g++ -std=c++17 -c http_server.cpp

clean:
	rm -f server *.o