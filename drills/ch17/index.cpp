#include "./../std_lib_facilities.h"


//17.4
void print_array10(ostream& os, int* a) {
	for (int i = 0; i < 10; ++i)
	{
		os << a[i] << " ";
	}
	os << "\n";
}


//17.7
void print_array(ostream& os, int* a, int n) {
	for (int i = 0; i < n; ++i)
	{
		os << a[i] << " ";
	}
	os << "\n";
}


//17.10
void print_vector(ostream& os, vector<int>& v) {
	for (int m : v) os << m << " ";
	os << "\n";
}

int main() {
	// 17.1 Free store memory allocation
	/* 
	free store memory can be allocated 
	without being immediately initialized
	*/
	int* array = new int[10];





	//17..2
	//Output is 10 zeros
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i] << endl;
	}


	//17.4
	//Printing data to output file stream
	ofstream ost {"output.txt"}; 
	print_array10(ost, array);
	// ost.close();


	//17.3
	//Array memory deallocated
	delete[] array;





	cout << "====array2" << endl;
	//17.5
	int* array2 = new int[10] {100, 101, 102, 103, 104,
	105, 106, 107, 108, 109};

	for (int i = 0; i < 10; ++i)
	{
		cout << array2[i] << endl;
	}
	//17.9
	delete[] array2;
	cout << "====array3" << endl;
	//17.6
	int* array3 = new int[11] {100, 101, 102, 103, 104,
	105, 106, 107, 108, 109, 110};

	for (int i = 0; i < 11; ++i)
	{
		cout << array3[i] << endl;
	}

	//17.7
	print_array(ost, array3, 11);
	// ost.close();


	//17.9
	delete[] array3;



	//17.8
	int* array4 = new int[20] {100, 101, 102, 103, 104,
		105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115
		, 116, 117, 118, 119};

	for (int i = 0; i < 20; ++i)
	{
		cout << array4[i] << endl;
	}

	//17.9
	delete[] array4;














	cout << "=====================================Vectors" << endl;

	//17.10
	vector<int> *vector10 = new vector<int>(10);
	// vector<int> vector10(10);
	int y = 100;

	for (int& v : *vector10) {
        v = y;
        ++y;
    }
	for (int x: *vector10) {
        cout << x << endl;
	}
		cout << "====Vector11" << endl;
	y = 100;
	vector<int> *vector11 = new vector<int>(11);

	for (int& v : *vector11) {
        v = y;
        ++y;
    }
	for (int x: *vector11) {
        cout << x << endl;
	}
	cout << "====Vector20" << endl;
	y = 100;
	vector<int> *vector20 = new vector<int>(20);

	for (int& v : *vector20) {
        v = y;
        ++y;
    }
	for (int x: *vector20) {
        cout << x << endl;
	}


	print_vector(ost, *vector10);
	print_vector(ost, *vector11);
	print_vector(ost, *vector20);
	ost.close();


	return 0;
}