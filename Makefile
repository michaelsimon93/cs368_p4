main: main.cpp ComplexNumber.h ComplexNumber.cpp 
	g++ -g main.cpp ComplexNumber.h
main.cpp: ComplexNumber.h ComplexNumber.cpp 
	g++ -c -g main.cpp
ComplexNumber.cpp: ComplexNumber.h
	g++ -c -g ComplexNumber.cpp

clean:
	\rm *.o *.h.gch
