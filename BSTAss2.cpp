/*
Author: Jacob Ellis
Date: 18/03/20
Assignment 2: Question 2. 

The purpose of this program is to create a Binary Search Tree (BST) with words which have been input from an external text file. 
This program should include three files, BST.h, BST.cpp, and readText.h.
Comments on individual functions / methods can be found at the place at which they are declared, rather than within the main function. 
Further information can be found in the accompanying report. 

*/

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include "BST.h"
#include "readText.h"
using namespace std;




int main()
{

    string filename = "";
    cout << "Please enter the name of the file you would like to parse : ";   
    cin >> filename;
    
    filename += ".txt"; // This appends a filepath to the input filename so that custom filenames may be entered. 

    vector<string> words;
    words = readCharFile(filename); // Takes in a string as a filename.


    vector<pair<string, int>> pairVect = countDuplicates(words); // Creates a paired vector, with a string, and a count of the occurences. 

    removeDuplicate(pairVect); // Removes duplicates from vector.

    BST BSTree; // Create Binary Search Tree object.    

    for (int i = 0; i < pairVect.size(); i++) //Loop for inserting words into tree.         
    {
        BSTree.Insert(pairVect[i].first, pairVect[i].second); // 'first' and 'second' refer to the separate elements in the paired vector. 
    }




    BSTree.Results();

    return 0;
}

