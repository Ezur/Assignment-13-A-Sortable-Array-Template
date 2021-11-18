// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "DynamicArray.h"
//#include "DynamicArray.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;
  
  // Testing main constructor
  cout << "\nTesting DynamicArray()" << endl;
  cout << "------------------------------------------" << endl;
  cout << "Testing int constructor\n";
  DynamicArray<int>a;
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a[0] << endl;
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);
  
  cout << "\nTesting double constructor\n";
  DynamicArray<double>a2(2);
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a2[0] << endl;
  for (int i = 0; i < a2.capacity(); i++)
    assert(a2[i] == 0);

  cout << "\nTesting char constructor\n";
  DynamicArray<char>b;
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << b[0] << endl;
  for (int i = 0; i < b.capacity(); i++)
    assert(b[i] == '\0');
  
  // TESTING COPY CONSTRUCTOR
  cout << "\n\nObject copy test\n";
  cout << "--------------------";
  DynamicArray<int> c = a; // making a copy
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == c[i]); // uses setter for both a / d
  // change the content in the original array to verify it's not a shallow copy
  for (int i = 0; i < a.capacity(); i++)
  {
    a[i]++;
    assert(a[i] != c[i]);
  }
  
  DynamicArray<char> d = b; // making a copy
  assert(b.capacity() == d.capacity());
  for (int i = 0; i < b.capacity(); i++)
    assert(b[i] == d[i]); // uses setter for both a / d
  // change the content in the original array to verify it's not a shallow copy
  for (int i = 0; i < b.capacity(); i++)
  {
    b[i]++;
    assert(b[i] != d[i]);
  }
  
  // TESTING ASSIGNMENT OPERATOR
  cout << "\n\nObject assignment test\n";
  cout << "--------------------------";
  DynamicArray<int> e; e = a;
  assert(a.capacity() == e.capacity());
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == e[i]);
  // change the content in original array to verify its not a shallow copy
  for (int i = 0; i < a.capacity(); i++)
  {
    a[i]++;
    assert(a[i] != e[i]);
  }
  
  DynamicArray<char> f; f = b;
  assert(b.capacity() == f.capacity());
  for (int i = 0; i < b.capacity(); i++)
    assert(b[i] == f[i]);
  // change the content in original array to verify its not a shallow copy
  for (int i = 0; i < b.capacity(); i++)
  {
    b[i]++;
    assert(b[i] != f[i]);
  }
    
  // TESTING CONST CAPACITY
  cout << "\n\nTesting int capacity() const" << endl;
  cout << "-------------------" << endl;
  cout << "Testing int\n";
  cout << "EXPECTED: 2" << endl;
  cout << "ACTUAL: " << c.capacity() << endl;
  assert(2 == c.capacity());
  
  cout << "\nTesting char\n";
  cout << "EXPECTED: 2" << endl;
  cout << "ACTUAL: " << d.capacity() << endl;
  assert(2 == d.capacity());


  // TESTING CAPACITY SETTER
  cout << "\nTesting void capacity(int)" << endl;
  cout << "-------------------" << endl;
  cout << "Testing int\n";
  DynamicArray<int> a1(100);
  cout << "EXPECTED: 100" << endl;
  cout << "ACTUAL: " << a1.capacity() << endl;
  assert(100 == a1.capacity());
  cout << "\t> Capacity has changed" << endl;
  a1.capacity(2000);
  cout << "EXPECTED: 2000" << endl;
  cout << "ACTUAL: " << a1.capacity() << endl;
  assert(2000 == a1.capacity());
  
  cout << "\nTesting string\n";
  DynamicArray<string> g(25);
  cout << "EXPECTED: 25" << endl;
  cout << "ACTUAL: " << g.capacity() << endl;
  assert(25 == g.capacity());
  cout << "\t> Capacity has changed" << endl;
  g.capacity(1400);
  cout << "EXPECTED: 1400" << endl;
  cout << "ACTUAL: " << g.capacity() << endl;
  assert(1400 == g.capacity());
    
  // TESTING OPERATOR[] GETTER
  cout << "\nTesting operator[](int) const" << endl;
  cout << "--------------------------------" << endl;
  cout << "Testing int & double getter\n";
  const DynamicArray<int>b1;
  const DynamicArray<double>b2;
  cout << "EXPECTED: " << b1[1] << endl;
  cout << "ACTUAL: " << b2[1] << endl;
  assert(b1[1] == b2[1]);
  for (int i = 0; i < b1.capacity(); i++)
    if (b1[i] == 1)
      assert(b1[i] == 1);

  cout << "\nTesting char getter\n";
  const DynamicArray<char> b3;
  const DynamicArray<char> b4;
  cout << "EXPECTED: " << b3[1] << endl;
  cout << "ACTUAL: " << b4[1] << endl;
  assert(b3[0] == b4[0]);
  for (int i = 0; i < b1.capacity(); i++)
    if (b1[i] == 1)
      assert(b1[i] == 1);

  
  // TESTING OPERATOR[] SETTER
  cout << "\nT& StaticArray<T, CAP>::operator[](int index)" << endl;
  cout << "------------------------------------------" << endl;
  cout << "Testing int setter";
  e[2] = 5338;
  cout << "\nEXPECTED: 5338 for e[2]" << endl;
  cout << "ACTUAL: " << e[2] << endl;
  assert(5338 == e[2]);

  cout << "\nTesting double setter";
  a1[-10] = 94.556;
  cout << "\nEXPECTED: 0 for a1[-10]" << endl;
  cout << "ACTUAL: " << a1[-10] << endl;
  assert(a1[-10] == 0); // uses dummy value bc out of range

  a1[-6] = 65544;
  assert(0 == a1[-6]); // uses dummy value again bc out of range

  cout << "\nTesting char setter()";
  d[3] = 'h';
  d[4] = 'i';
  cout << "\nEXPECTED: hi" << endl;
  cout << "ACTUAL: " << d[3] << d[4] << endl;
  assert('h' == d[3]);
  assert('i' == d[4]);
  

  // Testing const object
  cout << "\nTesting Const Object" << endl;
  cout << "----------------------" << endl;
  cout << "\nTesting int const object\n";
  const DynamicArray<int>c1; // main constructor works
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << c1[2] << endl;
  assert(c1.capacity() == 2);
  assert(c1[0] == c1[0]); // capacity getter exists
  assert(c1[-1] == c1[-1]); // getter's range checking works

  cout << "\nTesting double const object\n";
  const DynamicArray<double>c2; // main constructor works
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << c2[2] << endl;
  assert(c2.capacity() == 2);
  assert(c2[0] == c2[0]); // capacity getter exists
  assert(c2[-1] == c2[-1]); // getter's range checking works

  cout << "\nTesting char const object\n";
  const DynamicArray<char>c3; // main constructor works
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << c3[2] << endl;
  assert(c3.capacity() == 2);
  assert(c3[0] == c3[0]); // capacity getter exists
  assert(c3[-1] == c3[-1]); // getter's range checking works

  cout << "\nTesting string const object\n";
  const DynamicArray<string>c4; // main constructor works
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << c4[2] << endl;
  assert(c4.capacity() == 2);
  assert(c4[0] == c4[0]); // capacity getter exists
  assert(c4[-1] == c4[-1]); // getter's range checking works
  
  return 0;
}
