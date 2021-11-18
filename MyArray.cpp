// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
using namespace std;

#include "Array.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;

  int user_index, user_value;
  string buffer;
  int counter = 0;

  Array array;
  Array array_flags; // tracks when an index is changed

  while (true)
  {
    // prompts user for input
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buffer; // index
    user_index = atoi(buffer.c_str());

    // user enters "Q" / "q" to end program
    if (buffer == "Q" or buffer == "q")
      break;

    cin >> buffer; // value
    user_value = atoi(buffer.c_str());

    // modifies the array w/ new values
    array[user_index] = user_value; // sets the user-specified index with value
    array_flags[user_index] = 1;

  }
  // counts the # of new values
  for (int i = 0; i < array_flags.capacity(); i++)
    if (array_flags[i] != 0)
      counter++;

  cout << "> You stored this many values: " << counter << endl;
  cout << "\tThe index-value pairs are:\n";

  // outputs each index-value pair
  for (int i = 0; i < array_flags.capacity(); i++)
    if (array_flags[i] == 1)
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
      cout << "I didn't find it" << endl << endl;
    else
      cout << "Found it -- the value stored at " << user_index << " is " << array[user_index] << endl << endl;
  }

}
