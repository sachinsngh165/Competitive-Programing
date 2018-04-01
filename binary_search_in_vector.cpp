std::vector<int> V;
// (fill V with values)
std::sort(V.begin(), V.end());

int numValsLessThan5 = std::lower_bound(V.begin(), V.end(), 5) - V.begin();
int numValsLessThanOrEqualTo5 = std::upper_bound(V.begin(), V.end(), 5) - V.begin();


// C++ code to demonstrate the working of lower_bound()
#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    // initializing vector of integers
    // for single occurrence
    vector<int> arr1 = {10, 15, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for multiple occurrences
    vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for no occurrence
    vector<int> arr3 = {10, 15, 25, 30, 35};    
     
    // using lower_bound() to check if 20 exists
    // single occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
            " (in single occurrence case) : ";
    cout << lower_bound(arr1.begin(), arr1.end(), 20) 
            - arr1.begin();
      
    cout << endl;
     
    // using lower_bound() to check if 20 exists
    // multiple occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
             "(in multiple occurrence case) : ";
    cout << lower_bound(arr2.begin(), arr2.end(), 20) 
            - arr2.begin();
      
    cout << endl;
      
    // using lower_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using lower_bound "
             "(in no occurrence case) : ";
    cout << lower_bound(arr3.begin(), arr3.end(), 20) 
            - arr3.begin();
      
    cout << endl;    
}