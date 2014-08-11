build:
	g++ -std=c++11 main.cpp -o rez -Wall -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_core
run:
	./rez
clear:
	rm rez