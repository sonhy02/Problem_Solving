#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Date {
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++();
    Date operator++(int);
    Date& operator+=(unsigned int);
    static bool leapYear(int);
    bool endOfMonth(int) const;
    unsigned int getyear() {
        return year;
    }
    unsigned int getmonth() {
        return month;
    }
    unsigned int getday() {
        return day;
    }

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const std::array<unsigned int, 13> days;
    void helpIncrement();
};



const array<unsigned int, 13> Date::days{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd, int yy) {
    if (mm >= 1 && mm <= 12) month = mm;
    else throw invalid_argument{ "Month must be 1-12" };

    if (yy >= 1900 && yy <= 2100) year = yy;
    else throw invalid_argument{ "Year must be >= 1900 and <= 2100" };

    //test for a leap year
    if ((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
        (dd >= 1 && dd <= days[mm]))  day = dd;
    else {
        throw invalid_argument{ "Day is out of range for current month and year" };
    }
}




Date& Date::operator++() {
    helpIncrement();
    return *this;
}


Date Date::operator++(int) {
    Date temp{ *this };
    helpIncrement();


    return temp;
}


Date& Date::operator+=(unsigned int additionalDays) {
    for (unsigned int i = 0; i < additionalDays; ++i) {
        helpIncrement();
    }
    return *this;
}




bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
}
bool Date::endOfMonth(int testDay) const {
    if (month == 2 && leapYear(year))
        return testDay == 29;
    else return testDay == days[month];
}
void Date::helpIncrement() {
    if (!endOfMonth(day))
        ++day;
    else {
        if (month < 12) {
            ++month;
            day = 1;
        }
        else {
            ++year;
            month = 1;
            day = 1;
        }
    }
}
ostream& operator<<(ostream& output, const Date& d) {

    output << d.month << '/' << d.day << "/" << d.year;
    return output;
}


istream& operator>>(istream& input, Date& d) {
    input >> setw(2) >> d.month;
    input.ignore();
    input >> setw(2) >> d.day;
    input.ignore();
    input >> setw(4) >> d.year;
    return input;
}


class Baby {
public:
    Baby(const std::string&, const Date&);
    void setName(string&);
    void setBirthDate(Date&);
    string getName() const;
    Date getBirthDate() const;
private:
    string name;
    Date birthDate;
};


bool compareName(const Baby& b1, const Baby& b2) {
    return b1.getName() < b2.getName();
}

int main() {
    cout << "Enter the number of newborn babies: ";
    int n;
    cin >> n;
    Date d0;
    Baby b0("", d0);
    vector<Baby> bVec(n,b0);
    for (int i = 0; i < n; i++) {
        string name;
        Date d1, d2, d3;
        cout << "\nEnter the baby name: ";
        cin.ignore(100,'\n');
        getline(cin, name);
        cout << "Enter the baby's birth date in the form mm/dd/yyyy: ";
        cin >> d1;
        bVec[i].setName(name);
        bVec[i].setBirthDate(d1);
        if(d1.getday() == 29&&d1.getmonth() == 2) {
            d3.setDate(d1.getmonth(), 28, d1.getyear() + 1);
        }
        else {
            d3.setDate(d1.getmonth(), d1.getday(), d1.getyear() + 1);
        }
        d2.setDate(3, 1, d1.getyear() + 7);
        cout << bVec[i].getName() << " born on " << bVec[i].getBirthDate();
        cout << "\n100th day: " << (bVec[i].getBirthDate() += 99);
        cout << "\nFirst birthday: " << d3;
        cout << "\nFirst school day: " << d2 << "\n";
    }
    cout << "\nNewborn babies in the alphabetical order of names: \n";
    sort(bVec.begin(), bVec.end(), compareName);
    for (int i = 0; i < n; i++) {
        cout << bVec[i].getName() << " (" << bVec[i].getBirthDate() << ")\n";
    }

}


Baby::Baby(const std::string& s, const Date& d) {
    name = s;
    birthDate = d;
}

void Baby::setName(string& s) {
    name = s;
}

void Baby::setBirthDate(Date& d) {
    birthDate = d;
}

string Baby::getName() const {
    return name;
}

Date Baby::getBirthDate() const {
    return birthDate;
}