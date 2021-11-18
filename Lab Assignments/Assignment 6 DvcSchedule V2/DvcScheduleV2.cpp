// Programmer: Elise Zur
// Programmer's ID: 1851550

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include <cstring>

#include "DynamicArray.h"
#include "StaticArray.h"

struct Subjects
{
  string subjectCode;
  int sections;
};

struct SectionsForTerm
{
  string term;
  int numSectionsSeen;
  DynamicArray<string> seenSectionNumber;
};

bool checkDuplicate(string term, string section, int& numberOfTermsSeen, StaticArray<SectionsForTerm, 200>& alreadySeen, int& duplicate);

int main()
{
  // identification
  cout << "Programmer: Elise Zur\n";
  cout << "Programmer's ID: 1851550\n";
  cout << "File: " << __FILE__ << endl << endl;

  // declarations
  int duplicate = 0;  // # of duplicate courses
  int numTermsSeen = 0; // int numTermsSeen
  int totalLines = 0; // # of lines processed
  int index = 0;

  StaticArray<SectionsForTerm, 200> alreadySeen;
  DynamicArray<Subjects> subjects;

  // open input file & check access
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.is_open())
  {
    cout << "Error. Unable to open the file." << endl;
    return 1;
  }

  while (fin.good())
  {
    bool ifDuplicate = false;
    bool alreadySeenSubject = false;
    
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    string data;
    getline(fin, data);
    strcpy(buf, data.c_str());

    if(buf[0] == 0) continue; // skip blank lines

    // parse each line
    const string term(token = strtok(buf, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string courseName((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if(courseName.find('-') == string::npos) continue;
    const string subjectCode(courseName.begin(), courseName.begin() + courseName.find('-'));

    // count the # of lines processed
    totalLines++;

    // check duplicate & store info in array
    ifDuplicate = checkDuplicate(term, section, numTermsSeen, alreadySeen, duplicate);

    if (ifDuplicate)
      duplicate++;
    else
    {
      for (int i = 0; i < index; i++)
      {
        if (subjectCode == subjects[i].subjectCode)
        {
          alreadySeenSubject = true;
          subjects[i].sections++;
          break;
        }
      }

      if (!alreadySeenSubject)
      {
        subjects[index].subjectCode = subjectCode;
        subjects[index].sections = 1;
        index += 1;
      }
    }
  }

  // close file
  fin.close();

  // sort
  for (int i = 0; i < index; i++)
    for (int j = i + 1; j < index; j++)
      if (subjects[j].subjectCode < subjects[i].subjectCode)
        swap(subjects[i].subjectCode, subjects[j].subjectCode);

  // display result
  cout << "\nUnique number of courses is " << (totalLines - duplicate) << endl << endl;

  // display subjects & # of sections
  for (int i = 0; i < index; i++)
    cout << left << setw(8) << subjects[i].subjectCode << subjects[i].sections << " sections" << endl;

  // display results
  cout << "Total duplicates: " << duplicate << endl;
  cout << "Total counts: " << totalLines << endl;
  cout << "Total subjects: " << index << endl;

  return 0;
}

bool checkDuplicate(string term, string section, int& numTermsSeen,
                    StaticArray<SectionsForTerm, 200>& alreadySeen, int& duplicate)
{
  bool foundTerm = false;
  bool foundSec = false;

  // check if the term is included in alreadySeen
  for(int i = 0; i < numTermsSeen; i++)
  {
    if(term == alreadySeen[i].term)
    {
      foundTerm = true;

      // check if the section is in alreadySeen, if the term is found in alreadySeen
      for(int j = 0; j < alreadySeen[i].numSectionsSeen; j++)
      {
        if(section == alreadySeen[i].seenSectionNumber[j])
        {
          foundSec = true;
          break;
        }
      }

      // add section if it is unique
      if(!foundSec)
      {
        alreadySeen[i].seenSectionNumber[alreadySeen[i].numSectionsSeen] = section;
        alreadySeen[i].numSectionsSeen++;
      }
      break;
    }
  }

  // add term and section when the term is not found
  if(!foundTerm)
  {
    alreadySeen[numTermsSeen].term = term;
    alreadySeen[numTermsSeen].numSectionsSeen = 1;
    alreadySeen[numTermsSeen].seenSectionNumber[0] = section;
    numTermsSeen++;
  }

  return (foundTerm && foundSec);
}



