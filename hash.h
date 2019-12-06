//
// Created by tonyb on 12/4/2019.
//

#ifndef PROJ08_HASH_H
#define PROJ08_HASH_H

#include <vector>
#include <string>


using namespace std;


class Hash {
private:
    static const int tableSize = 1000007;   //very large prime number

    struct hashNode{

        int data;
        hashNode *next;
    };

    hashNode* table[tableSize];



public:

    Hash();

    void hashFunction(const string &s, int key);
    ~Hash();



};


#endif //PROJ08_HASH_H
