#include "ui.h"
#include "doctor.h"
#include "patient.h"
#include "person.h"
#include <cstdlib>
using namespace std;

void loading() {
  std::cout << "Loading ";
  for (int i = 0; i < 10; i++) {
    std::cout << ".";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "\b.";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    std::cout << "\b.";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    std::cout << "\b.";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(55));
    std::cout << "\b.";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
  std::cout << " Done!" << std::endl;
}

void select() {
  system("cls");
  int input;
  title();
  cout << " 1. Open Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 2. Open Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 0. Exit\n\n";
  cout << "\t\t\t\t";
  cout << "Choose options:[1/2/0]";
  fflush(stdin);
  fflush(stdin);
  cin >> input;
  switch (input) {
    {
    case 1:
      menuPatient();
      break;
    case 2:
      menuDoctor();
      break;
    case 0: {
      system("cls");
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      fflush(stdin);
      cout << "\t\t\t\t";
      cout << "by nguyen tuong hy";
      cout << "\n\n\n\n";
      exit(0);
    } break;
    default:
      fflush(stdin);
      cout << "\n\n\n";
      cout << "\t\t\t\t";
      cout << "      Invalid input!";
      cout << "\n\n";
      cout << "\t\t\t\t";
      cout << "Press Enter to choose again...";
      getchar();
      select();
    }
  }
}

void start() {
  system("cls");
  cout << "\n";
  cout << "\t\t\t\t    ---------------------------\n";
  cout << "\t\t\t\t    |HOPITAl MANAGEMENT SYSTEM|\n";
  cout << "\t\t\t\t    ---------------------------\n";
  cout << "\n\n\n";
  cout << "\t\t\t\t";
  cout << "Leader   ";
  cout << ":";
  cout << "   Nguyen Thanh Nhat - 28211549569";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Member   ";
  cout << ":";
  cout << "   Nguyen Tuong Hy - 28210200564";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Member   ";
  cout << ":";
  cout << "   Nguyen Tien Dat - 28211100961";
  cout << "\n\n";
  cout << "\t\t\t\t";
  cout << "Member   ";
  cout << ":";
  cout << "   Luu Duc Thang - 28211153081\n";
  cout << "\n\n";
  cout << "\t\t\t\tPress Enter to continue......";
  cout << "\n\n";
  getchar();
  cout << "\t\t\t\t";
  loading();
}
void Person::table() {
  cout << std::setw(20) << std::left << "ID" << std::setw(20) << "Full Name"
       << std::setw(20) << "Age" << std::setw(20) << "Tell Number"
       << std::setw(20) << "Address" << std::endl;
  cout << "------------------------------------------------------------------"
          "-----------------------\n";
}
void Doctor::table() {
  cout << std::setw(20) << std::left << "ID Doctor" << std::setw(20)
       << "Full Name" << std::setw(20) << "Age" << std::setw(20)
       << "Tell Number" << std::setw(20) << "Address" << std::endl;
  cout << "------------------------------------------------------------------"
          "-----------------------\n";
}
void Patient::table() {
  cout << std::setw(20) << std::left << "ID Patient" << std::setw(20)
       << "Full Name" << std::setw(20) << "Age" << std::setw(20)
       << "Tell Number" << std::setw(20) << "Address" << std::endl;
  cout << "------------------------------------------------------------------"
          "-----------------------\n";
}

void title() {
  cout << "\n\n\n";
  cout << "\t\t\t\t\t";
  cout << "\n";
  cout << "\t\t\t\t    ---------------------------\n";
  cout << "\t\t\t\t    |HOPITAl MANAGEMENT SYSTEM|\n";
  cout << "\t\t\t\t    ---------------------------\n";
  cout << "\n\n";
  cout << "\t\t\t\t";
}

void menuPatient() {
  int input;
  Patient p;
  system("cls");
  title();
  cout << " 1. Enter new Records Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 2. Shows all Records Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 3. Delete Records Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 4. Search and view Records Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 5. Add Medical\n\n";
  cout << "\t\t\t\t";
  cout << " 6. Shows Medical Patient\n\n";
  cout << "\t\t\t\t";
  cout << " 7. Back select Patient/Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 0. Exit\n\n";
  cout << "\t\t\t\t";
  cout << "Choose options:[1/2/3/4/5/6/7/0]:";
  fflush(stdin);
  cin >> input;
  switch (input) {
  case 1: {
    system("cls");
    p.addRecord();
  } break;

  case 2: {
    system("cls");
    p.displayRecord();
    getchar();
  } break;

  case 3: {
    system("cls");
    p.deleteRecord();
  } break;

  case 4: {
    system("cls");
    p.searchRecord();
  } break;
  case 5: {
    system("cls");
    p.addMedical();
  } break;
  case 6: {
    system("cls");
    displayMedical();
  }
  case 7: {
    system("cls");
    select();
  } break;
  case 0: {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    fflush(stdin);
    cout << "\t\t\t\t";
    cout << "by nguyen tuong hy";
    cout << "\n\n\n\n";
    exit(0);
  } break;

  default: {
    fflush(stdin);
    cout << "\n\n\n";
    cout << "\t\t\t\t";
    cout << "      Invalid input!";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Press Enter to choose again...";
    getchar();
    menuPatient();
  }
  }
}

void menuDoctor() {
  int input;
  Doctor d;
  system("cls");
  title();
  cout << " 1. Enter new Records Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 2. Shows all Records  Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 3. Delete Records Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 4. Search and view Records Doctor\n\n";
  cout << "\t\t\t\t";
  cout << " 5. Exit\n\n";
  cout << "\t\t\t\t";
  cout << "Choose options:[1/2/3/4/5]:";
  fflush(stdin);
  cin >> input;
  switch (input) {
  case 1: {
    system("cls");
    d.addRecord();
  } break;

  case 2: {
    system("cls");
    d.displayRecord();
    getchar();
  } break;
  case 3: {
    system("cls");
    d.deleteRecord();
  } break;
  case 4: {
    system("cls");
    d.searchRecord();
  } break;
  case 5: {
    system("cls");
    select();
    break;
  }
  case 0: {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    fflush(stdin);
    cout << "\t\t\t\t";
    cout << "by nguyen tuong hy";
    cout << "\n\n\n\n";
    exit(0);
  } break;
  default: {
    fflush(stdin);
    cout << "\n\n\n";
    cout << "\t\t\t\t";
    cout << "      Invalid input!";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Press Enter to choose again...";
    getchar();
    menuDoctor();
  }
  }
}
