#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> readCharFile(string filePath) // This is a predefined function given with the assignment. 
{
    ifstream in(filePath);
    char c;
    string w = "";
    vector<string> strings;
    if (!in.eof() && in.fail()) {
        cerr << "<<<!! ERROR - " << filePath << " NOT FOUND !!!>>>" << endl;
        return strings;
    }

    if (in.is_open()) {
        while (in.good()) {
            in.get(c);

            c = tolower(c);
            if (isalpha(c)) {
                w += c;
            }
            else if (isspace(c)) {
                if (w != "") {
                    strings.push_back(w);
                }
                w = "";
            }
        }
        if (w != "") {
            strings.push_back(w);
        }
    }
    in.close();
    return strings;
}


vector<pair<string, int>>  countDuplicates(vector<string> data)// This function counts words and appends the number of occurences in a paired vector. 
{                                                       // This was achieved with help from this forum: http://www.cplusplus.com/forum/beginner/168895/
    vector<string> unique;									
    unique_copy(data.begin(), data.end(), back_inserter(unique));
    // This code allows for testing in between stages, so as to see the contents of the vector. 

    cout << endl << endl << "Original text: " << endl;
    for (int i = 0; i < unique.size(); i++)
    {
        cout << unique[i] << " ";
    }

    cout << endl << endl << endl;
    vector<pair<string, int>> pairedVector;
    for (string i : unique) // 'Range-for' loop is a useful concept I had never encountered before. 
        pairedVector.emplace_back(i, count(data.begin(), data.end(), i)); // Complex insertion of the nested 'count' function, into the paired vector. 
   
  // This code allows for checking the contents of the paired vector. 
    cout << "Contents of the paired vector: "<<endl;
    for (int i = 0; i < pairedVector.size(); i++)
    {
        cout << pairedVector[i].first << ", " << pairedVector[i].second << " | ";
    } 
    cout << endl << endl << endl<<endl;
    return pairedVector; // At this stage, the vector contains pairs with specific words - and their count (duplicates remain). 
}

void removeDuplicate(vector<pair<string, int>>& pairedVector) // This function removes the multiple occurences of a specific word. 
                                                //This problem was solved with help from this forum: https://www.techiedelight.com/remove-duplicates-vector-cpp/
{
    auto end = pairedVector.end();
    for (auto i = pairedVector.begin(); i != end; ++i)
    {
        end = remove(i + 1, end, *i); //Complex logic from the forum (unoriginal, though re-purposed). 
    }
    pairedVector.erase(end, pairedVector.end()); // These are operations / libraries which I was ignorant of before researching. 
}
