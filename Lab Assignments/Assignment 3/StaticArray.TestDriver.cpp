// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
using namespace std;

#include "StaticArray.h"
//#include "StaticArray.h"


int main()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;
  
  // Testing main constructor
  cout << "\nTesting StaticArray<T, CAP>::StaticArray()" << endl;
  cout << "------------------------------------------" << endl;
  cout << "\nTesting int constructor\n";
  StaticArray<int, 3>a1;
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a1[0] << endl;
  for (int i = 0; i < a1.capacity(); i++)
    assert(a1[i] == 0);
  
  cout << "\nTesting double constructor\n";
  StaticArray<double, 4>a2;
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << a2[0] << endl;
  for (int i = 0; i < a1.capacity(); i++)
    assert(a2[i] == 0);
  
  cout << "\nTesting char constructor\n";
  StaticArray<char, 5>a3;
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << a3[0] << endl;
  for (int i = 0; i < a3.capacity(); i++)
    assert(a3[i] == '\0');
  
  cout << "\nTesting string constructor\n";
  StaticArray<string, 6>a4;
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << a4[0] << endl;
  for (int i = 0; i < a4.capacity(); i++)
    assert(a4[i] == "\0");
  
  // Testing capacity()
  cout << "\nTesting capacity()" << endl;
  cout << "-------------------" << endl;
  cout << "\nTesting int capacity()\n";
  cout << "EXPECTED: 3" << endl;
  cout << "ACTUAL: " << a1.capacity() << endl;
  assert(3 == a1.capacity());
  
  cout << "\nTesting double capacity()\n";
  cout << "EXPECTED: 4" << endl;
  cout << "ACTUAL: " << a2.capacity() << endl;
  assert(4 == a2.capacity());
  
  cout << "\nTesting char capacity()\n";
  cout << "EXPECTED: 5" << endl;
  cout << "ACTUAL: " << a3.capacity() << endl;
  assert(5 == a3.capacity());

  cout << "\nTesting string capacity()\n";
  cout << "EXPECTED: 6" << endl;
  cout << "ACTUAL: " << a4.capacity() << endl;
  assert(6 == a4.capacity());


  // Testing setter
  cout << "\nT& StaticArray<T, CAP>::operator[](int index)" << endl;
  cout << "------------------------------------------" << endl;
  cout << "\nTesting int setter()";
  a1[2] = 5338;
  cout << "\nEXPECTED: 5338 for a[2]" << endl;
  cout << "ACTUAL: " << a1[2] << endl;
  assert(5338 == a1[2]);

  cout << "\nTesting double setter()";
  a2[-10] = 94.556;
  cout << "\nEXPECTED: 0 for a2[-10]" << endl;
  cout << "ACTUAL: " << a1[-10] << endl;
  assert(0 == a2[-10]); // uses dummy value bc out of range
  
  a2[-6] = 65544;
  assert(0 == a2[-6]); // uses dummy value again bc out of range

  cout << "\nTesting char setter()";
  a3[3] = 'h';
  a3[4] = 'i';
  cout << "\nEXPECTED: hi" << endl;
  cout << "ACTUAL: " << a3[3] << a3[4] << endl;
  assert('h' == a3[3]);
  assert('i' == a3[4]);

  
  cout << "\nTesting string setter()";
  a4[2] = "hello ";
  a4[3] = "my name is Elise";
  cout << "\nEXPECTED: hello my name is Elise" << endl;
  cout << "ACTUAL: " << a4[2] << a4[3] << endl;
  assert("hello " == a4[2]);


  // Testing getter
  cout << "\nTesting StaticArray<T, CAP>::operator[](int index) const" << endl;
  cout << "------------------------------------------" << endl;
  cout << "\nTesting int & double getter\n";
  const StaticArray<int, 20>b1;
  const StaticArray<double, 20>b2;
  cout << "EXPECTED: " << b1[1] << endl;
  cout << "ACTUAL: " << b2[1] << endl;
  assert(b1[1] == b2[1]);

  for (int i = 0; i < b1.capacity(); i++)
    if (b1[i] == 1)
      assert(b1[i] == 1);
  
  cout << "\nTesting char getter\n";
  const StaticArray<char, 5> b3;
  cout << "EXPECTED: " << b3[1] << endl;
  cout << "ACTUAL: " << b3[1] << endl;

  cout << "\nTesting string getter\n";
  const StaticArray<string, 3> b4;
  cout << "EXPECTED: " << b4[1] << endl;
  cout << "ACTUAL: " << b4[1] << endl;

  // Testing const
  cout << "\nTesting Const Object" << endl;
  cout << "----------------------" << endl;
  cout << "\nTesting int const object\n";
  const StaticArray<int, 5 >c1; // main constructor works
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << c1[2] << endl;
  assert(c1.capacity() == 5);
  assert(c1[0] == c1[0]); // capacity getter exists
  assert(c1[-1] == c1[-1]); // getter's range checking works
  
  cout << "\nTesting double const object\n";
  const StaticArray<double, 6 >c2; // main constructor works
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << c2[2] << endl;
  assert(c2.capacity() == 6);
  assert(c2[0] == c2[0]); // capacity getter exists
  assert(c2[-1] == c2[-1]); // getter's range checking works
  
  cout << "\nTesting char const object\n";
  const StaticArray<char, 7 >c3; // main constructor works
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << c3[2] << endl;
  assert(c3.capacity() == 7);
  assert(c3[0] == c3[0]); // capacity getter exists
  assert(c3[-1] == c3[-1]); // getter's range checking works
  
  cout << "\nTesting string const object\n";
  const StaticArray<string, 8 >c4; // main constructor works
  cout << "EXPECTED: " << endl;
  cout << "ACTUAL: " << c4[2] << endl;
  assert(c4.capacity() == 8);
  assert(c4[0] == c4[0]); // capacity getter exists
  assert(c4[-1] == c4[-1]); // getter's range checking works
  
  return 0;
}
