#include "./../std_lib_facilities.h"
//7.9
#include <cmath>

constexpr char number = '8';
//6.2
//7.11
constexpr char exit_case = 'e';
const string exit_trigger = "exit";
//7.11 No need for 'x', now program exits through 'exit' keyword
// constexpr char quit = 'x';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
//7.7
constexpr char square_root = 's';
const string square_trigger = "sqrt";
//7.9
constexpr char power = 'p';
const string power_trigger = "pow";
//7.10
const string declkey = "#";

double expression();

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var){
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val){
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s){
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
}

void set_value(string s, double d){
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
		error("set: undefined variable", s);
}

class Token{
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t){
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get(){

	if (full){
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch){
		case print:
		//7.11
		case exit_case:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		//7.9
		case ',':
			return Token(ch);
		//7.10
		case '#':
			return Token{let};
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch)){
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
    			cin.putback(ch);
    			//7.10
    			// if (s == declkey) return Token{let};
    			if (is_declared(s))
    				return Token(number, get_value(s));
    			//7.7
    			else if (s == square_trigger) return Token{square_root};
    			//7.9
    			else if (s == power_trigger) return Token{power};
    			//7.11
    			else if (s == exit_trigger) return Token{exit_case};
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
	}
}

void Token_stream::ignore(char c){

	if (full && c == buffer.kind){
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}

Token_stream ts;
//7.7
double sqrt_function(char k)

{
    Token t = ts.get();
    if (t.kind != '(') error("Expected '('");
    double m = expression();
    t = ts.get();
    if (t.kind != ')') error("Expected ')'");
    switch (k) {
    //7.8
    case square_root: {
    	if (m > 0) return sqrt(m);
    	error("Error: Cannot take the square root of negative numbers");
    }
    default:
        error("Square root error");
    }
}

//7.9
double power_function(char p)

{
	Token t = ts.get();
    if (t.kind != '(') error("'(' expected");
    double x = expression();
    t = ts.get();
    if (t.kind != ',') error("',' expected");
    t = ts.get();
    if (t.kind != number) error("Expected a number");
    //int i = narrow_cast<int>(t.value);
    int i = int(t.value);
    if (i != t.value) error("Power must be an integer");
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    switch (p) {
    case power: {
    	return pow(x, i);
    }
    default:
        error("Power function error");
    }
}


double primary(){

	Token t = ts.get();
	switch (t.kind){
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error ("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		//7.7
		case square_root: 
			return sqrt_function(t.kind);
		//7.9
		case power:
			return power_function(t.kind);
		default:
			error("primary expected");
	}
}

double term(){

	double left = primary();
	Token t = ts.get();
	while(true){
		switch (t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error ("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error ("%: Zero oszto");
				left = fmod (left, d);
				t = ts.get();
				break;
				/*
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression(){

	double left = term();
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void clean_up_mess(){
	ts.ignore(print);
}

double declaration(){
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement(){
	Token t = ts.get();
	switch(t.kind){
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void calculate(){
	
/*	double val = 0;

	while (cin)
		try {

		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << "=" << statement() << endl;
		*/
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		//7.11
		if (t.kind == exit_case) return;
		ts.putback(t);
		cout << "=" << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() 

try {

	//6.4
	cout << "Welcome to our simple calculator." << endl << 
	"Please enter expressions using floating-point numbers." << endl;
	//6.5
	//7.11 modified comment
	cout << "Available operations are: addition, subtraction, mutiplication, division, and modulous" << endl 
	<< "Type ';' to end and print an expression. Type 'exit' to quit the program!" << endl;
	//7.6
	define_name("k", 1000);
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	calculate();

	return 0;
} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}
