// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef DynamicArray_h
#define DynamicArray_h

template <typename T>
class DynamicArray
{
  T* value; // T datatype CAP capacity
  int cap;
  T dummy = T();
  
public:
  DynamicArray(int=2); // constructor // default = 2
  DynamicArray(const DynamicArray<T>&); // copy constructor
  ~DynamicArray() {delete [] value;} // destructor
  DynamicArray<T>& operator=(const DynamicArray<T>&); // assignment operator
  int capacity() const {return cap;}
  void capacity(int); // setter
  T operator[] (int) const; // getter
  T& operator[] (int); // setter
  
};

// main constructor
template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
  dummy = T();
  this->cap = cap;
  value = new T[cap];
  for (int i = 0; i < cap; i++)
    value[i] = T();
}

// copy constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
  cap = original.cap;
  value = new T[cap];
  
  for (int i = 0; i < cap; i++)
    value[i] = original.value[i];
  dummy = original.dummy;
}

// assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
  if (this != &original)
  {
    // do what the deconstructor does
    delete [] value;
    
    // do what the constructor does
    cap = original.cap;
    value = new T[cap];
    for (int i = 0; i < cap; i++)
      value[i] = original.value[i];
    dummy = original.dummy;
  }
  return *this; // returns a self reference
}

// capacity setter
template <typename T>
void DynamicArray<T>::capacity(int cap)
{
  // allocate a new array with the new capacity
  T* temp = new T[cap];
  
  // get the lesser of the new and old capacities
  int limit = (cap < this->cap ? cap : this-> cap) ;
  
  // copy the contents
  for (int i = 0; i < limit; i++)
    temp[i] = value[i];
  
  // set added values to their defaults
  for (int i = limit; i < cap; i++)
    temp[i] = T();
  
  // deallocate original array
  delete [] value;
  
  // switch newly allocated array into the object
  value = temp;
  
  // update the capacity
  this->cap = cap;
}

// operator [] getter
template <typename T>
T DynamicArray<T>::operator[](int index) const // getter
{
  if (index < 0 || index >= cap)
    return dummy;
  return value[index];
}

// operator [] setter
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
//  dummy = T();
  if (index < 0) return dummy;
  if (index >= cap) capacity(2 * index);
  return value[index];
}

#endif /* DynamicArray_h */
