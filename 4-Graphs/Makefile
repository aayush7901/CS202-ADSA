inc =  -lm

all:  directed undirected prob1 prob2 prob3 prob4

directed: main_directed.cpp
	g++ -w -o directed main_directed.cpp -Wno-deprecated -I ${inc}

undirected: main_undirected.cpp
	g++ -w -o undirected main_undirected.cpp -Wno-deprecated -I ${inc}

prob1: prob1.cpp
	g++ -w -o prob1 prob1.cpp -Wno-deprecated -I ${inc}

prob2: prob2.cpp
	g++ -w -o prob2 prob2.cpp -Wno-deprecated -I ${inc}

prob3: prob3.cpp
	g++ -w -o prob3 prob3.cpp -Wno-deprecated -I ${inc}

prob4: prob4.cpp
	g++ -w -o prob4 prob4.cpp -Wno-deprecated -I ${inc}

clean:
	rm -f directed undirected prob1 prob2 prob3 prob4
