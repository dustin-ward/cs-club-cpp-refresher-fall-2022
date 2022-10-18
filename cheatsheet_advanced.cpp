#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
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

    // Dynamic Array
    int length = 5;
    int* arr = new int[length];
    delete[] arr;

    // 2-D Dynamic Array
    int N = 3, M = 4;
    int** arr2d = new int*[N];
    for(int i=0; i<N; ++i)
        arr2d[i] = new int[M];

    // Cleanup
    for(int i=0; i<N; ++i)
        delete[] arr2d[i];
    delete[] arr2d;


	// Pointers to custom data
	struct MyStruct {
		string data;
	
		string getData() {
			return this->data;
		}
	};
	
	MyStruct* my_data = new MyStruct;
	
	my_data->data = "Hello World!";		// Access pointer data and methods via
	cout<<my_data->getData()<<endl;		// the arrow operator. Not the dot.

	delete my_data;



	// Iterators
	vector<int> container = {1,5,7,3,8,9,2,3,0};
	
	// Iterator to 1st element
	std::vector<int>::iterator it_begin = container.begin();
	auto it_end = end(container);	// Another way to get iterator
	
	// From algorithm.h
	sort(it_begin, it_end);    		// STL sort function ascending
	sort(container.rbegin(), container.rend()); 	// Sort descending
	reverse(it_begin, it_end); 		// Reverse vector.

	int value;
	auto it = lower_bound(it_begin, it_end, value); // First element >= value

	it = upper_bound(it_begin, it_end, value);	// First element > value
	int pos = it - it_begin;			// How to get pos idx

	int val = *it;		// Access value at iterator by dereferencing.
	


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

class BaseClass {};

class MyClass : public BaseClass {
    public:
        MyClass() {
            privateData = new int;
        };

        ~MyClass() {
            delete privateData;
        };

        void publicFunc();
    
        friend int operator+(MyClass&, MyClass&);

    private:
        int* privateData;
};

void MyClass::publicFunc() {
    // implementation here
}

int operator+(MyClass &a, MyClass &b) {
    return *a.privateData + *b.privateData;
}
