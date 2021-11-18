////  PriorityQueue.pop.cpp
//// Programmer: Elise Zur
//// Programmer's ID: 1851550
//
//#include <iostream>
//#include <string>
//#include <cassert>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//
//#include "PriorityQueue.h"
//using namespace std;
//
//int main()
//{
//  // identification
//  cout << "Programmer: Elise Zur\n";
//  cout << "Programmer's ID: 1851550\n";
//  cout << "File: " << __FILE__ << endl << endl;
//
//  srand(unsigned(time(0))); rand();
//
//  int n = 1000000;
//  const int reps = n / 100;
//
//  cout.setf(ios::fixed);
//  cout.precision(4);
//  double elapsedSecondsNorm = 0;
//  double expectedSeconds = 0;
//
//  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
//  {
//    PriorityQueue<int> time_array(n * 2);
//
//    for (int i = 0; i < n; i++)
//      time_array.push(i);
//
//    assert(time_array.size() == n);
//
//    PriorityQueue<int> test_array = time_array;
//
//    while(!test_array.empty())
//    {
//        int temp = test_array.top();
//        test_array.pop();
//        assert(temp >= test_array.top());
//    }
//
//    // start timer
//    clock_t startTime = clock();
//
//    for(int rep = 0; rep < reps; rep++)
//        time_array.pop();
//
//    // stop timer
//    clock_t endTime = clock();
//
//    assert(time_array.size() == n - reps);
//    test_array = time_array;
//
//    while(!test_array.empty())
//    {
//        int temp2 = test_array.top();
//        test_array.pop();
//        assert(temp2 >= test_array.top());
//    }
//
//    // compute timing results
//    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
//    double factor = pow(2.0, double(cycle));
//
//    if(cycle == 0)
//        elapsedSecondsNorm = elapsedSeconds;
//
//    expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
//
//    // output section
//    cout << expectedSeconds;
//    if (cycle == 0)
//      cout << " (expected O(log n))";
//    else
//      cout << " (expected: " << expectedSeconds << ')';
//    cout << " for n=" << n << endl;
//  }
//}
//
