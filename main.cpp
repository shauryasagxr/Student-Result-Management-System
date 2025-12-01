#include <iostream>
#include <vector>
#include "Student.h"
#include "HashTable.h"
#include "Sorting.h"
#include "Search.h"

using namespace std;

int main() {
    HashTable ht;
    vector<Student> records;

    records.push_back({101, "Amit", 87, "DSA"});
    records.push_back({103, "Shaurya", 92, "DSA"});
    records.push_back({102, "Riya", 76, "DSA"});
    records.push_back({104, "Kabir", 69, "DSA"});

    for (auto s : records)
        ht.insertStudent(s);

    cout << "\n--- SEARCH USING HASH TABLE ---\n";
    Student* s = ht.searchStudent(103);
    if (s)
        cout << "Found: " << s->StudentName << " | Marks: " << s->Marks << endl;

    cout << "\n--- SORT BY MARKS: QUICK SORT ---\n";
    quickSort(records, 0, records.size() - 1);
    for (auto s : records)
        cout << s.StudentID << " " << s.StudentName << " " << s.Marks << endl;

    cout << "\n--- SORT BY MARKS: HEAP SORT ---\n";
    heapSort(records);
    for (auto s : records)
        cout << s.StudentID << " " << s.StudentName << " " << s.Marks << endl;

    cout << "\n--- SORT BY ROLL NUMBER: RADIX SORT ---\n";
    radixSort(records);
    for (auto s : records)
        cout << s.StudentID << " " << s.StudentName << endl;

    cout << "\n--- BINARY SEARCH FOR ROLL 102 ---\n";
    int index = binarySearch(records, 102);
    if (index != -1)
        cout << "Found: " << records[index].StudentName;
    else
        cout << "Not found";

    return 0;
}
