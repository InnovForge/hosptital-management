#include "patient.h"
#include "ui.h"
#include <cstdio>
#include <fstream>
#include <ios>
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
int checkLine() {
  std::ifstream file("patient.txt");
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (line.empty()) {
        return 1; // dong trong;
      } else {
        return 0;
      }
    }
  }
  file.close();
  return 0;
}
void Patient::addRecord() {
  std::ofstream fout;
  fout.open("patient.txt", std::ios::out | std::ios::app);
  cin.ignore();
  p.getData();
  fout << p.idPatient << "|";
  fout << p; // được kế thừa từ lớp person
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

  /* đây là dòng tính toán phần từ*/
  std::ifstream fin_temp;
  // table();
  fin_temp.open("patient.txt", std::ios::in);
  std::vector<Patient> listPatient;
  // Bỏ qua dòng đầu tiên
  while (!fin_temp.eof()) {
    Patient patient;
    std::getline(fin_temp, patient.idPatient, '|');
    std::getline(fin_temp, patient.id, '|');
    std::getline(fin_temp, patient.name, '|');
    std::getline(fin_temp, patient.age, '|');
    std::getline(fin_temp, patient.tellnumber, '|');
    std::getline(fin_temp, patient.address, '\n');
    // cin.ignore();
    listPatient.push_back(patient);
  }
  fin_temp.close();
  string dataname = listPatient[Location].name;
  deleteMedical(name);
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
int Patient::findName(string name) {
  std::ifstream fin;
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
  fin.close();
  int pos = 1;
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (name == listPatient[i].name) {
      pos = i + 1;
      return pos;
    }
  }
  return false;
}
medicalRecord patient;
void addmedicalRecord() {
  cout << "nhap chuan doan benh: ";
  cin.ignore();
  std::fflush(stdin);
  getline(cin, patient.chanDoan);
  cout << "lish su benh: ";
  cin.ignore();
  std::fflush(stdin);
  getline(cin, patient.lishsubenh);
}
void Patient::addMedical() {
  std::ifstream fin;
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
  fin.close();
  string name;
  cout << "nhap ten benh nhan: ";
  cin.ignore();
  // std::fflush(stdin);
  getline(cin, name);
  if (findName(name) == false) {
    cout << "khong tim thay" << name;
    cout << "\ndo you want return main or retart?";
    char input;
    cin >> input;
    if (input == 'Y' || input == 'y') {
      p.addMedical();
    } else
      menuPatient();
    getchar();
  } else {
    fstream fout;
    fout.open("medical.txt", ios::app | ios::out);
    addmedicalRecord();
    fout << name << "|";
    fout << patient.chanDoan << "|" << endl;
    fout.close();
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Record add successfully!!";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Do you want to add more?(Y/N)";
    char input;
    cin >> &input;
    if (input == 'Y' || input == 'y') {
      p.addMedical();
    } else
      menuPatient();
    getchar();
  }

  /*har deleteFile[] = "patient.txt";
    char oldname[] = "temp.txt";
    char newname[] = "patient.txt";
    if (remove(deleteFile) != 0)
    {
      perror("Error removing file");
    }
    else
    {
      cout << "delete file successfully";
    }
    if (rename(oldname, newname) != 0)
      perror("Error renaming file");
    else
      cout << "File renamed successfully";

    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Record add successfully!!";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Do you want to add more?(Y/N)";
    char input;
    cin >> &input;
    if (input == 'Y' || input == 'y')
    {
      p.add();
    }
    else
      menuPatient();
    getchar();*/
}
void deleteMedical(string name) {
  system("cls");
  std::fstream fin;
  // table();
  fin.open("medical.txt", std::ios::in);
  std::vector<medicalRecord> medicalRe;
  // Bỏ qua dòng đầu tiên
  while (!fin.eof()) {
    medicalRecord patient;
    std::getline(fin, patient.name, '|');
    std::getline(fin, patient.chanDoan, '|');
    std::getline(fin, patient.lishsubenh, '\n');
    // cin.ignore();
    medicalRe.push_back(patient);
  }
  fin.close();
  int count = 0; // dem vi tri can xoa;
  for (int i = 0; i < medicalRe.size() - 1; i++) {
    if (medicalRe[i].name == name) {
      count = i;
    }
  }
  std::vector<string> records;
  string line;

  std::ifstream records_input("medical.txt");
  while (getline(records_input, line)) {
    records.push_back(line);
  }
  records_input.close();
  size_t recno = records.size();

  cout << "These are the records" << std::endl;
  size_t Location = count;
  if (Location < 0 || Location >= recno) {
    cout << "Invalid choice" << std::endl;
  } else {
    cout << "You have chosen to delete record " << Location << ": "
         << records[Location] << std::endl;
    records.erase(records.begin() + Location);
    recno = records.size();
  }

  std::ofstream records_output("medical.txt");
  cout << "These are the records" << std::endl;
  for (size_t i = 0; i < recno; ++i) {
    records_output << records[i] << std::endl;
  }
  records_output.close();
}
