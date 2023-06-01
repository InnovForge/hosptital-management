#include "patient.h"
#include "ui.h"
#include <string>
Patient p;
void Patient::getData() {
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
  cin.ignore();
  cin >> id;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "ID Patient:              :  ";
  cin.ignore();
  cin >> idPatient;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Full Name:              :  ";
  cin.ignore();
  std::getline(cin, name);
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Age:                    :  ";
  cin.ignore();
  cin >> age;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "tellnumber              :  ";
  cin.ignore();
  cin >> tellnumber;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "address                 :  ";
  cin >> address;
  cout << std::endl;
}
void Patient::addRecord() {
  std::ofstream fout;
  fout.open("patient.txt", std::ios::out | std::ios::app);
  cin.ignore();
  p.getData();
  fout << p.idPatient << "|";
  fout << p; // được kế thừa từ lớp person;
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
    p.addRecord();
  } else
    menuPatient();
  getchar();
}
void Patient::displayRecord() {
  std::ifstream fin;
  // table();
  fin.open("patient.txt", std::ios::in);
  std::vector<Patient> listPatient;
  while (!fin.eof()) {
    std::getline(fin, p.idPatient, '|');
    std::getline(fin, p.id, '|');
    std::getline(fin, p.name, '|');
    std::getline(fin, p.age, '|');
    std::getline(fin, p.tellnumber, '|');
    std::getline(fin, p.address, '\n');
    // cin.ignore();
    listPatient.push_back(p);
  }

  p.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].idPatient
         << std::setw(20) << listPatient[i].name << std::setw(20)
         << listPatient[i].age << std::setw(20) << listPatient[i].tellnumber
         << std::setw(20) << listPatient[i].address << std::endl;
  }

  fin.close();
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "press enter to exit";
  getchar();
  cin.ignore();
  menuPatient();
}
void Patient::showDelete(string namefile) {
  std::ifstream fin;
  // table();
  fin.open(namefile, std::ios::in);
  std::vector<Patient> listPatient;
  // Bỏ qua dòng đầu tiên
  while (!fin.eof()) {
    Patient patient;
    std::getline(fin, patient.idPatient, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  p.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].idPatient
         << std::setw(20) << listPatient[i].name << std::setw(20)
         << listPatient[i].age << std::setw(20) << listPatient[i].tellnumber
         << std::setw(20) << listPatient[i].address << "[" << i << "]"
         << std::endl;
  }
  fin.close();
}
void Patient::deleteRecord() {
  system("cls");
  std::vector<string> records;
  string line;

  std::ifstream records_input("patient.txt");
  while (getline(records_input, line)) {
    records.push_back(line);
  }
  records_input.close();
  size_t recno = records.size();

  cout << "These are the records" << std::endl;
  showDelete("patient.txt");
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

  std::ofstream records_output("patient.txt");
  cout << "These are the records" << std::endl;
  for (size_t i = 0; i < recno; ++i) {
    records_output << records[i] << std::endl;
  }

  records_output.close();
  showDelete("patient.txt");
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
    p.deleteRecord();
  } else
    menuPatient();
  getchar();
}
void Patient::showData() {

  cout << std::setw(20) << std::left << idPatient << std::setw(20) << name
       << std::setw(20) << age << std::setw(20) << tellnumber << std::setw(20)
       << address << std::endl;
}
void Patient::searchRecord() {
  char n[10];
  int flag = 0;
  cout << "Enter id Doctor do you find: ";
  cin.ignore();
  cin >> n;
  std::ifstream fin;
  // table();
  fin.open("patient.txt", std::ios::in);
  std::vector<Patient> listPatient;
  while (!fin.eof()) {
    Patient patient;
    std::getline(fin, patient.idPatient, '|');
    std::getline(fin, patient.id, '|');
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.age, '|');
    std::getline(fin, patient.tellnumber, '|');
    std::getline(fin, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  p.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (listPatient[i].idPatient == n) {
      listPatient[i].showData();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << "\t\t\t\tNot Found....\n\n";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Press enter to exit";
  getchar();
  cin.ignore();
  menuPatient();
}
