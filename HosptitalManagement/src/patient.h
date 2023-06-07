#ifndef PATIENT_H
#define PATIENT_H
#include "person.h"
#include <fstream>
#include <string>

class Patient : public Person {
public:
  std::string idPatient;
  void getData();
  void showData();
  void addRecord();
  void displayRecord();
  void deleteRecord();
  void showDelete(string namefile);
  void table();
  void searchRecord();
  int findName(string name);
  void addMedical();
  void reNameFile();
};
struct medicalRecord {
  string name;
  string chanDoan;
  string lishsubenh;
};
void addMedical();
void chuandoan();
void deleteMedical(string name);
#endif
