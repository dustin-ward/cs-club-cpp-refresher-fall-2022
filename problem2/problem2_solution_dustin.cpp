/* ULeth Computer Science Club
 *  - C++ Refresher Fall 2022
 *
 * #########################   PROBLEM 2   ############################
 *
 * In this problem, you must implement a vector class that functions
 * similar to the standard vector in C++.
 *
 * The vector must support the following operations:
 *
 *   - '[]' operator
 *   - push_back()
 *   - size()
 *
 * Your vector should use dynamically allocated memory, as you cannot
 * know how many elements will be inserted into the vector at any given
 * time. You should also try to avoid just creating a large array at
 * the beginning of execution. Try to only resize it when more space
 * is actually needed.
 *
 * A template class with all of the required functions has been
 * provided. Just fill them all in :)
 *
 * You may need to create extra private variables or functions. That
 * is completely fine.
 *
 * When compiled, the main function will test the functionality of your
 * vector. You should see the following output:
 *
 * 0
 * 100
 * 0 1 2 3 4 5 6 7 8 9 ... 98 99
 *
 * ####################################################################
 */
#include <iostream>
using namespace std;

class myVector {
	public:
		// Constructor function
		//
		// This gets called when the vector is first
		// created. Any of your initialization code
		// should go here.
		myVector() {
			current_size = 0;
			max_size = INIT_SIZE;
			data = new int[INIT_SIZE];
		}

		// Destructor function
		//
		// This gets called when a vector is removed
		// from memory. Any dynamic memory created by
		// this class should be cleaned up here.
		~myVector() {
			delete[] data;
		}

		// Square-bracket operator overload
		//
		// This defines the functionality of the '[]'
		// operator. Think about what this operator does
		// on a vector normally. i.e vector[i];
		//
		// Watch out for out of bounds access!
		int& operator[](int idx) {
			if(idx < current_size)
				return data[idx];
			else
				cerr<<"ERROR: idx OUT OF BOUNDS"<<endl;
		}

		// Push_back function
		//
		// This function is called when the user wants to
		// add a number to our vector. If possible it should
		// insert the number into our vector, otherwise it 
		// should dynamically resize the vector to make room.
		void push_back(int val) {
			if(current_size == max_size) {
				int* new_arr = new int[max_size*2];
				for(int i=0; i<current_size; i++)
					new_arr[i] = data[i];

				delete[] data;
				data = new_arr;

				max_size *= 2;
			}
			data[current_size] = val;
			current_size++;
		}

		// Size function
		//
		// Returns the number of elements currently in
		// the vector.
		int size() {
			return current_size;
		}

	private:
		int current_size;
		int max_size;
		
		// This is how big your vector should be initially.
		const int INIT_SIZE = 4;
		
		// This is the core of our vector. This is where
		// numbers are stored.
		int* data;
};

int main() {
	// Create vector
	myVector V;

	// Start from size 0, and fill with numbers 0-99
	cout<<V.size()<<endl;
	for(int i=0; i<100; i++)
		V.push_back(i);

	// Check to make sure filling worked;
	cout<<V.size()<<endl;
	for(int i=0; i<V.size(); i++)
		cout<<V[i]<<" ";
	cout<<endl;
}
