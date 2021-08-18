using namespace std;

const int NOSTUDENTS = 3;
struct dateType {
  int month;
  int day;
  int year;
};

struct studentType {
  string firstName;
  string middleName;
  string lastName;
  dateType registrationDate;
  dateType birthDate;
  double gpa;
};

void processFile(ifstream&, studentType[]);
void outputData(const studentType[]);
