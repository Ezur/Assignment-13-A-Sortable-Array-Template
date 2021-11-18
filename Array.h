// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef Array_h
#define Array_h

class Array
{
  int values[100]; // initialize to 0
  int dummy;
  
public:
  Array(); // main constructor
  int capacity() const; // getter
  int operator[](int) const; // getter version
  int& operator[](int); // setter version
};

#endif /* Array_h */
