#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <fstream>
using namespace std;


// Macro for something later
//#define HEX(x) setw(2)<<setfill('0')<<hex<<(int)(x)


// Globals / Constants
#define CONSTANT_VALUE = 9999;
const int GLOBAL_VARIABLE = 9998;


// Structs / Custom data types
struct MyStruct {
	int a;
	int b;
	int c[5];
	string d = "default values can go here";

	// Member functions can be declared in structs
	int getB() {
		return b;
	}

	// Operators can also be overloaded
	bool operator<(const MyStruct& m) {
		if(b == m.b)
			return a > m.a;
		else
			return b > m.b;
	}
};


// Functions / Stubs
int add_function(int a, int&b);

void do_you_need_function_stubs() {
	// If we write the whole function ABOVE main, we do
	// not need to write a stub.
	cout<<"No"<<endl;
}

bool mySortFunc(const MyStruct& a, const MyStruct&b) {
	return a.a > b.a;
}

// Main funciton
int main() {
	// Primitive Types
	
	// Character/Byte
	char var_char; // 8bit value (0 to 255)

	// Integers
	short 	     var_short; // 16bit signed (-2^15 to 2^15 - 1)
	int 	     var_int;   // 32bit signed (-2^31 to 2^31 - 1)
	long 	     var_long;  // 32bit signed (same as int)
	long long    var_ll;    // 64bit signed (-2^63 to 2^63 - 1)
	
	// Values are unknown if left uninitialized
	cout<<"var_short: "<<var_short<<"\nvar_int: "<<var_int<<"\nvar_ll: "<<var_ll<<endl;

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

	// Structs
	MyStruct S;
	S.a = 1;
	S.b = 2;
	int res = S.getB();
	

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


	// Reading from and Writing to files
	ofstream file_out;		// Create input filestream. fstream can do both r/w
	file_out.open("./testfile.txt");	// Open file from filename
	
	file_out << "DATA\nTO\nBE\nWRITTEN\n";	// Write data to file
	file_out.close();

	ifstream file_in;
	file_in.open("./testfile.txt");
	string line;			// Keep reading a string from file until
	while(getline(file_in, line))	// we reach EOF. The while condition will
		cout<<line<<" ";	// return false when EOF is read.
	cout<<endl;

	file_in.close();		// Close file


	// STL
	// From vector.h
	vector<int> array;		// Resizeable array
	vector<int> filled_array(5, 1);	// Create size 5 filled with 1's
	
	filled_array.push_back(3);	// Add a new element to the end of the array
	filled_array.pop_back();	// Remove the last element from the array
	filled_array.size();		// Returns size
	filled_array.empty();		// Returns true if the vector is empty
	
	for(int i:filled_array)		// Range-based loop.
		cout<<i<<" ";		// Interates over all elements
	cout<<endl;

	for(int &i:filled_array)	// Use reference to mutate
		i++;


	// Iterators
	std::vector<int>::iterator it_begin = array.begin(); // Iterator to 1st element
	auto it_end = end(array);			     // Another way to get iterator
	
	// From algorithm.h
	sort(it_begin, it_end);    		// STL sort function ascending
	sort(array.rbegin(), array.rend()); 	// Sort descending
	reverse(it_begin, it_end); 		// Reverse vector.

	int value;
	auto it = lower_bound(it_begin, it_end, value); // First element >= value

	it = upper_bound(it_begin, it_end, value);	// First element > value
	int pos = it - it_begin;			// How to get pos idx

	
	// Custom Sort
	vector<MyStruct> V(100, S);
	sort(V.begin(), V.end());

	sort(V.begin(), V.end(), mySortFunc);	// Using comparison function form above

	// Lambda function
	sort(V.begin(), V.end(), 		// Using lambda funciton in-place
		[](const MyStruct& a, const MyStruct& b) {
			return a.a > a.b;
		}
	);


	// Pointers / Memory Management
	int *a, *b, c; 	// Create int pointers (Unknown value. Both addr and value)
//	cout<<"location of 'a': "<<a<<" value = "<<*a<<endl; // UNSAFE DEREFERENCE!!!
//	cout<<"location of 'b': "<<b<<" value = "<<*b<<endl;

	a = new int;	// Allocated space for an int on the heap
	
	*a = 123;	// Change memory at the location being pointed to (Dereference)
	b = a;		// Change where in memory is being pointed to

	// Ptr value vs dereference
	cout<<"location of 'a': "<<a<<" value = "<<*a<<endl;
	cout<<"location of 'b': "<<b<<" value = "<<*b<<endl;
	cout<<"location of 'c': "<<&c<<" value = "<<c<<endl;

	// Must delete allocated memory to avoid leaks
	delete a;
	
	// Pointer Manipulation	
	struct Data {
		int a 	    = 1;	// 4 bytes
		int b  	    = 2;	// 4 bytes
		char c 	    = 0x1C;	// 1 byte
		long long d = 44444444;	// 8 bytes
		int *e;			// 8 bytes
	};

	Data D;		// Declare struct

	char *bytes = reinterpret_cast<char*>(&D); // Cast location of D to a char ptr
						   
	for(int i=0; i<sizeof(Data); ++i)	// Look at raw bytes of D
		cout<<setw(2)<<setfill('0')<<hex<<(int)(bytes[i])<<" ";
	cout<<endl;

}

// Sad function all the way at the bottom :(
int add_function(int a, int &b) {
	// 'a' passed by value. It will not change out of scope
	// 'b' passed by reference. It will be changed out of scope
	b += a;
	a--;
	return a+b;
}
