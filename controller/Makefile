CC = g++
CFLAGS = -std=c++17 -Wall

output: controller.o TrafficController.o TrafficLight.o
	$(CC) $(CFLAGS) controller.o TrafficController.o TrafficLight.o -o output

controller.o: controller.cpp
	$(CC) $(CFLAGS) -c controller.cpp

TrafficController.o: TrafficController.cpp TrafficController.hpp
	$(CC) $(CFLAGS) -c TrafficController.cpp

TrafficLight.o: TrafficLight.cpp TrafficLight.hpp
	$(CC) $(CFLAGS) -c TrafficLight.cpp

clear:
	rm *.o output