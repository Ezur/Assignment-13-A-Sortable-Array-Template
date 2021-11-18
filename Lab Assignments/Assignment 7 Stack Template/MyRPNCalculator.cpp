// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "Stack.h"

int main()
{
  // identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;

  double result = 0;
  string input = "";
  Stack<double> mainStack;
  Stack<double> secondStack;

  while(true)
  {
    cout << "Enter: ";
    if (!mainStack.empty())
    {
      // display stack
      secondStack = mainStack;
      while (!secondStack.empty())
      {
        cout << secondStack.peek() << " ";
        secondStack.pop();
      }
    }
      cin >> input;

    if (input == "Q" || input == "q")
      break;

    if ((input == "+" || input == "*" || input == "-" || input == "/") && mainStack.size() >= 2)
    {
      secondStack = mainStack;

      double num1 = secondStack.peek();
      secondStack.pop();
      double num2 = secondStack.peek();
      secondStack.pop();

      if (input == "+")
        result = num1 + num2;
      else if (input == "*")
        result = num1 * num2;
      else if (input == "-")
        result = num2 - num1;
      else if(input == "/")
        result = num2 / num1;

      mainStack.pop();
      mainStack.pop();
      mainStack.push(result);
    }
    else
      mainStack.push(atoi(input.c_str()));
  }
}
