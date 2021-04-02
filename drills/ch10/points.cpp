#include "./../std_lib_facilities.h"
class wrong_input{};
class size_error{};
int main () {
	try {
		struct Point {
			int x;
			int y;
		};


		int x,y;
		vector<Point> original_points;
		char ch1, ch2, ch3;
		cout << "Enter points in the form of x and y value pairs: e.g. (5,7) " << endl;
		int n = 7;
		while(n>0) {
			cin >> ch1 >> x >> ch2 >> y >> ch3;
			if (ch1!='(' || ch2!=',' || ch3!=')') {
		        throw wrong_input();
		    }
			original_points.push_back(Point{x,y});
			n--;
		}

		string oname = "mydata.txt";
		ofstream ost {oname}; 
		if (!ost) error("can't open output file ",oname);
		for (Point p : original_points) ost << '(' << p.x << ',' << p.y << ") ";
		ost.close();






		string iname = "mydata.txt";

		ifstream ifs { iname };

		if ( !ifs ) error ("Cannot open file: ", iname);


		vector<Point> processed_points;
		string str;
		Point p;

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


		cout << "Result of original_points vector: " << endl;
		for (const auto& point : original_points)
			cout << '(' << point.x << "," << point.y << ')' << endl;


		cout << "Result of processed_points vector: " << endl;
		for (const auto& processed : processed_points) {
			cout << '(' << processed.x << "," << processed.y << ')'<< endl;
		}
		if(original_points.size() != processed_points.size()) {
			throw size_error();
		}
		int counter = 0;
		for (const auto& point : original_points) {
			if(point.x != processed_points[counter].x || point.y != processed_points[counter].y) {
				cout << "Something is wrong, boy!" <<endl;
				break;
			}
			counter++;
		}


	}

	catch (exception& e) {
	    cerr << "Error: " << e.what() << endl;
	    	return 1;
	}
	catch (size_error&) {
		cerr << "ERROR: The sizes of the vectors are not equal!!" << endl;
	}
	catch (wrong_input&) {
		cerr << "ERROR: Data was not inputted properly!" << endl;
	}
	catch (...) {
    	cerr << "Something terrible has happened!\n";
    	return 2;
	}
}
