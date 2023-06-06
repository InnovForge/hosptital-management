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
  void addMedicalReport(); // hồ sơ bệnh án bệnh nhân;
  int findName(string name);
  void getMeical();
};
struct addMedicalReport {
  std::string tenBenhNhan;
  std::string trieuChung;
  std::string chuanDoan;
  std::string ngayDieutri;
  std::string lishsuketQuaKham;
};
/**/
#endif
