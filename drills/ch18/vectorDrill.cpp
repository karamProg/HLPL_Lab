#include "./../std_lib_facilities.h"

//18.2.1
vector<int>gv {1,2,4,8,16,32,64,128,256,512};

//18.2.2
void f(vector<int> v) {
	//18.2.3
	vector<int> lv(v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		lv[i] = gv[i];
	}
	for (int j = 0; j < v.size(); ++j)
	{
		cout << lv[j] << " ";
	}
	cout << endl;

	vector<int> lv2 = v;
	for (int m = 0; m < v.size(); ++m)
	{
		cout << lv2[m] << " ";
	}
	cout << endl;
}

int main () {

	//18.2.4
	f(gv);
	vector<int> vv {1,2,6,24,120,720,5040,40320,362880,3628800};
	f(vv);
	return 0;
}
