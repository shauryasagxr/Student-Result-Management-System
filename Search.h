#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "Student.h"
using namespace std;

int sequentialSearch(vector<Student> &arr, int id) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].StudentID == id)
            return i;
    }
    return -1;
}

int binarySearch(vector<Student> &arr, int id) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid].StudentID == id) return mid;
        else if (arr[mid].StudentID < id) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

#endif
