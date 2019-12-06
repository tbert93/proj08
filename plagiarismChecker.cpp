#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "hash.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char* argv[])
{
    string dir = string("C:\\Users\\tonyb\\CLionProjects\\proj08\\sm_doc_set");
    //int numWords = atoi(argv[2]);
    //int numDocs = atoi(argv[3]);
    vector<string> files = vector<string>();

    getdir(dir,files);


    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }

    Hash h;

    /*ifstream myFile;
    for(int i = 2; i < files.size(); i++){

        string fileptr = dir + '/' + files[i];
        myFile.open(fileptr.c_str());

        string word;
        vector<string> words;

        while(!myFile.eof()){
            while(words.size() < 6 && !myFile.eof() ){

                myFile >> word;

                if(word.length() != 0){
                    words.push_back(word);
                }
            }
            string chunk;

            for(int j = 0; j < word.length(); j++){
                chunk += word.at(j);
            }
            h.hashFunction(chunk, i-2);
            words.erase(words.begin());
        }

        myFile.close();

    }


   */return 0;
}