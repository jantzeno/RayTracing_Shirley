cpp_ppm:
	g++ -std=c++11 cpp/ppm.cpp -o bin/cppm

d_ppm:
	dmd d/ppm.d -of=bin/dppm

nim_ppm:
	nim cpp -o:bin/nimppm --nimcache=bin/nimcache nim/ppm.nim

java_ppm:
	javac -d bin java/ppm.java
	jar -cfe bin/java_ppm.jar ppm bin/ppm.class
	#java ppm ppm.jar

kotlin_ppm:
	kotlinc kotlin/ppm.kt -include-runtime -d bin/kotlin_ppm.jar

all:	cpp_ppm	d_ppm	nim_ppm	java_ppm kotlin_ppm

clean_linux:
	rm -rfv bin/*

clean_win:
	rm bin\* -Recurse -Force -Exclude .gitignore
