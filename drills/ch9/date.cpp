#include "./../std_lib_facilities.h"

enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

vector<string> months {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Invalid{};

class Date {
private:
	int y; 
	Month m;
	int d;
	bool is_valid() 
	{
		if (y < 0 || d > 31 || d < 1) return false;

		return true;
	}
public:
	Date(): y{2000}, m{Month::jan}, d{1} {}

	Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd}
	{
		if(!is_valid()) throw Invalid{};
	}

	void set_year(int yy){ if(yy<0) error("Invalid year"); y = yy; }
	void set_month(Month mm){ m = mm; }
	void set_day(int dd){ d = dd; }

	int get_year() { return y; }
	Month get_month() { return m; }
	int get_day() { return d; }

	void add_day()
	{
		++d;
		if (d > 31)
		{
			d = 1;
			++m;
		} if (m == Month::jan)
		{
			++y;
		}
	}
};

ostream& operator<< (ostream& os, Date d)
{
	return os << d.get_year() << ". " 
		<< d.get_month() << " "
		<< d.get_day();
}

int main()
try {

	Date today(1978, Month::jun, 25);
	cout << today << endl;


	Date tomorrow;
	// cout << tomorrow << endl;
	today.add_day();
	tomorrow = today;
	cout << tomorrow << endl;
	return 0;
	
} catch (Invalid) {
	cerr << "Invalid date.\n";
	return 1;
}