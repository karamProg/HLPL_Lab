#include "./../std_lib_facilities.h"


//18.1
int ga[10] = {1,2,4,8,16,32,64,128,256,512};


//18.2
void f(int a[], int n) {
	//18.3
	int la[10];
	for (int i = 0; i < 10; ++i)
	{
		la[i] = ga[i];
	}
	cout << "la:" << endl;
	for (int j = 0; j < n; ++j)
	{
		cout << la[j] << " ";
	}
	cout << endl << endl;

	int* p =  new int[n];
	for (int m = 0; m < n; ++m)
	{
		p[m] = a[m];
	}

	cout << "Free store array:" << endl;
	for (int x = 0; x < n; ++x)
	{
		cout << p[x] << " ";
	}
	cout << endl << endl;
	delete[] p;
}

int main() {

	//18.4
	f(ga, 10);

	int aa[10] {1,2,6,24,120,720,5040,40320,362880,3628800};

	//To calculate Factorial
	// int holder = 1;
	// for (int i = 0; i < 11; ++i)
	// {
	// 	holder *= i+1;
	// 	aa[i] = holder;
	// }


	f(aa, 10);
	return 0;
}