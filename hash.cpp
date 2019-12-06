//
// Created by tonyb on 12/4/2019.
//

#include "hash.h"
#include <iostream>

using namespace std;

Hash::Hash(){

    for(int i = 0; i < tableSize; i++){
        table[i] = NULL;
    }
}


void Hash::hashFunction(const string &key, int file) {

    int hashVal = 0;

    for(char ch : key)
        hashVal = 37 * hashVal + ch;

    int index = hashVal % tableSize;

    hashNode *temp = new hashNode;
    temp->data = file;
    if(table[index] == NULL){
        temp->next = NULL;
        table[index] = temp;
    }else{
        temp->next = table[index];
        table[index] = temp;
    }



}

Hash::~Hash(){

    for(int i = 0; i < tableSize; i++){
        if(table[i] != NULL){
            hashNode *current = table[i];
            hashNode *next = NULL;
            while(current != NULL){
                next = current->next;
                delete(current);
                current = next;
            }
            table[i] = NULL;
        }
    }
}


