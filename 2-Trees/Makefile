inc =  -lm

all:  main.cpp
	g++ -w -o main main.cpp -Wno-deprecated -I ${inc} 

main: main.cpp
	g++ -w -o main main.cpp -Wno-deprecated -I ${inc}

prob1: prob1.cpp
	g++ -w -o prob1 prob1.cpp -Wno-deprecated -I ${inc}

prob2: prob2.cpp
	g++ -w -o prob2 prob2.cpp -Wno-deprecated -I ${inc}

clean:
	rm -f main prob1 prob2
