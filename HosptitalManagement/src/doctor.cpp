#include "doctor.h"
#include "ui.h"
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
  cin.ignore();
  cin >> id;
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "ID Doctor:              :  ";
  cin.ignore();
  cin >> idDoctor;
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
void Doctor::addRecord() {
  std::ofstream fout;
  fout.open("doctor.txt", std::ios::out | std::ios::app);
  cin.ignore();
  d.getData();
  fout << d.idDoctor << "|";
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
    cout << std::setw(20) << std::left << listPatient[i].idDoctor
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
    std::getline(fin, d.idDoctor, '|');
    std::getline(fin, d.id, '|');
    std::getline(fin, d.name, '|');
    std::getline(fin, d.age, '|');
    std::getline(fin, d.tellnumber, '|');
    std::getline(fin, d.address, '\n');
    // cin.ignore();
    listPatient.push_back(d);
  }

  d.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].idDoctor
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
  char n[10];
  int flag = 0;
  cout << "Enter id Doctor do you find: ";
  cin.ignore();
  cin >> n;
  std::ifstream fin;
  // table();
  fin.open("doctor.txt", std::ios::in);
  std::vector<Doctor> listPatient;
  while (!fin.eof()) {
    Doctor doctor;
    std::getline(fin, doctor.idDoctor, '|');
    std::getline(fin, doctor.id, '|');
    std::getline(fin, doctor.name, '|');
    std::getline(fin, doctor.age, '|');
    std::getline(fin, doctor.tellnumber, '|');
    std::getline(fin, doctor.address, '-');
    // cin.ignore();
    listPatient.push_back(doctor);
  }
  d.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (listPatient[i].idDoctor == n) {
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
