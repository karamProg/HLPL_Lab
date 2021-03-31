#include "./../std_lib_facilities.h"

void swap_v(int a, int b) { 
	int temp; temp = a, a=b; b=temp; 
	cout << a << endl << b << endl;
};
void swap_r(int& a,int& b) { 
	int temp; temp = a, a=b; b=temp; 
	cout << a << endl << b << endl;
};	
// void swap_cr(const int& a, const int& b) { 
// 	int temp; temp = a, a=b; b=temp; 
// 	cout << a << endl << b << endl;
// };





int main () {
	int x = 7;
	int y =9;
	swap_v(x,y);
	swap_r(x,y);
	// swap_cr(x,y)
	cout <<endl << "-----" << endl;


	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	// swap_r(cx,cy);
	// swap_r(7.7,9.9);
	// swap_cr(cx,cy)
	cout <<endl << "-----" << endl;



	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
	swap_v(7.7,9.9);
	// swap_r(dx,dy);
	// swap_r(7.7,9.9);
	// swap_cr(dx,dy)


	return 0;
}

/*
Which functions and calls compiled, and why? 

**********Functions:
Only the first two functions because the third 
has constant assignment and the value of 
constants cannot be changed.


**********Calls:
1. First function calls:
The first function calls worked in all cases because it's 
just normal integers switching.

2. Second Function calls:
worked in the first case, with integers.
It didn't work in the second case with constants
	swap_r(cx,cy);
	binding reference ‘int&’ to ‘const int’ discards qualifiers
	swap_r(7.7,9.9);
	cannot bind non-const reference ‘int&’ to a value of type ‘int’
	swap_cr(cx,cy)

Also didn't work int he third case
	swap_r(dx,dy);
	swap_r(7.7,9.9);
	cannot bind non-const reference ‘int&’ to a value of type ‘int’

*/