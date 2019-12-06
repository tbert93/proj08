//
// Created by tonyb on 12/4/2019.
//

#ifndef PROJ08_HASH_H
#define PROJ08_HASH_H

#include <vector>
#include <string>
#include <list>


using namespace std;


class Hash {
private:
   
   static const int tableSize = 1000037;   //very large prime number

   vector<int> *table;




public:

    Hash();

    void hashFunction(const string &s, int key);
    void displayHash();
    void displayCollisions(int cheaterNum, int numFiles, vector<string> &files);
    void scrubber(string &str);
    ~Hash();



};


#endif //PROJ08_HASH_H
