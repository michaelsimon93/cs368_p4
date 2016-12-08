///////////////////////////////////////////////////////////////////////////////
//			ALL STUDENTS COMPLETE THESE SECTIONS
// Title: P4
// Files: main.cpp ComplexNumber.cpp ComplexNumber.h
// Semester: CS368 Spring 2016
// 
// Author: Michael Simon
// Email: masimon2@wisc.edu
// CS Login: msimon
// Lecturer's Name: Deppeler
// Lab Section: 
//
///////////////////////////////////////////////////////////////////////////////

/**
 * Main is just to test the ComplexNumber class
 *
 * <p>Bugs: None
 * 
 * @author Michael Simon
 */  


#include <iostream>
#include "ComplexNumber.h"
#include "ComplexNumber.cpp"
using namespace std;

int main(void){
	ComplexNumber C1;
	ComplexNumber C2;

	//Loops to keep the program from crashing from incorrect input
	while(true){
		cout << "Enter a complex number C1:\n";
		cin >> C1;
		if(cin.fail() == false)
			break;
		cerr << "ivalid format - must be a + bi\n\n";
		cin.clear();
		for(char b = ' '; b != '\n'; b = cin.get());
	}
	while(true){
		cout << "Enter a complex number C2:\n";
		cin >> C2;
		if(cin.fail() == false)
			break;
		cerr << "ivalid format - must be a + bi\n\n";
		cin.clear();
		for(char b = ' '; b != '\n'; b = cin.get());
	}
	
	//results of the calculations
	cout << "For C1 = " << C1 << " and C2 = " << C2 << " :\n";
	cout << "C1 + C2 = " << C1 + C2 << '\n';
	cout << "C1 - C2 = " << C1 - C2 << '\n';
	cout << "C1 * C2 = " << C1 * C2 << '\n';
	if(C1 == C2)
		cout << "C1 == C2 is true\n";
	else cout << "C1 == C2 is false\n";
	if(C1 != C2)
		cout << "C1 != C2 is true\n";
	else cout << "C1 != C2 is false\n";
	ComplexNumber tmp = C1;
	C1 += C2;
	cout << "After C1 += C2, C1 = " << C1 << '\n';
	C1 = tmp;
	C1 -= C2;
	cout << "After C1 -= C2, C1 = " << C1 << '\n';
	C1 = tmp;
	C1 *= C2;
	cout << "After C1 *= C2, C1 = " << C1 << '\n';
	C1 = tmp;
	cout.flush();
	
	return 0;
}
