// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef StaticArray_h
#define StaticArray_h

template <typename T, int CAP>
class StaticArray
{
  T value[CAP]; // T datatype CAP capacity
  T dummy;
  
public:
  StaticArray(); // main constructor
  int capacity() const {return CAP;}
  T operator[](int) const; // getter
  T& operator[](int); // setter
};

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray() // main constructor
{
  dummy = T();
  for (int index = 0; index < CAP; index++)
    value[index] = T();
}

template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const // getter
{
  if (index < 0 || index >= CAP)
    return dummy;
  return value[index];
}

template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index) // setter
{
//  dummy = T();
  if (index < 0 || index >= CAP)
    return dummy;
  return value[index];
}

#endif /* StaticArray_h */
