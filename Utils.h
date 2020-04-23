#pragma once
#include "framework.h"
#include <vector>
using namespace std;

// Common functions like randint, sorting etc.

namespace Utils {

	int randint(int min, int max);
	template<class T> void printVector(vector<T> vec, string separator = "");
 






	// template functions must be in header file
	template<class T>
	void printVector(vector<T> vec, string separator){
		cout << endl;
		for (UINT16 i = 0; i < vec.size(); i++) {
			cout << vec[i]
				 << separator;
		}
		cout << endl;
	}
}
