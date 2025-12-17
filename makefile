make:
	g++ -std=c++17 -O2 -o proj1_p1.x proj1_p1.cpp
	g++ -std=c++17 -O2 -o proj1_p2.x proj1_p2.cpp

clean:
	rm -f proj1_p1.x proj1_p2.x

