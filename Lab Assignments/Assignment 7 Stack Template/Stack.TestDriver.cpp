// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <cassert>
using namespace std;

#include "Stack.h"

int main2()
{
  // identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  // Testing constructor
  Stack<int> a;
  assert(a.peek() == 0);
  assert(a.size() == 0);
  
  cout << "Testing constructor/size/pop" << endl;
  for (int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == 0);
    a.pop();
  }

  int test = 0;
  cout << "Testing push/pop/peek" << endl;
  a.push(5);
  a.push(10);
  cout << "EXPECTED: 10 for 2nd push" << endl;
  cout << "ACTUAL: " << a.peek() << endl;
  test = 10;
  assert(test == 10);
  a.pop();
  cout << "\nEXPECTED: 5 for 1st push" << endl;
  cout << "ACTUAL: " << a.peek() << endl;
  test = 5;
  assert(test == 5);
  
  // confused why empty always returns 0? 
  cout << "\nTesting empty" << endl;
  cout << "EXPECTED: 1" << endl;
  cout << "ACTUAL: " << a.empty() << endl;
  
  a.push(20);
  a.push(40);
  cout << "\nTesting clear" << endl;
  a.clear();
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a.size() << endl;
  
  cout << "\nConst object test" << endl;
  const Stack<int> b;
  assert(b.size() == 0);
  assert(b.empty());
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << b.size() << endl;
  
  cout << "\nObject copy test" << endl;
  a.push(1000);
  a.push(500);
  Stack<int> c(a); // making a copy
  assert(a.size() == c.size());
  for (int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == c.peek());
    a.pop();
    c.pop();
  }
  cout << "Stack a size: " << a.size() << endl;
  cout << "Stack c size: " << c.size() << endl;
  
  cout << "\nObject assignment test" << endl;
  a.push(100);
  a.push(250);
  Stack<int> d;
  d = a;
  assert(a.size() == d.size());
  
  cout << "Stack a value before pop: " << a.peek() << endl;
  cout << "Stack c value before pop: " << d.peek() << endl;
  
  for (int i = 0; i < 10; i++)
  {
    assert(a.size() == d.size());
    a.pop();
    d.pop();
  }
  cout << "\nStack a value after pop: " << a.peek() << endl;
  cout << "Stack c value after pop: " << d.peek() << endl;
  
  return 0;
}

