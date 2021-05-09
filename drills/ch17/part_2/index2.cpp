#include "./../../std_lib_facilities.h"




void print_array(int* a, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}


int main () {
	//17.2.1
	int num = 7;
	int* p1 = &num;
	//17.2.2
	cout << "Pointer: "<< p1 << endl;
	cout << "Number: " << num << endl;
	//17.2.3
	int* array = new int[7] {1,2,4,8,16,32,64};
	int* p2 = array;

	//17.2.4
	cout << "Array pointer: " << p2 << endl;
	cout << "Array: ";
	print_array(array, 7);
	
	//17.2.5
	int* p3 = p2;
	//17.2.6
	p1 = p2;
	//17.2.7
	p3 = p2;


	//17.2.8
	cout << endl << "Pointers:" << endl; ;
	cout << p1 << endl << p2 << endl;
	cout << endl << "What they point to:" << endl ;
	cout << *p1 << endl << *p2 << endl;


	//17.2.9
	delete[] array;


	//17.2.10
	int* secondArray = new int[10] {1,2,4,8,16,32,64,128,256,512};
	p1 = secondArray;
	cout << "Second array: ";
	print_array(secondArray, 10);



	//17.2.11
	int* thirdArray = new int[10];
	p2 = thirdArray;

	//17.2.12
	for (int i = 0; i < 10; ++i)
	{
		p2[i] = p1[i];
	}
	cout << "Third array: ";
	print_array(thirdArray, 10);

	//17.2.13


// int* array = new int[7] {1,2,4,8,16,32,64};

	//Free store allocate vector 1
    vector<int> *v1 = new vector<int> {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    //creating a reference for vector1
    vector<int> &vr1 = *v1;

    //Free store allocate vector 2
    vector<int> *v2 = new vector<int> (10);
    //creating reference for vector 2
    vector<int> &vr2 = *v2;



	for (int j = 0; j < 10; ++j)
	{
		vr2[j] = vr1[j];
	}


    for (int v : *v2) cout << v << ' ';
    cout << endl;

	return 0;
}