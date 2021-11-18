// Programmer: Elise Zur
// Programmer's ID: 1851550

#ifndef Queue_h
#define Queue_h

template <typename V>
class Queue
{
  struct node
  {
    V value;
    node* next;
  };
  
  int siz;
  node* firstNode; //head pointer
  node* lastNode; // tail pointer
  V dummy = V();
  
public:
  Queue(); // main constructor
  Queue(const Queue<V>&); // copy constructor
  ~Queue();
  Queue<V>& operator=(const Queue<V>&);
  void push(const V&);
  const V& front() const; // return an immutable ref to oldest node
  const V& back() const; // return an immutable ref to newest node
  void pop();
  int size() const { return siz; }
  bool empty() const { return siz == 0; }
  void clear();
};

// main constructor
template <typename V>
Queue<V>::Queue()
{
  firstNode = nullptr;
  lastNode = nullptr;
  siz = 0;
  dummy = V();
}

// copy constructor
template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = nullptr;
  lastNode = nullptr;
  siz = original.siz;
  
  for(node* ptr = original.firstNode; ptr != nullptr; ptr = ptr->next)
  {
    node* temp = new node;
    temp->value = ptr->value;
    temp->next = nullptr;
    if (lastNode != nullptr)
      lastNode->next = temp;
    else
      firstNode = temp;
    lastNode = temp;
  }
}

// destructor
template <typename V>
Queue<V>::~Queue()
{
  while(firstNode != nullptr)
  {
    node* ptr = firstNode;
    firstNode = firstNode->next;
    delete ptr;
  }
}

// assignment operator
template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original)
{
  if(this != &original)
  {
    while (firstNode != nullptr)
    {
      node* ptr = firstNode;
      firstNode = firstNode->next;
      delete ptr;
    }
    
    lastNode = nullptr;

    for(node* ptr = original.firstNode; ptr != nullptr; ptr = ptr->next)
    {
      node* temp = new node;
      temp->value = ptr->value;
      temp->next = nullptr;
      if(lastNode != nullptr)
        lastNode->next = temp;
      else
        firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

// push
template <typename V>
void Queue<V>::push(const V& value)
{
  node* temp = new node;
  temp->value = value;
  temp->next = 0;
  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  ++siz;
}

// front
template <typename V>
const V& Queue<V>::front() const
{
  if (firstNode == nullptr)
    return dummy;
  return firstNode->value;
}

// back
template <typename V>
const V& Queue<V>::back() const
{
  if (lastNode == nullptr)
    return dummy;
  return lastNode->value;
}

// pop
template <typename V>
void Queue<V>::pop()
{
  if (firstNode)
  {
    node* ptr = firstNode;
    firstNode = firstNode->next;
    delete ptr;
    --siz;
  }
  
  if (siz == 0) lastNode = nullptr;
}

// clear
template <typename V>
void Queue<V>::clear( )
{
  while (firstNode != nullptr)
  {
    node* ptr = firstNode;
    firstNode = firstNode->next;
    delete ptr;
    --siz;
  }
  if (siz == 0)
    lastNode = nullptr;
}

#endif /* Queue_h */
