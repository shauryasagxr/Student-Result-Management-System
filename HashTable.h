#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class HashTable {
    static const int size = 10;
    vector<Student> table[size];

    int hashFunction(int id) {
        return id % size;
    }

public:
    void insertStudent(Student s) {
        int index = hashFunction(s.StudentID);
        table[index].push_back(s);
    }

    Student* searchStudent(int id) {
        int index = hashFunction(id);
        for (auto &s : table[index]) {
            if (s.StudentID == id)
                return &s;
        }
        return NULL;
    }
};

#endif
