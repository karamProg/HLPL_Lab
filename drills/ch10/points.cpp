#include "./../std_lib_facilities.h"

int main () {
	try {
		struct Point {
			int x;
			int y;
		};


		int x = 0;
		int y = 0;
		vector<Point> original_points;


		int n = 1;
		while(n>0) {
			cin >> x >> y;
			original_points.push_back(Point{x,y});
			n--;
		}

		for (const auto& point : original_points)
			cout << '(' << point.x << ", " << point.y << ')' << endl;



		string oname = "mydata.txt";
		ofstream ost {oname}; 
		if (!ost) error("can't open output file ",oname);
		for (Point p : original_points) ost << '(' << p.x << ',' << p.y << ")\n";







		string iname = "mydata.txt";

		ifstream ifs { iname };

		if ( !ifs ) error ("Cannot open file: ", iname);
		vector<Point> Processed_points;
		string ch1, ch2, ch3;
		for (Point p; ifs >> ch1 >> p.x >> ch2 >> p.y >> ch3; )
        Processed_points.push_back(Point{p.x, p.y});

		for (const auto& point : Processed_points)
			cout << '(' << point.x << ", " << point.y << ')' << endl;
		return 0;
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
