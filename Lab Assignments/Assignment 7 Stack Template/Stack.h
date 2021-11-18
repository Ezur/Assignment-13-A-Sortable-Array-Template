// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef Stack_h
#define Stack_h

#include <iostream>

template <typename V>
class Stack
{
  V* values;
  int cap; // actual memory allocated
  int siz; // track memory used
  void capacity(int);
  
public:
  Stack(int = 2); // constructor
  Stack(const Stack<V>&); // copy constructor
  ~Stack() { delete [] values; } // destructor
  Stack<V>& operator=(const Stack<V>&); // assignment operator
  void push(const V&);
  const V& peek() const;
  void pop() { if (siz > 0) --siz; }
  int size() const { return siz; }
  bool empty() const;
  void clear() { siz = 0; }
  
};

// main constructor
template <typename V>
Stack<V>::Stack(int cap)
{
  siz = 0;
  this->cap = cap;
  values = new V[cap];
}

// copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  siz = original.siz;
  cap = original.cap;
  values = new V[cap];
  
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
  
}

// assignment operator
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    delete [] values;
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this; // returns a self reference
}

// push()
template <typename V>
void Stack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap);
  values[siz] = value;
  ++siz;
}

// peek()
template <typename V>
const V& Stack<V>::peek() const
{
  if (siz < 0)
    return values[0];
  else
    return values[siz - 1];
}

template <typename V>
bool Stack<V>::empty() const
{
  if (siz == 0)
    return true;
  else
    return false;
}

template <typename V>
void Stack<V>::capacity(int updatedCap)
{
  V* temp = new V[updatedCap];
  int limit = min(updatedCap, cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  for (int i = limit; i < cap; i++)
    temp[i] = V();
  delete [] values;
  values = temp;
  cap = updatedCap;
}

#endif /* Stack_h */
