// PriorityQueueTest.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
#include <ctime>
//#include <conio.h>
#include <algorithm>
#include <cassert>

#include "PriorityQueue.h"

using namespace std;

int main()
{
   int bound = 500;
   srand((unsigned int)time(NULL));
   rand();

   PriorityQueue<int> pq;

   for (int i = 0; i < bound; i++)
   {
       int j = rand();
       pq.push(j);
   }

 cout << "Test 1" << '\n';

   int prev = -1;

   while (!pq.empty())
   {
       if (prev > 0)
           assert(prev >= pq.top());
       cout << pq.top() << '\n';
       prev = pq.top();
       pq.pop();
   }

 cout << "Hit any key to continue ";
 cin.get();

 cout << "Test 2" << '\n';

 for (int i = 0; i < bound; i++)
   {
       pq.push(i);
   }

 prev = -1;

   while (!pq.empty())
   {
       if (prev > 0)
           assert(prev >= pq.top());
       cout << pq.top() << '\n';
       prev = pq.top();
       pq.pop();
   }
}

