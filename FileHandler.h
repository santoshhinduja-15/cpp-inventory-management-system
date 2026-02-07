#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
using namespace std;

inline void ensureFileExists(const char* filename) {
    ifstream fin(filename);
    if (!fin.good()) {
        ofstream fout(filename);
        fout.close();
    }
}

#endif
