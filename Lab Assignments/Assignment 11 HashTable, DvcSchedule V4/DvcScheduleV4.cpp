// Programmer: Elise Zur
// Programmer's ID: 1851550

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cmath>

#include "HashTable.h"
#include "DynamicArray.h"

int hashCode(const string&);

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
  
  // declarations
  HashTable<string, bool, 90000> seen(hashCode);
  HashTable<string, int, 200> countSubjects(hashCode);
  int duplicates = 0;
  int total = 0;
  int lines = 0;


  clock_t startTime = clock();

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
    if (seen.containsKey(term + "," + section))
    {
      duplicates++;
      continue;
    }
    else
    {
      seen[term + "," + section] = true;
      countSubjects[subjectCode]++;
    }
  }
  fin.close();
  clock_t endTime = clock();
  
  // compute timing results
  double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  
//  unique = (total - duplicates);
//  cout << "\n\nUnique number of courses: " << unique << endl;
  
  Queue<string> output_q = countSubjects.keys();
  DynamicArray<string> output_a;
  
  // copy output_queue into output_array
  for(int i = 0; i < countSubjects.size(); i++)
  {
    output_a[i] = output_q.front();
    output_q.pop();
  }
  
  for(int i = 0; i < countSubjects.size(); i++)
  {
    string nextSubject = output_a[i];
    int num = i - 1;
    while(num >= 0 && nextSubject < output_a[num])
    {
      output_a[num + 1] = output_a[num];
      output_a[num] = nextSubject;
      num--;
    }
  }
  
  // output data
  cout << "\nFinished!" << endl;
  cout << "hashTable CAP = 90000/200" << endl;
  cout << "Total runtime: " << elapsedSeconds << " second(s)" << endl;
  cout << "The load factor for the duplication checking: " << seen.loadFactor() << endl;
  cout << "The average list size for the duplication checking: " << (double)seen.size() / total << endl;
  cout << "The load factor for the subject code: " << countSubjects.loadFactor() << endl;
  cout << "Total duplication: " << duplicates << endl;
  cout << "Total records: " << total << endl;
  cout << "Total subjects: " << countSubjects.size() << endl << endl;

  for(int i = 0; i < countSubjects.size(); i++)
    cout << output_a[i] << ", " << countSubjects[output_a[i]] << " sections" << endl;
  
}

int hashCode(const string& key)
{
  int index = 0;
  for (int i = 0; i < key.size(); i++)
    index += pow(i, 3) * key[i];
  return index;
}
