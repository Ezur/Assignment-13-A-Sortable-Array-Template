// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include "DynamicArray.h"

int main2()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;

  int counter = 0;
  string buffer;
  float user_index, user_value;

  DynamicArray<double> array;
  DynamicArray<bool> array_flags;

  while(true)
  {
    // prompts user for input
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buffer; // index
    user_index = atoi(buffer.c_str());

    // user enters "Q" / "q" to end program
    if (buffer == "Q" or buffer == "q")
      break;

    cin >> buffer; // value
    user_value = atof(buffer.c_str());

    // modifies the array w/ new values
    array[user_index] = user_value; // sets the user-specified index with value
    array_flags[user_index] = true;

  }

  // counts the # of new values
  for (int i = 0; i < array_flags.capacity(); i++)
    if (array_flags[i] != false)
      counter++;

  cout << "\n\tYou stored this many values: " << counter << endl;
  cout << "\tThe index-value pairs are:";

  // outputs each index-value pair
  for (int i = 0; i < array_flags.capacity(); i++)
    if (array_flags[i] == true)
      cout << "\n\t\t" << i << " => " << array[i];
  cout << endl << endl;

  while(true)
  {
    // prompts user to search for an index
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> buffer;
    user_index = atoi(buffer.c_str());

    // user enters "Q" / "q" to end program
    if (buffer == "Q" or buffer == "q")
      break;

    // checks array for changed index
    if (array_flags[user_index] == 0)
      cout << "Sorry, but there is no value stored at index " << user_index << endl << endl;
    else
      cout << "Found it -- the value stored at " << user_index << " is " << array[user_index] << endl << endl;
  }
  return 0;
}
