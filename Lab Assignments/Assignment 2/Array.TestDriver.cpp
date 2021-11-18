// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
using namespace std;

#include <cassert>
#include "Array.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;
  
  assert(true);
  
  // Array::Array
  Array a;
  cout << "\nTesting Array::Array\n";
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a[0] << endl;
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);

  // Array::capacity
  cout << "\nTesting Array::capacity" << endl;
  cout << "EXPECTED: 100" << endl;
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());
  
  // Array::operator[] setter
  cout << "\nTesting Array::operator[] setter";
  a[5] = 12323;
  a[9] = 223232323;
  cout << "\nEXPECTED: 12323 for a[5]";
  cout << "\nACTUAL: " << a[5] << endl;
  assert(12323 == a[5]);
  
  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  
  assert(12323 == a[5]);
  assert(223232323 == a[9]);
  assert(123123 == a[-6]);
  
  // Array::operator[] getter
  cout << "\nTesting Array::operator[] getter\n";
  const Array e;
  const Array d = e;
  cout << "EXPECTED: " << d[1] << endl;
  cout << "ACTUAL: " << e[1] << endl;
  for (int i = 0; i < 100; i++)
    assert(d[i] == e[i]);
  
  for (int i = 0; i < 100; i++)
    if (e[i] == 1)
      assert(e[i] == 1);
  
  //const object
  cout << "\nTesting Const object\n";
  const Array c; // if this compiles, Array::Array main constructor exists
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << c[1] << endl;
  assert(c.capacity() == 100); // if this compiles, Array::capacity is a getter
  assert(c[0] == c[0]); // if this compiles, Array::operator[] getter exists
  assert(c[-1] == c[-1]); // tests the getter's range checking
  
  return 0;
}
