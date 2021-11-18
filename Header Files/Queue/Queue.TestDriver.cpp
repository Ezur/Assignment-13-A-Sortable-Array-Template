// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include "Queue.h"
#include "Queue.h"

int main()
{
 // identification
 cout << "Programmer: Elise Zur\n";
 cout << "Programmer's ID: 1851550\n";
 cout << "File: " << __FILE__ << endl << endl;

// ****************************************

 cout << "Testing constructor() & size" << endl;
 cout << "--------------------------" << endl;
 Queue<int> a_int;
 assert(0 == a_int.size());

 Queue<string> a_str;
 assert(0 == a_str.size());

// ****************************************

 cout << "\nTesting copy constructor test" << endl;
 cout << "------------------------" << endl;
 Queue<int> b_int(a_int); // making (queue c) a copy of (queue a)
 assert(b_int.size() == a_int.size());
 for (int i = 0; i < a_int.size(); i++)
 {
   assert(b_int.front() == a_int.front());
   a_int.pop();
   b_int.pop();
 }

 Queue<string> b_str(a_str); // making (queue c) a copy of (queue a)
 assert(b_str.size() == a_str.size());
 for (int i = 0; i < a_str.size(); i++)
 {
   assert(b_str.front() == a_str.front());
   a_str.pop();
   b_str.pop();
 }

// ****************************************

 cout << "\nTesting object assignment operator test" << endl;
 cout << "------------------------------------" << endl;
 Queue<int> c_int;
 c_int = b_int;
 assert(c_int.size() == b_int.size());
 for (int i = 0; i < b_int.size(); i++)
 {
   assert(c_int.size() == b_int.size());
   c_int.pop();
   b_int.pop();
 }

 Queue<string> c_str;
 c_str = b_str;
 assert(c_str.size() == b_str.size());
 for (int i = 0; i < b_str.size(); i++)
 {
   assert(c_str.size() == b_str.size());
   c_str.pop();
   b_str.pop();
 }

// ****************************************

 cout << "\nTesting push(), front(), back(), & pop()" << endl;
 cout << "----------------------------------" << endl;
 a_int.push(2);
 a_int.push(4);
 int num = a_int.front();
 cout << "EXPECTED: 2 for first element" << endl;
 cout << "ACTUAL: " << num << endl;
 int num2 = a_int.back();
 cout << "EXPECTED: 4 for last element" << endl;
 cout << "ACTUAL: " << num2 << endl;

 a_str.push("hi");
 a_str.push("bye");
 string str = a_str.front();
 cout << "EXPECTED: hi for first element" << endl;
 cout << "ACTUAL: " << str << endl;
 string str2 = a_str.back();
 cout << "EXPECTED: bye for last element" << endl;
 cout << "ACTUAL: " << str2 << endl;

// ****************************************

 cout << "\nTesting empty()" << endl;
 cout << "---------------" << endl;
 a_int.pop();
 a_int.pop();
 cout << "EXPECTED: 1 (TRUE)" << endl;
 cout << "Actual: " << a_int.empty() << endl;

 a_str.pop();
 a_str.pop();
 cout << "EXPECTED: 1 (TRUE)" << endl;
 cout << "Actual: " << a_str.empty() << endl;

// ****************************************

 cout << "\nTesting clear() & size()" << endl;
 cout << "------------------------" << endl;
 a_int.push(100);
 a_int.push(300);
 a_int.clear();
 cout << "EXPECTED: size == 0" << endl;
 cout << "ACTUAL: size == " << a_int.size() << endl;

 a_str.push("good");
 a_str.push("luck");
 a_str.clear();
 cout << "EXPECTED: size == 0" << endl;
 cout << "ACTUAL: size == " << a_str.size() << endl;

// ****************************************

 cout << "\nTesting const object test" << endl;
 cout << "-------------------------" << endl;
 const Queue<int> d_int;
 assert(0 == d_int.size());
 assert(d_int.empty());

 const Queue<string> d_str;
 assert(0 == d_str.size());
 assert(d_str.empty());

 return 0;
}
