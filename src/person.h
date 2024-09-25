#ifndef PERSON_H
#define PERSON_H
#include "ui.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;

class Person {
public:
	string id;
	string name;
	string age;
	string address;
	string tellnumber;
	// Person();
	friend std::ostream& operator<<(std::ostream& FILE_OUT, Person& bn);
	void getData();
	void showData();
	void addRecord();
	void displayRecord();
	void deleteRecord();
	void table();
	void showDelete(string namefile);
	void searchRecord();
};

#endif