#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include "Student.h"
using namespace std;

// QUICK SORT
int partition(vector<Student> &arr, int low, int high) {
    int pivot = arr[high].Marks;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].Marks <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Student> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// HEAP SORT
void heapify(vector<Student> &arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left].Marks > arr[largest].Marks)
        largest = left;
    if (right < n && arr[right].Marks > arr[largest].Marks)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<Student> &arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// RADIX SORT
int getMaxRoll(vector<Student> &arr) {
    int maxVal = arr[0].StudentID;
    for (auto &s : arr)
        maxVal = max(maxVal, s.StudentID);
    return maxVal;
}

void countSort(vector<Student> &arr, int exp) {
    int n = arr.size();
    vector<Student> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i].StudentID / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i].StudentID / exp) % 10] - 1] = arr[i];
        count[(arr[i].StudentID / exp) % 10]--;
    }

    arr = output;
}

void radixSort(vector<Student> &arr) {
    int maxRoll = getMaxRoll(arr);
    for (int exp = 1; maxRoll / exp > 0; exp *= 10)
        countSort(arr, exp);
}

#endif
