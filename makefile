DEPS=-lpthread \
-lboost_system \
-lssl -lcrypto \
-lcpprest \
-lopencv_core \
-lopencv_imgproc \
-lopencv_imgcodecs \
-lopencv_highgui

all:
	+$(MAKE) -C ImageProcessing
	+$(MAKE) -C Communication
	+$(MAKE) -C Simulation
	+$(MAKE) -C DesktopApplication
	g++ ./ImageProcessing/image_processing.o \
	./Communication/http_server.o \
	./Communication/websocket_client.o \
	./Communication/main.o \
	$(DEPS) -o BBServer

clean:
	rm -f BBServer
	cd Communication && $(MAKE) clean
	cd ImageProcessing && $(MAKE) clean
	cd Simulation && $(MAKE) clean
	cd DesktopApplication && $(MAKE) clean
