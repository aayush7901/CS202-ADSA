inc =  -lm

all:  part1 part2 part3

part1: part1.cpp
	g++ -w -o part1 part1.cpp -Wno-deprecated -I ${inc}

part2: part2.cpp
	g++ -w -o part2 part2.cpp -Wno-deprecated -I ${inc}

part3: part3.cpp
	g++ -w -o part3 part3.cpp -Wno-deprecated -I ${inc}

clean:
	rm -f part1 part2 part3
