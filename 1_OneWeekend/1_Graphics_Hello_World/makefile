c++:
	g++ -std=c++11 ./C++/ppm.cpp -o ./bin/cppm

d:
	dmd ./D/ppm.d -of=./bin/dppm

nim:
	nim cpp -o:./bin/nimppm --nimcache=./bin/nimcache ./Nim/ppm.nim

java:
	javac -d ./bin ./Java/ppm.java
	jar -c -e ppm -f ./bin/ppm.jar ./bin/ppm.class
	#java ppm ppm.jar

all: c++ d nim java

clean:
	rm -fv ./bin/*
