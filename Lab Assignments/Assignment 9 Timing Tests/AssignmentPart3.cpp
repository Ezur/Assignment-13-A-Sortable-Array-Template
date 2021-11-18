// Programmer: Elise Zur
// Programmer's ID: 1851550
// Nested For-Loop Sorting

#include <iostream>
#include <string>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock( ), clock_t, time, and CLOCKS_PER_SEC

#include "DynamicArray.h"

int main()
{
  // identification
  cout << "Programmer: Elise Zåur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;

  srand(unsigned(time(0)));
  rand();

  // programmer customizations go here
  int n = 2000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // problem setup goes here -- create a data structure of size n
    DynamicArray<double> array(n);
    
    // assert that n is the size of the data structure if applicable
    assert(array.capacity( ) == n); // or something like that...

    // fill array with random values
    for (int i = 0; i < n; i++)
      array[i] = rand();
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
   
    // do something where n is the "size" of the problem
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (array[j] < array[i])
          swap(array[i], array[j]);
  
    // stop timer
    clock_t endTime = clock( );
    
    // validation block -- assure that process worked if applicable
    // verify each number in the array is greater or equal to the
    // number before it, starting with the 2nd number.
    for (int i = 1; i < n; i++) assert (array[i - 1] <= array[i]);
    
    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
  cout << endl;
}
