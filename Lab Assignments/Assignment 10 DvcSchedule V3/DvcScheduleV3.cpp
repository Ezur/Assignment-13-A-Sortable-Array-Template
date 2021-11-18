// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "AssociativeArray.h"

int main()
{
  // identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;

  // open input file & check access
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.is_open())
  {
    cout << "Error. Unable to open the file." << endl;
    return 1;
  }
  
  AssociativeArray<string, AssociativeArray<string, bool> > seen;
  AssociativeArray<string, AssociativeArray<string, int> > courseCount;

  int duplicates = 0;
  int total = 0;
  
  while (fin.good())
  {
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines
    
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    total++;
    if (seen[term].containsKey(section))
    {
      duplicates++;
      continue;
    }
    else
    {
      seen[term][section] = true;
      courseCount[subjectCode][course]++;
    }
  }
  fin.close();
  
  cout << "The number of duplicates is: " << duplicates << '\n';
  cout << "The total is: " << total << '\n';

  AssociativeArray<int, string> courseArray;
  Queue<string> courseQueue = courseCount.keys();
  
  // copy courseQueue to courseArray
  for(int i = 0; !courseQueue.empty(); i++)
  {
    courseArray[i] = courseQueue.front();
    courseQueue.pop();
  }

  // sort courseArray
  for(int i = 0; i < courseArray.size(); i++)
    for(int j = i + 1; j < courseArray.size(); j++)
      if(courseArray[i] > courseArray[j])
        swap(courseArray[i], courseArray[j]);

  for(int i = 0; i < courseCount.size(); i++)
  {
    AssociativeArray<int, string> subjectArray;
    Queue<string> subjectQueue = courseCount[courseArray[i]].keys();
    
    // copy subjectQueue to subjectArray
    for(int j = 0; !subjectQueue.empty(); j++)
    {
      subjectArray[j] = subjectQueue.front();
      subjectQueue.pop();
    }

    // sort courseArray
    for(int k = 0; k < courseCount[courseArray[i]].size(); k++)
      for(int m = k + 1; m < courseCount[courseArray[i]].size(); m++)
        if(courseArray[k] > courseArray[m])
          swap(courseArray[k], courseArray[m]);

    AssociativeArray<int, string> outputs;

    for(int n = 0; n < courseCount[courseArray[i]].size(); n++)
    {
      string s = "  " + subjectArray[n] + ", " + to_string(courseCount[courseArray[i]][subjectArray[n]]) + " section(s)";
      outputs[n] = s;
    }

    if(courseArray[i] != "" && (courseCount[courseArray[i]].size()) > 0)
      cout << courseArray[i] << ", " << courseCount[courseArray[i]].size() << " course(s)" << endl;
    
    for(int p = 0; p < outputs.size(); p++)
      cout << outputs[p] << endl;

  }

    
}



