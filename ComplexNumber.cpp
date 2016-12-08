///////////////////////////////////////////////////////////////////////////////
//
// Main Class File: main.cpp
// File: ComplexNumber.cpp
// Semester: CS368 Spring 2016
//
// Author: Michael Simon
// CS Login: msimon
// Lecturer's Name: Deppeler
// Lab Section:
//
///////////////////////////////////////////////////////////////////////////////

/**
 * The ComplexNumber class and the logic for the required operations.
 *
 * @author Michael Simon
 */

#include <iostream>
#include "ComplexNumber.h"
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Constructs a default Complex number 0.0 + 0.0i
 */
//Default 0-argument constructor.
ComplexNumber::ComplexNumber(){
	this->imag = 0.0;
	this->real = 0.0;
}

/**
 * Constructs a complex number with a given value
 *
 * @param real_part - the real part of the imaginary number
 * @param imaginary_part - the imaginary part of the imaginary number
 *
 */
//Copy Constructor
ComplexNumber::ComplexNumber(double real_part, double imaginary_part){
	this->imag = imaginary_part;
	this->real = real_part;
}

/**
 * Constructs a new complex number that is a copy of the given number
 *
 * @param rhs - the complex number to be copied
 */
ComplexNumber::ComplexNumber(const ComplexNumber & rhs) {
	this->real = rhs.real;
	this->imag = rhs.imag;
}

/**
 * Prints the complex number to the given output stream.  
 */
//Print function.
void ComplexNumber::print(ostream & out) const {
	if(this->real == 0 && this->imag == 0)
		out << 0;
	else if(this->imag == 0)
		out << this->real;
	else if(this->real == 0)
		out << this->imag << 'i';
	else{
		out << this->real;
		if(this->imag < 0)
			out << " - " << -this->imag << 'i';
		else out << " + " << this->imag << 'i';
	}
}	
/**
 * Compares two complex numbers and determines if they are equal or not
 *  
 *  @param rhs - the ComplexNumber that this will be compared to
 */
//Checks if entities are equal.
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
	if(this->imag == rhs.imag && this->real == rhs.real){
		return true;
	}else{
		return false;
	}
}
//Overloaded******************************************

/**
 * Assigns the value of rhs to this
 *
 * @param rhs - the ComplexNumber to be used 
 */
//Equal Overloaded Function
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	if(this == &rhs)
		return *this;
	else{
		this->real = rhs.real;
		this->imag = rhs.imag;
		return *this;
	}
}

/**
 * Increments this by rhs
 *
 * @param rhs - the ComplexNumber to be used 
 */
//+= overloaded function
const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	this->imag = this->imag + rhs.imag;
	this->real = this->real + rhs.real;
	return *this;
}

/**
 * Decrements this by rhs
 *
 * @param rhs - the ComplexNumber to be used 
 */
//-= overloaded function
const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	this->imag = this->imag - rhs.imag;
	this->real = this->real - rhs.real;
	return *this;
}

/**
 * Multiplies this by rhs
 *
 * @param rhs - the ComplexNumber to be used 
 */
//*= overloaded function
const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double rl = (this->real * rhs.real) - (this->imag * rhs.imag);
	double im = (this->real * rhs.imag) + (this->imag * rhs.real);
	this->real = rl;
	this->imag = im;
	return *this;	
}
//Overloaded/////////////////////////////////////////////////*^^
//Arithmetic Operators******************************************

/**
 * Addition function
 *
 * @param lhs - ComplexNumber1
 * @param rhs - ComplexNumber2
 */
//Addition
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	temp += rhs;
	return temp;
}

/**
 * Subtraction Function
 *
 * @param lhs - ComplexNumber1
 * @param rhs - ComplexNumber2
 */
//Subtraction
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	temp -= rhs;
	return temp;
}

/**
 * Multiplication Function
 *
 * @param lhs - ComplexNumber1
 * @param rhs - ComplexNumber2 
 */
//Multiplication
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	temp *= rhs;
	return temp;
}
//Arithmetic Operations///////////////////////////////////////////*^^

//Relational Operators**********************************************

/**
 * Compares two complex numbers and determines if they are equal 
 *
 * @param lhs - ComplexNumber1
 * @param rhs - ComplexNumber2 
 *
 * @return true if they are equal
 * @return false if they are not equal
 */
//Checking if Equal
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs))return true;
	return false;
}

/**
 * Compares two complex numbers to see if they are not equal
 *
 * @param lhs - ComplexNumber1
 * @param rhs - ComplexNumber2
 *
 * @return true if they are not equal
 * @return false if they are equal
 */
// Checking if not Equal
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs)) return false;
	return true;
}
//Relational Operators///////////////////////////////////////////*^^
//I/O Operators*****************************************************

/**
 * << Function
 *
 * @param out - variable to be outputted
 * @param n - ComplexNumber
 *
 * @return out 
 */
// <<
ostream & operator<<(ostream & out, const ComplexNumber & n){
	n.print(out);
	return out;
}

/**
 * >> Function 
 *
 * @param in - istream variable
 * @param n - ComplexNumber
 *
 * @return in
 */
// >>
istream & operator>>(istream & in, ComplexNumber & n){
	double realNum;double imagNum;char buffer; int sign; string temp;
    //Get rid of pre-existing white-spaces
	in.get(buffer);
	while (buffer == ' ' || buffer == '\n' || buffer== '\t') {
		in.get(buffer);
	}
	in.putback(buffer); // Puts back recently looked-at item

	//Input the realnumbers
	in >> realNum;

	//Parse through white-spaces
	in.get(buffer);
	while(buffer == ' ' || buffer == '\n' || buffer == '\t') in.get(buffer);
	//Check for Signs
	if(buffer == '-'){
		sign = -1;
	}else if (buffer == '+'){
		sign = 1;
	}else{
		cout << "Invalid input"<<endl;
		in.setstate(ios::failbit);
		return in;
	}

	//Take care of white spacing, again.
	in.get(buffer);
	while(buffer == ' ' || buffer == '\n' || buffer == '\t'){
		in.get(buffer);
	}
	in.putback(buffer);


	//Get the imaginary number portion.
	in >> temp;
	temp = temp.substr(0, temp.size()-1);
	imagNum = atof(temp.c_str());
	imagNum = imagNum * sign;

	n = ComplexNumber(realNum,imagNum);
	return in;

}
