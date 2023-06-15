#include "doctor.h"
#include "ui.h"
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
Doctor d;
// std::ostream& operator<<(std::ostream& FILE_OUT, Doctor& bn) {
//     FILE_OUT << bn.id << "|";
// 	FILE_OUT << bn.idDoctor << "|";
//     FILE_OUT << bn.name << "|";
//     FILE_OUT << bn.age << "|";
//     FILE_OUT << bn.tellnumber << "|";
//     FILE_OUT << bn.address << std::endl;
//     return FILE_OUT;
// }
void Doctor::getData() {
  system("cls");
  cout << " ";
  cout << "\n";
  cout << "\t\t\t\t";
  cout << "\n";
  cout << "\t\t\t\t";
  cout << "\n";
  cout << "\t\t\t\t";
  cout << "\n";
  cout << "\n\n\n\n";
  cout << "\t\t\t\t";
  cout << "Enter The Information Below:\n\n";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "ID:                     :  ";
  // cin.ignore();
  fflush(stdin);
  cin >> id;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "ID Doctor:              :  ";
  // cin.ignore();
  fflush(stdin);
  cin >> idDoctor;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Full Name:              :  ";
  cin.ignore();
  std::getline(cin, name);
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Age:                    :  ";
  fflush(stdin);
  // cin.ignore();
  cin >> age;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "tellnumber              :  ";
  /* cin.ignore(); */
  fflush(stdin);
  cin >> tellnumber;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "address                 :  ";
  cin.ignore();
  getline(cin, address);
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "bien che (1-yes/0-no)   :  ";
  fflush(stdin);
  cin >> bienche;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "salaty                  :  ";
  fflush(stdin);
  cin >> salary;
  cout << std::endl;
}
void Doctor::addRecord() {
  std::ofstream fout;
  fout.open("doctor.txt", std::ios::out | std::ios::app);
  cin.ignore();
  d.getData();
  fout << d.idDoctor << "|";
  fout << d.bienche << "|";
  fout << d.salary << "|";
  fout << d; // được kế thừa từ lớp person;
  fout.close();
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Record added successfully!!";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Do you want to add more?(Y/N)";
  char input;
  cin >> &input;
  if (input == 'Y' || input == 'y') {
    d.addRecord();
  } else
    menuDoctor();
  getchar();
}
void Doctor::showDelete(string namefile) {
  std::ifstream fin;
  // table();
  fin.open(namefile, std::ios::in);
  std::vector<Doctor> listPatient;
  // Bỏ qua dòng đầu tiên
  while (!fin.eof()) {
    Doctor patient;
    std::getline(fin, patient.idDoctor, '|');
    std::getline(fin, patient.bienche, '|');
    std::getline(fin, patient.salary, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  d.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].bienche << setw(20)
         << listPatient[i].salary << setw(20) << listPatient[i].idDoctor
         << std::setw(20) << listPatient[i].name << std::setw(20)
         << listPatient[i].age << std::setw(20) << listPatient[i].tellnumber
         << std::setw(20) << listPatient[i].address << "[" << i << "]"
         << std::endl;
  }
  fin.close();
}
void Doctor::displayRecord() {
  std::ifstream fin;
  // table();
  fin.open("Doctor.txt", std::ios::in);
  std::vector<Doctor> listPatient;
  while (!fin.eof()) {
    Doctor patient;
    std::getline(fin, patient.idDoctor, '|');
    std::getline(fin, patient.bienche, '|');
    std::getline(fin, patient.salary, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }

  d.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << std::setw(20)
         << listPatient[i].bienche << setw(20) << listPatient[i].salary
         << setw(20) << listPatient[i].idDoctor << std::setw(20)
         << listPatient[i].name << std::setw(20) << listPatient[i].age
         << std::setw(20) << listPatient[i].tellnumber << std::setw(20)
         << listPatient[i].address << std::endl;
  }

  fin.close();
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "press enter to exit";
  getchar();
  cin.ignore();
  menuDoctor();
}
void Doctor::deleteRecord() {
  system("cls");
  std::vector<string> records;
  string line;

  std::ifstream records_input("doctor.txt");
  while (getline(records_input, line)) {
    records.push_back(line);
  }
  records_input.close();
  size_t recno = records.size();

  cout << "These are the records" << std::endl;
  showDelete("doctor.txt");
  size_t Location = 0;
  cout << "Which record would you like to delete?" << std::endl;
  cin >> Location;
  system("cls");
  if (Location < 0 || Location >= recno) {
    cout << "Invalid choice" << std::endl;
  } else {
    cout << "You have chosen to delete record " << Location << ": "
         << records[Location] << std::endl;
    records.erase(records.begin() + Location);
    recno = records.size();
  }

  std::ofstream records_output("doctor.txt");
  cout << "These are the records" << std::endl;
  for (size_t i = 0; i < recno; ++i) {
    records_output << records[i] << std::endl;
  }

  records_output.close();
  showDelete("doctor.txt");
  cout << std::endl << "Goodbye" << std::endl;

  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Record delete successfully!!";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Do you want to delete more?(Y/N)";
  char input;
  cin >> &input;
  if (input == 'Y' || input == 'y') {
    d.deleteRecord();
  } else
    menuDoctor();
  getchar();
}
void Doctor::showData() {

  cout << std::setw(20) << std::left << idDoctor << std::setw(20) << name
       << std::setw(20) << age << std::setw(20) << tellnumber << std::setw(20)
       << address << std::endl;
}
void Doctor::searchRecord() {
  string Name;
  int flag = 0;
  cout << "Enter name Doctor do you find: ";
  cin.ignore();
  getline(cin, Name);
  std::ifstream fin;
  // table();
  fin.open("doctor.txt", std::ios::in);
  std::vector<Doctor> listPatient;
  while (!fin.eof()) {
    Doctor patient;
    std::getline(fin, patient.idDoctor, '|');
    std::getline(fin, patient.bienche, '|');
    std::getline(fin, patient.salary, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  d.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (listPatient[i].name == Name) {
      listPatient[i].showData();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << "\t\t\t\tnot found....\n\n";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "press enter to exit";
  getchar();
  cin.ignore();
  menuDoctor();
}
void Doctor::TienLuong() {
  std::ifstream fin;
  // table();
  fin.open("Doctor.txt", std::ios::in);
  std::vector<Doctor> listPatient;
  while (!fin.eof()) {
    Doctor patient;
    std::getline(fin, patient.idDoctor, '|');
    std::getline(fin, patient.bienche, '|');
    std::getline(fin, patient.salary, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  fin.close();
  vector<int> arrNumber;
  for (int i = 0; i < listPatient.size() - 1; i++) {
    // listPatient[i].salary;
    int tien = stoi(listPatient[i].salary);
    arrNumber.push_back(tien);
  }
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (listPatient[i].bienche == "1") {
      cout << right << setw(50) << listPatient[i].name << ": "
           << listPatient[i].salary << " + Bonus 500" << endl;
    } else {
      cout << right << setw(50) << listPatient[i].name << ": "
           << listPatient[i].salary << endl;
    }
  }
  int Sum = 0;
  for (int i = 0; i < arrNumber.size(); i++) {
    if (listPatient[i].bienche == "1") {
      arrNumber[i] += 500;
      Sum += arrNumber[i];
    } else {
      Sum += arrNumber[i];
    }
  }
  cout << "\n\n\n\nSum salary all Doctor: " << Sum << endl;
  cout << "\t\t\t\t";
  cout << "Press Enter to exit";
  getchar();
  cin.ignore();
  menuDoctor();
}
