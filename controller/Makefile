CC = g++
CFLAGS = -std=c++17 -Wall

controller: controller.o Event.o TrafficController.o TrafficLight.o
	$(CC) $(CFLAGS) controller.o Event.o TrafficController.o TrafficLight.o -o controller

controller.o: controller.cpp
	$(CC) $(CFLAGS) -c controller.cpp

Event.o: Event.cpp Event.hpp
	$(CC) $(CFLAGS) -c Event.cpp

TrafficController.o: TrafficController.cpp TrafficController.hpp
	$(CC) $(CFLAGS) -c TrafficController.cpp

TrafficLight.o: TrafficLight.cpp TrafficLight.hpp
	$(CC) $(CFLAGS) -c TrafficLight.cpp

clear:
	rm *.o controller