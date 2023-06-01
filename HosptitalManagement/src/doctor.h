#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"
#include <fstream>
#include <string>

class Doctor : public Person {
public:
  std::string idDoctor;
  void getData();
  void showData();
  void addRecord();
  void displayRecord();
  void table();
  void deleteRecord();
  void showDelete(string namefile);
  void searchRecord();
};
#endif // !DOCTOR_H
