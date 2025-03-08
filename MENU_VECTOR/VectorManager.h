#pragma once

#ifndef VECTORMANAGER_H
#define VECTORMANAGER_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include<limits>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::string;
using std::cerr;

class VectorManager {
public:
	VectorManager(int size);
    void displayMenu() const;
    void resize(int newSize);
    void addElement(int num);
    void removeElement();
    void sortAscending();
    void sortDescending();
    void displayVector() const;
    void clear();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void filterEven() const;
    void filterOdd() const;
    void eraseElement(int num);
    void insertElement(int num, int index);
    void deleteDuplicates();
    void insertRange(const std::vector<int>& other);
    int binarySearch(const int& target) const;
    void AddElementVec();
    void clearFile(ofstream &f);
    void DisplayFile(ifstream& f, string& s) const;
    void OpenFileData() const;
private:
    vector<int> vec = {};
};
#endif VECTORMANAGER_H
