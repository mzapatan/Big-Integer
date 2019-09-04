#include "FactorialPrueba.h"
 string FactorialPrueba::factorial(int n)
{
	int res[MAX];

	// Initialize result 
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);
	string salida;
	cout << "Factorial of given number is \n";
	for (int i = res_size - 1; i >= 0; i--) {
		cout << res[i];
		salida.push_back(to_string(res[i])[0]);
	}
	return salida;
}

 int FactorialPrueba::multiply(int x, int res[], int res_size)
 {
	 int carry = 0;  // Initialize carry 

		// One by one multiply n with individual digits of res[] 
	 for (int i = 0; i < res_size; i++)
	 {
		 int prod = res[i] * x + carry;

		 // Store last digit of 'prod' in res[]   
		 res[i] = prod % 10;

		 // Put rest in carry 
		 carry = prod / 10;
	 }

	 // Put carry in res and increase result size 
	 while (carry)
	 {
		 res[res_size] = carry % 10;
		 carry = carry / 10;
		 res_size++;
	 }
	 return res_size;
 }
