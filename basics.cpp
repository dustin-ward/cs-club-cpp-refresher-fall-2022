#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int add_function(int a, int&b);

void do_you_need_function_stubs() {
	cout<<"No"<<endl;
}

int main() {
	// Primitive Types
	
	// Character/Byte
	char var_char; // 8bit value (0 to 255)

	// Integers
	short 	     var_short; // 16bit signed (-2^15 to 2^15 - 1)
	int 	     var_int;   // 32bit signed (-2^31 to 2^31 - 1)
	long 	     var_long;  // 32bit signed (same as int)
	long long    var_ll;    // 64bit signed (-2^63 to 2^63 - 1)
	
	unsigned int var_uint;  // 32bit unsigned (0 to 2^32)

	// Floating Point
	float 	    var_float;   // 32bit signed decimal number
	double 	    var_double;  // 64bit signed decimal number
	long double var_ldouble; // 96bit signed decimal number

	// Ranges from limits.h
	cout<<"Max float range: " << std::numeric_limits<float>::max()<<endl;
	cout<<"Min float range: " << std::numeric_limits<float>::lowest()<<endl;
	cout<<"Smallest float: " << std::numeric_limits<float>::min()<<endl;
	cout<<"Max double range: " << std::numeric_limits<double>::max()<<endl;
	cout<<"Min double range: " << std::numeric_limits<double>::lowest()<<endl;
	cout<<"Smallest double: " << std::numeric_limits<double>::min()<<endl;
	cout<<"Max long double range: " << std::numeric_limits<long double>::max()<<endl;
	cout<<"Min long double range: " << std::numeric_limits<long double>::lowest()<<endl;
	cout<<"Smallest long double: " << std::numeric_limits<long double>::min()<<endl;

	// Arrays
	int int_array[10]; 			// Fixed size array
	char char_array[3] = {'a', 'b', 'c'};	// Declare and assign
	cout<<"char_array[0] = "<<char_array[0]<<endl;


	// Loops
	for(int i=0; i<10; i++) {
		int_array[i] = i;
	}

	for(int i=0; i<10; ++i)			// We dont need brackets for 
		cout<<int_array[i]<<" ";	// single line loops
	cout<<endl;

	int i=0;				// Same thing, but with while
	while(i < 10) {
		cout<<int_array[i]<<" ";
		i++;				// Make sure to increment the counter
	}
	cout<<endl;

	
	// Functions
	int x=1, y=2; // You can declare and assign on the same line	
	cout<<"Add function before:\n"<<"x = "<<x<<"\ny = "<<y<<endl;
	int result = add_function(x, y);
	cout<<"Add function result = "<<result<<endl;
	cout<<"Add function after:\n"<<"x = "<<x<<"\ny = "<<y<<endl;


	// STL
	vector<int> array;		// Resizeable array
	vector<int> filled_array(5, 1)	// Create size 5 filled with 1's
	
	filled_array.size()		// Returns size
	
	for(int i:filled_array)		// Range-based loop.
		cout<<i<<" ";		// Interates over all elements
	cout<<endl;

	for(int &i:filled_array)	// Use reference to mutate
		i++;

}

int add_function(int a, int &b) {
	// 'a' passed by value. It will not change out of scope
	// 'b' passed by reference. It will be changed out of scope
	b += a;
	a--;
	return a+b;
}
