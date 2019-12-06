//
// Created by tonyb on 12/4/2019.
//

#include "hash.h"
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <bits/stdc++.h>

using namespace std;

Hash::Hash(){

    table = new vector<int>[tableSize];

}


void Hash::hashFunction(const string &key, int file) {

    unsigned int hashVal = 0;
    for(int ch = 0; ch < key.size(); ch++)
        hashVal = 37 * hashVal + key[ch];

    unsigned int index = hashVal % tableSize;

    table[index].push_back(file);


}

//displays hashtable and values
void Hash::displayHash() {

    for(int i = 0; i < tableSize; i++){
        for(int j = 0; j < table[i].size(); j++){

            cout << i << ": " << table[i].at(j) << endl;

        }
    }
}

//finds and displays the collsions, displayed in ascending order

void Hash::displayCollisions(int cheaterNum, int numFiles, vector<string> &files) {

    int cheaterArr[numFiles][numFiles];
    for(int i = 0; i < numFiles; i++){
        for(int j = 0; j < numFiles; j++){
            cheaterArr[i][j] = 0;
        }
    }


    for(int i = 0; i < tableSize; i++){
        for(int j = 0; j < table[i].size(); j++){
            int k = j + 1;
            if(k < table[i].size()){
                int firstFile = table[i].at(j);
                int secondFile = table[i].at(k);
                if(table[i].at(j) != table[i].at(k)) {
                    cheaterArr[firstFile][secondFile]++;
                }

            }
        }
    }

    vector<int> sortArr;

    for(int i = 0; i < numFiles; i++){
        for(int j = 0; j < numFiles; j++){
            if(cheaterArr[i][j] >= cheaterNum){
                sortArr.push_back(cheaterArr[i][j]);

            }
        }
    }

    sort(sortArr.begin(),sortArr.end());

    for(int k = 0; k < sortArr.size(); k++){
        for(int i = 0; i < numFiles; i++){
            for(int j = 0; j < numFiles; j++){
                if(cheaterArr[i][j] == sortArr.at(k)){
                    cout << cheaterArr[i][j] << ": " << files.at(i+2) << " and " << files.at(j+2) << endl;

            }
        }
    }
    }


}

//scrubs word chnks so that characters are lowercase and erases punctuation and non letters

void Hash::scrubber (string &str) {

    for (int i = 0; i < str.length(); i++){
        if (96 < str[i] && str[i] < 123)
            str[i] = str[i] - 32;
        if(str[i]<64 || str[i]>91){
            str.erase(str.begin()+i);
            i--;
        }
    }
}

Hash::~Hash(){


}


