#ifndef FACTORIALPRUEBA_H
#define FACTORIALPRUEBA_H
#include <string>
#include<iostream>
using namespace std;
class FactorialPrueba
{
#define MAX 50000 

	int multiply(int x, int res[], int res_size);

	// This function finds factorial of large numbers 
	// and prints them 
public:
	string factorial(int n);

	// This function multiplies x with the number  
	// represented by res[]. 
	// res_size is size of res[] or number of digits in the  
	// number represented by res[]. This function uses simple  
	// school mathematics for multiplication. 
	// This function may value of res_size and returns the  
	// new value of res_size 
		
	
};

#endif // !FACTORIALPRUEBA_H