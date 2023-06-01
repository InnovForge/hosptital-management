#include "person.h"
using namespace std;
Person ps;
std::ostream &operator<<(std::ostream &FILE_OUT, Person &bn) {
  FILE_OUT << bn.id << "|";
  FILE_OUT << bn.name << "|";
  FILE_OUT << bn.age << "|";
  FILE_OUT << bn.tellnumber << "|";
  FILE_OUT << bn.address << std::endl;
  return FILE_OUT;
}
void Person::getData() {
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
  cout << "Full name:              :  ";
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

void Person::showData() {

  cout << std::setw(20) << std::left << id << std::setw(20) << name
       << std::setw(20) << age << std::setw(20) << tellnumber << std::setw(20)
       << address << std::endl;
}
void Person::addRecord() {
  std::ofstream fout;
  fout.open("data.txt", ios::out | ios::app);
  ps.getData();
  fout << ps;
  fout.close();
  // cout << "\n\nData Successfully Saved to File....\n";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Record added successfully!!";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Do you want to add more?(Y/N)";
  char input;
  cin >> &input;
  if (input == 'Y' || input == 'y') {
    ps.addRecord();
  } else
    menuPatient();
  getchar();
}

void Person::displayRecord() {
  std::ifstream fin;
  // table();
  fin.open("data.txt", std::ios::in);
  std::vector<Person> listPatient;
  while (!fin.eof()) {
    Person benhnhan;
    std::getline(fin, benhnhan.id, '|');
    std::getline(fin, benhnhan.name, '|');
    std::getline(fin, benhnhan.age, '|');
    std::getline(fin, benhnhan.tellnumber, '|');
    std::getline(fin, benhnhan.address, '\n');
    // cin.ignore();
    listPatient.push_back(benhnhan);
  }
  ps.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].id << std::setw(20)
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
  menuPatient();
}
void Person::showDelete(string namefile) {
  std::ifstream fin;
  // table();
  fin.open(namefile, std::ios::in);
  std::vector<Person> listPatient;
  while (!fin.eof()) {
    Person benhnhan;
    std::getline(fin, benhnhan.id, '|');
    std::getline(fin, benhnhan.name, '|');
    std::getline(fin, benhnhan.age, '|');
    std::getline(fin, benhnhan.tellnumber, '|');
    std::getline(fin, benhnhan.address, '\n');
    // cin.ignore();
    listPatient.push_back(benhnhan);
  }
  table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    cout << std::setw(20) << std::left << listPatient[i].id << std::setw(20)
         << listPatient[i].name << std::setw(20) << listPatient[i].age
         << std::setw(20) << listPatient[i].tellnumber << std::setw(20)
         << listPatient[i].address << "[" << i << "]" << std::endl;
  }
  fin.close();
}
void Person::deleteRecord() {
  system("cls");
  std::vector<string> records;
  string line;

  std::ifstream records_input("data.txt");
  while (getline(records_input, line)) {
    records.push_back(line);
  }

  records_input.close();
  size_t recno = records.size();

  cout << "These are the records" << std::endl;
  showDelete("data.txt");
  size_t recno1 = 0;
  cout << "Which record would you like to delete?" << std::endl;
  cin >> recno1;
  system("cls");
  if (recno1 < 0 || recno1 >= recno) {
    cout << "Invalid choice" << std::endl;
  } else {
    cout << "You have chosen to delete record " << recno1 << ": "
         << records[recno1] << std::endl;
    records.erase(records.begin() + recno1);
    recno = records.size();
  }

  std::ofstream records_output("data.txt");
  cout << "These are the records" << std::endl;
  for (size_t i = 0; i < recno; ++i) {
    records_output << records[i] << std::endl;
  }

  records_output.close();
  showDelete("data.txt");
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
    ps.deleteRecord();
  } else
    menuPatient();
  getchar();
}
void Person::searchRecord() {
  char n[10];
  int flag = 0;
  cout << "nhap n";
  cin >> n;
  std::ifstream fin;
  // table();
  fin.open("data.txt", std::ios::in);
  std::vector<Person> listPatient;
  while (!fin.eof()) {
    Person benhnhan;
    std::getline(fin, benhnhan.id, '|');
    std::getline(fin, benhnhan.name, '|');
    std::getline(fin, benhnhan.age, '|');
    std::getline(fin, benhnhan.tellnumber, '|');
    std::getline(fin, benhnhan.address, '\n');
    // cin.ignore();
    listPatient.push_back(benhnhan);
  }
  ps.table();
  for (int i = 0; i < listPatient.size() - 1; i++) {
    if (listPatient[i].id == n) {
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
  menuPatient();
}
