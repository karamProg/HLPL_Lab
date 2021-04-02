#include "./../std_lib_facilities.h"
class wrong_input{};
int main () {
	try {
		struct Point {
			int x;
			int y;
		};


		int x = 0;
		int y = 0;
		vector<Point> original_points;

		cout << "Enter points in the form of x and y values: e.g 5 7 " << endl;
		int n = 7;
		while(n>0) {
			cin >> x >> y;
			original_points.push_back(Point{x,y});
			n--;
		}
		cout << "Result of original_points vector: " << endl;
		for (const auto& point : original_points)
			cout << '(' << point.x << "," << point.y << ')' << endl;

		string oname = "mydata.txt";
		ofstream ost {oname}; 
		if (!ost) error("can't open output file ",oname);
		for (Point p : original_points) ost << '(' << p.x << ',' << p.y << ") ";
		ost.close();






		string iname = "mydata.txt";

		ifstream ifs { iname };

		if ( !ifs ) error ("Cannot open file: ", iname);


		vector<Point> processed_points;
		char ch1, ch2, ch3;
		string str;
		Point p;
		p.x = 0;
		p.y = 0;

		while(ifs >> ch1 >> x >> ch2 >> y >> ch3) {
		    if (ch1!='(' || ch2!=',' || ch3!=')') {
		        throw wrong_input();
		    }
		    p.x = x;
		    p.y = y;
            processed_points.push_back(p);
		}
		//Testing size to see if points were copied. 
		// cout << "Size of proccessed = " << processed_points.size() << endl;
		cout << "Result of processed_points vector: " << endl;
		for (const auto& processed : processed_points) {
			cout << '(' << processed.x << "," << processed.y << ')'<< endl;
		}
	}

	catch (exception& e) {
	    cerr << "Error: " << e.what() << '\n';
	    	return 1;
	}
	catch (...) {
    	cerr << "Something terrible has happened!\n";
    	return 2;
	}
}
