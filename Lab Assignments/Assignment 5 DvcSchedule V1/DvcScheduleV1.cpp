// Programmer: Elise Zur
// Programmer's ID: 1851550

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <cstring> // for strtok and strcpy
#include "DynamicArray.h"

struct dvc_classes
{
  string term;
  string section;
  string course;
  string subjectCode;
};

int main()
{
  // programmer's identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl;
  
  int progress = 0;
  int duplicate = 0;
  int unique = 0;
  int totalLines = 0; // # of lines processed
  int totalSubjects = 1; // # of subjects
  int sections = 0; // # of sections counted for each subject code
  int index = 0;
  DynamicArray<dvc_classes> unique_course; // array to access the struct
  DynamicArray<bool> unique_subjectcode;
  DynamicArray<bool> is_duplicate;

  is_duplicate = false;
  
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good())
    cout << "I/O error. File can't find!\n";
  
  while (fin.good())
  {
   // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());

    if (buf[0] == 0) continue; // skip blank lines

    //parse the line
    const string term(token = strtok(buf, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    // count the total number of lines processed
    totalLines++;
    
    // progress bar
    if (progress == 5000)
    {
      cout << '.';
      cout.flush();
      progress = 0;
    }
    progress++;

    // finding duplicates
    for (int i = 0; i < totalLines; i++)
    {
      if (unique_course[i].term == term && unique_course[i].section == section)
      {
        is_duplicate[i] = true;
        duplicate++;
        break;
      }
    }

    if (!(is_duplicate[index]))
    {
      unique_course[index].term = term;
      unique_course[index].section = section;
      unique_course[index].course = course;
      unique_course[index].subjectCode = subjectCode;
      index++;
    }
    
  } // end of while loop
  
    // sorting alphabetically
    for (int i = 0; i < index; i++)
    {
      for (int j = i + 1; j < index; j++)
      {
        if (unique_course[i].subjectCode > unique_course[j].subjectCode)
          swap(unique_course[j].subjectCode, unique_course[i].subjectCode);
      }
      if (progress == 1000)
      {
        cout << '.';
        cout.flush();
        progress = 0;
      }
      progress++;
    }
    
  unique = (totalLines - duplicate);
  cout << "\n\nUnique number of courses: " << unique << endl;
  
  for (int i = 0; i < totalLines; i++)
    unique_subjectcode[i] = true;

  // count # of subjects
  for (int i = 0; i < totalLines; i++)
  {
    if (unique_subjectcode[i])
    {
      for (int j = 0; j < totalLines; j++)
      {
        if (unique_course[i].subjectCode == unique_course[j].subjectCode)
        {
          unique_subjectcode[j] = false;
          sections++;
        }
      }
      cout << unique_course[i].subjectCode << ' ' << sections << endl;
      sections = 0;
      totalSubjects++;
    }
  }
  
  // closes the file
  fin.close();
  
  cout << "\nTotal duplicates: " << duplicate << endl;
  cout << "Total  lines processed: " << totalLines << endl;
  cout << "Total subjects: " << totalSubjects << endl;
}
