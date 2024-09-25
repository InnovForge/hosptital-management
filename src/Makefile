all: build_and_run

build_and_run: build run

build:
	g++ main.cpp doctor.cpp person.cpp patient.cpp ui.cpp -o main

run:
	./main

clean:
	rm -f main
