// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "Queue.h"
#include "DynamicArray.h"

struct Customer
{
  char IDtag;
  int arrivalTime;
  int serviceEndTime;
  Customer()
  {
    IDtag = '!';
    arrivalTime = 0;
    serviceEndTime = 0;
  }
  Customer(char IDtag, int arrivalTime, int serviceEndTime)
  {
    this->IDtag = IDtag;
    this->arrivalTime = arrivalTime;
    this->serviceEndTime = serviceEndTime;
  }
};

int getRandomNumberOfArrivals(double);

int main()
{
  srand((unsigned)time(0));
  
  // identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  // read & input values from text file
  string data;
  string labels[5] = {"number of servers: ", "customer arrival rate: ",
    "maximum queue length: ", "minimum service time: ", "maximum service time: "};
  string values[6];
  
  ifstream fin("simulation.txt");
  if (!fin.good())
    cout << "Error: Unable to open file." << endl;
  
  for (int i = 0; i < 6; i++)
  {
    fin >> data;
    values[i] = data;
  }
  
  const unsigned int numServers = atoi(values[0].c_str());
  const double aveArrivalRate = atof(values[1].c_str());
  const unsigned int maxQueue = atoi(values[2].c_str());
  const unsigned int minServiceTime = atoi(values[3].c_str());
  const unsigned int maxServiceTime = atoi(values[4].c_str());
  const unsigned int customerStopTime = atoi(values[5].c_str());
  
  cout << left;
  cout << setw(27) << labels[0] << numServers << endl;
  cout << setw(27) << labels[1] << aveArrivalRate << " per minute, for " << customerStopTime << " minutes" << endl;
  cout << setw(27) << labels[2] << maxQueue << endl;
  cout << setw(27) << labels[3] << minServiceTime << " minutes" << endl;
  cout << setw(27) << labels[4] << maxServiceTime << " minutes" << endl << endl;
  
  fin.close();

  // declare/create/assign arrays & queues
  DynamicArray<Customer> nowServing;   // array of customers being served
  DynamicArray<bool> serverStatus;   // array of whether server is busy or free
  Queue<Customer> waitingLine;   // wait queue

  int enteredCustomers = 0;
  
  for (int i = 0; i < numServers; i++)
    serverStatus[i] = true;
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all services scheduled to complete at this clock time
    for (int i = 0; i < numServers; i++)
      if (!serverStatus[i])
        if (nowServing[i].serviceEndTime <= time)
          serverStatus[i] = true;

    // handle new arrivals -- can be turned away if wait queue is at maximum length
    if (time < customerStopTime)
    {
      int randArrivals = getRandomNumberOfArrivals(aveArrivalRate);
      for (int i = 0; i < randArrivals; i++)
      {
        if (waitingLine.size() < maxQueue)
        {
          waitingLine.push(Customer(65 + enteredCustomers++, time, 0));
          if (enteredCustomers >= 26)
            enteredCustomers = 0;
        }
      }
    }
        
    // for idle servers, move customer from wait queue and begin service for each server
    for (int i = 0; i < numServers; i++)
      if (serverStatus[i] && !waitingLine.empty())
      {
        serverStatus[i] = false;
        nowServing[i] = waitingLine.front();
        nowServing[i].serviceEndTime = time + rand() % (maxServiceTime - minServiceTime) + minServiceTime;
        waitingLine.pop();
      }
    
    // output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "server now serving wait queue" << endl;
    cout << "------ ----------- ----------" << endl;
    for (int i = 0; i < numServers; i++)
    {
      cout << setw(3) << right << i << setw(10);
      if (!serverStatus[i])
        cout << nowServing[i].IDtag;
      if (i == 0)
      {
        cout << setw(8);
        for (auto copyQ = waitingLine; !copyQ.empty(); copyQ.pop())
          cout << copyQ.front().IDtag;
      }
      cout << endl;
    }

  // if the end of the simulation has been reached, break
    bool allIdle = true;

    for (int i = 0; i < numServers; i++)
    {
      if (!serverStatus[i])
      {
        allIdle = false;
        break;
      }
    }
    
    if (allIdle && time >= customerStopTime)
    {
      cout << "Done!" << endl;
      return 0;
    }
    
    // pause for the user to press ENTER
    cout << "---------------------------" << endl;
    cout << "Press ENTER to continue...\n";
    string enter = "";
    getline(cin, enter);
    cout << "\n\n";
    
  }
  
  return 0;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand( ) / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}
