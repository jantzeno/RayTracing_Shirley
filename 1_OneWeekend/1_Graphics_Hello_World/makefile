cpp_ppm:
	g++ -std=c++11 ./cpp/ppm.cpp -o ./bin/cppm

d_ppm:
	dmd ./d/ppm.d -of=./bin/dppm

nim_ppm:
	nim cpp -o:./bin/nimppm --nimcache=./bin/nimcache ./nim/ppm.nim

java_ppm:
	javac -d ./bin ./java/ppm.java
	jar -c -e ppm -f ./bin/ppm.jar ./bin/ppm.class
	#java ppm ppm.jar

all:	cpp_ppm	d_ppm	nim_ppm	java_ppm

clean:
	rm -rfv ./bin/*
