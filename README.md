# cs368_p4

Description
For this assignment I implemented the ComplexNumber class that corresponds to the interface (i.e., the header file) that 
was provided. This requires overloading arithmetic, relational, assignment, and I/O operators. Also implemented a separate 
main function (in the file main.cpp) that tests the ComplexNumber class.

The ComplexNumber class
The ComplexNumber class is used to represent complex numbers and to define operations on complex numbers. The interface for the 
ComplexNumber class is given in the header file ComplexNumber.h. 

The main Function
Wrote a main function to test the overloaded operators of the ComplexNumber class. The main function reads in two 
complex numbers (using the overloaded input operator) and uses the overloaded operators to compute (and display the results of) the 
following (in this order):

C1 + C2
C1 - C2
C1 * C2
C1 == C2
C1 != C2
C1 += C2 (then reset C1 to its original value)
C1 -= C2 (then reset C1 to its original value)
C1 *= C2

An example of how the main function runs and the output it produces is given below:

Enter a complex number C1: 

4.2 + 8.3i

Enter a complex number C2: 

3.1 - 9.2i

For C1 = 4.2 + 8.3i and C2 = 3.1 - 9.2i : 

C1 + C2 = 7.3 - 0.9i

C1 - C2 = 1.1 + 17.5i

C1 * C2 = 89.38 - 12.91i

C1 == C2 is false

C1 != C2 is true

After C1 += C2, C1 = 7.3 - 0.9i

After C1 -= C2, C1 = 1.1 + 17.5i

After C1 *= C2, C1 = 89.38 - 12.91i
