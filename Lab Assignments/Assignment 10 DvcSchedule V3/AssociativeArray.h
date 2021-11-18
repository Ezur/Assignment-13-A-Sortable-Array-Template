// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef AssociativeArray_h
#define AssociativeArray_h

#include "Queue.h"

template <typename K, typename V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V value;
    Node* next;
  };
  
  Node* firstNode;
  V dummy = V();
  int siz;
  
public:
  AssociativeArray() { firstNode = 0; dummy = V{}; siz = 0; }
  AssociativeArray(const AssociativeArray<K, V> &);
  AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);
  ~AssociativeArray();
  V operator[](const K&) const; // getter
  V& operator[](const K&); // setter
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  Queue<K> keys() const;
  int size() const { return siz; }
  void clear();
};

// copy constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V> & original)
{
  firstNode = nullptr;
  Node* lastNode = nullptr;
  siz = original.siz;
  
  for (Node* ptr = original.firstNode; ptr != nullptr; ptr = ptr->next)
  {
    Node* temp = new Node;
    temp->value = ptr->value;
    temp->key = ptr->key;
    temp->next = nullptr;
    
    if(lastNode != nullptr)
      lastNode->next = temp;
    else
      firstNode = temp;
    lastNode = temp;
  }
}

// assignment operator
template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode != nullptr)
    {
      Node* ptr = firstNode;
      firstNode = firstNode->next;
      firstNode = ptr;
      delete firstNode;
    }

    // build new AssociativeArray
    Node* lastNode = 0;
    for (Node* ptr = original.firstNode; ptr != nullptr; ptr = ptr->next)
    {
      Node* temp = new Node;
      temp->value = ptr->value;
      temp->key = ptr->key;
      temp->next = nullptr;
      
      if (lastNode != nullptr)
        lastNode->next = temp;
      else
        firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
    return *this;
}

//destructor
template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
  while(firstNode != nullptr)
  {
    Node* ptr = firstNode;
    firstNode = firstNode->next;
    delete ptr;
  }
}

// [] getter
template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const
{
  for (Node* ptr = firstNode; ptr; ptr = ptr->next)
    if (ptr->key == key)
      return ptr->value;
  
  V dummy = V();
  return dummy;
}

// [] setter
template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key) // setter
{
  for (Node* ptr = firstNode; ptr; ptr = ptr->next)
  {
    if (ptr->key == key)
      return ptr->value;
  }
  ++siz;
  Node* temp = new Node;
  temp->key = key;
  temp->value = V();
  temp->next = firstNode;
  firstNode = temp;
  return firstNode->value;
}

// contains key
template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
  for (Node* ptr = firstNode; ptr; ptr = ptr->next)
    if (ptr->key == key)
      return true;
  return false;
}

// delete key
template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
  // find the matching node
  Node* ptr, *prev;
  for (ptr = firstNode, prev = 0; ptr; prev = ptr, ptr = ptr->next)
    if (ptr->key == key)
      break;
  
  // if found
  if (ptr)
  {
    if (prev)
      prev->next = ptr->next; // skips over the node at p
    else
      firstNode = ptr->next; // there's a new head, possibly zero
    
    --siz;
    delete ptr; // done with this node
  }
}

// keys
template <typename K, typename V>
Queue<K> AssociativeArray<K, V>::keys()const
{
  Queue<K> retQ;
  Node* ptr;
  
  for (ptr = firstNode; ptr; ptr = ptr->next)
    retQ.push(ptr->key);

  return retQ;
}

// clear
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
  while (firstNode != nullptr)
  {
    Node* ptr = firstNode;
    firstNode = firstNode->next;
    delete ptr;
    --siz;
  }
}

#endif /* AssociativeArray_h */
