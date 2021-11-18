// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
using namespace std;

#include "Array.h"

Array::Array() // main constructor
{
  for (int index = 0; index < 100; index++)
    values[index] = int();
}

int Array::capacity() const { // getter to return capacity
  return 100;}

int Array::operator[](int index) const // getter
{
  if (index < 0 || index >= capacity())
    return 0;
  return values[index];
}

int& Array::operator[](int index) // setter
{
  if (index < 0 || index >= capacity())
    return dummy;
  return values[index];
}
