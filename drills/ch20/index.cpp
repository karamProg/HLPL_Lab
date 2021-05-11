#include "./../std_lib_facilities.h"

/*
Note:
Fot iterators:

1. begin() :- This function is used to return the beginning position of the container.

2. end() :- This function is used to return the after end position of the container.

*/

template<typename C>
void print(const C& c)
{
    for (auto& a : c)
        cout << a << ' ';
    cout << '\n';
}


//20.6
template<typename Iter1, typename Iter2>
    // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 make_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	if (f1 == e1)
	{
		cout << "Sequence is empty, there is nothing to copy.";
	} else {
	    for (Iter1 p = f1; p != e1; ++p)
	        *f2++ = *p;
	}
	return f2;
}


int main() {
	//20.1
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "arr: ";
	print(arr);
	//20.2
	vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "v: ";
	print(v);
	//20.3
	list<int> mylist {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "mylist: ";
	print(mylist);
	//20.4
	cout << "=================== Copies" << endl;
	int arr2[10];
	for(int i = 0; i < 10; i++)
    {
        arr2[i]=arr[i];
    }
    cout << "arr2: ";
    print(arr2);
	vector<int> v2 = v;
	cout << "v2: ";
	print(v2);
	list<int> mylist2 = mylist;
	cout << "mylist2: ";
	print(mylist2);



	//20.5
	//Looping over lists is different
	//You have to declare a special iterator first
	list<int>::iterator it;
	for(int j = 0; j < 10; j++)
    {
        arr2[j] += 2;
        v2[j] += 3;
        //Point the iterator to the beggining of the list
        it  = mylist2.begin();
        //Point it to our index
        advance(it, j);
        //Increment
        *it += 5; 
    }



    cout << "=================== Incremented" << endl;
    cout << "arr2: ";
    print(arr2);
    cout << "v2: ";
    print(v2);
    cout << "mylist2: ";
    print(mylist2);

    //20.7
    cout << "=================== Using copy" << endl;

    make_copy(begin(arr), end(arr), v.begin());
    make_copy(mylist.begin(), mylist.end(), begin(arr));

    cout << "arr: ";
	print(arr);
	cout << "v: ";
	print(v);

	cout << "mylist: ";
	print(mylist);
	cout << "arr: ";
	print(arr);


    //20.8
    cout << "=================== Find" << endl;
    //Declaring iterator
    vector<int>::iterator iter;
    //Trying to find index of number 3
    iter = find(v.begin(), v.end(), 3);
    if (iter != v.end())
    {
    	cout << "Number 3 found at index" << iter - v.begin() << endl;
    } else {
    	cout << "The value wasn’t found." << endl;
    }

    //Trying to find index of number 27
    iter = find(v.begin(), v.end(), 27);
    if (iter != v.end())
    {
    	cout << "Number 27 found at index" << iter - v.begin() << endl;
    } else {
    	cout << "The value wasn’t found." << endl;
    }


	return 0;
}
