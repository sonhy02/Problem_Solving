#include <bits/stdc++.h>
//#include <string>
//
//class Employee {
//public:
//    Employee(const std::string &, const std::string &, const std::string &);
//
//    virtual ~Employee() = default;         // compiler generates virtual destructor
//    void setFirstName(const std::string &); // set first name
//    std::string getFirstName() const;      // return first name
//    void setLastName(const std::string &);  // set last name
//    std::string getLastName() const;       // return last name
//    void setSocialSecurityNumber(const std::string &); // set SSN
//    std::string getSocialSecurityNumber() const;      // return SSN
//
//    virtual double earnings() const = 0;   // pure virtual
//    virtual std::string toString() const;  // virtual
//private:
//    std::string firstName;
//    std::string lastName;
//    std::string socialSecurityNumber;
//};
//
//// Fig. 12.10: Employee.cpp
//#include <sstream>
//
//using namespace std;
//
//Employee::Employee(const string &first, const string &last, const string &ssn)
//        : firstName(first), lastName(last), socialSecurityNumber(ssn) {}
//
//void Employee::setFirstName(const string &first) { firstName = first; }
//
//string Employee::getFirstName() const { return firstName; }
//
//void Employee::setLastName(const string &last) { lastName = last; }
//
//string Employee::getLastName() const { return lastName; }
//
//void Employee::setSocialSecurityNumber(const string &ssn) {
//    socialSecurityNumber = ssn; // should validate
//}
//
//string Employee::getSocialSecurityNumber() const {
//    return socialSecurityNumber;
//}
//
//string Employee::toString() const {
//    return getFirstName() + " "s + getLastName() +
//           "\nsocial security number: "s + getSocialSecurityNumber();
//}
//
//
//#include <string>              // C++ standard string class
//
//
//class SalariedEmployee : public Employee {
//public:
//    SalariedEmployee(const std::string &, const std::string &,
//                     const std::string &, double = 0.0);
//
//    virtual ~SalariedEmployee() = default;
//
//    void setWeeklySalary(double); // set weekly salary
//    double getWeeklySalary() const; // return weekly salary
//    virtual double earnings() const override; // calculate earnings
//    virtual std::string toString() const override;
//
//private:
//    double weeklySalary; // salary per week
//};
//
//#include <iomanip>
//#include <stdexcept>
//#include <sstream>
//
//using namespace std;
//
//SalariedEmployee::SalariedEmployee(const string &first,
//                                   const string &last, const string &ssn, double salary)
//        : Employee(first, last, ssn) { setWeeklySalary(salary); }
//
//void SalariedEmployee::setWeeklySalary(double salary) {
//    if (salary < 0.0) throw invalid_argument("Weekly salary must be >= 0.0");
//    weeklySalary = salary;
//}
//
//double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }
//
//double SalariedEmployee::earnings() const { return getWeeklySalary(); }
//
//string SalariedEmployee::toString() const {
//    ostringstream output;
//    output << fixed << setprecision(2);
//    output << "salaried employee: "
//           << Employee::toString() // reuse abstract base-class function
//           << "\nweekly salary: " << getWeeklySalary();
//    return output.str();
//}
//
//
//#include <string>     // C++ standard string class
//
//
//class CommissionEmployee : public Employee {
//public:
//    CommissionEmployee(const std::string &, const std::string &,
//                       const std::string &, double = 0.0, double = 0.0);
//
//    virtual ~CommissionEmployee() = default; // virtual destructor
//
//    void setCommissionRate(double);   // set commission rate
//    double getCommissionRate() const; // return commission rate
//
//    void setGrossSales(double);        // set gross sales amount
//    double getGrossSales() const;       // return gross sales amount
//
//    virtual double earnings() const override; // calculate earnings
//    virtual std::string toString() const override;
//
//private:
//    double grossSales;     // gross weekly sales
//    double commissionRate; // commission percentage
//};
//
//
//// Fig. 12.14: CommissionEmployee.cpp
//#include <iomanip>
//#include <stdexcept>
//#include <sstream>
//
//using namespace std;
//
//CommissionEmployee::CommissionEmployee(const string &first,
//                                       const string &last, const string &ssn, double sales, double rate)
//        : Employee(first, last, ssn) {
//    setGrossSales(sales);
//    setCommissionRate(rate);
//}
//
//void CommissionEmployee::setGrossSales(double sales) {
//    if (sales < 0.0) throw invalid_argument("Gross sales must be >= 0.0");
//    grossSales = sales;
//}
//
//double CommissionEmployee::getGrossSales() const { return grossSales; }
//
//void CommissionEmployee::setCommissionRate(double rate) {
//    if (rate <= 0.0 || rate > 1.0)
//        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
//    commissionRate = rate;
//}
//
//double CommissionEmployee::getCommissionRate() const { return commissionRate; }
//
//double CommissionEmployee::earnings() const {
//    return getCommissionRate() * getGrossSales();
//}
//
//string CommissionEmployee::toString() const {
//    ostringstream output;
//    output << fixed << setprecision(2);
//    output << "commission employee: " << Employee::toString() << "\ngross sales: "
//           << getGrossSales() << "; commission rate: " << getCommissionRate();
//    return output.str();
//}
//
//
//#include <string> // C++ standard string class
//
//class BasePlusCommissionEmployee : public CommissionEmployee {
//public:
//    BasePlusCommissionEmployee(const std::string &, const std::string &,
//                               const std::string &, double = 0.0, double = 0.0, double = 0.0);
//
//    virtual ~BasePlusCommissionEmployee() = default; // virtual destructor
//
//    void setBaseSalary(double); // set base salary
//    double getBaseSalary() const; // return base salary
//    virtual double earnings() const override; // calculate earnings
//    virtual std::string toString() const override;
//
//private:
//    double baseSalary; // base salary per week
//};
//
//
//// Fig. 12.16: BasePlusCommissionEmployee.cpp
//#include <iomanip>
//#include <stdexcept>
//#include <sstream>
//
//using namespace std;
//
//BasePlusCommissionEmployee::BasePlusCommissionEmployee(
//        const string &first, const string &last, const string &ssn,
//        double sales, double rate, double salary)
//        : CommissionEmployee(first, last, ssn, sales, rate) {
//    setBaseSalary(salary);
//}
//
//void BasePlusCommissionEmployee::setBaseSalary(double salary) {
//    if (salary < 0.0) throw invalid_argument("Salary must be >= 0.0");
//    baseSalary = salary;
//}
//
//double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }
//
//double BasePlusCommissionEmployee::earnings() const {
//    return getBaseSalary() + CommissionEmployee::earnings();
//}
//
//string BasePlusCommissionEmployee::toString() const {
//    ostringstream output;
//    output << fixed << setprecision(2);
//    output << "base-salaried " << CommissionEmployee::toString() << "; base salary: "
//           << getBaseSalary();
//    return output.str();
//}
//
//#include <iostream>
//#include <iomanip>
//#include <vector>
//
//using namespace std;
//
//void virtualViaPointer(const Employee* const); // prototype
//void virtualViaReference(const Employee&); // prototype
//
//int main() {
//    cout << fixed << setprecision(2); // set floating-point formatting
//    SalariedEmployee salariedEmployee{ "John", "Smith", "111-11-1111", 800 };
//    CommissionEmployee commissionEmployee{"Sue", "Jones", "333-33-3333", 10000, .06 };
//    BasePlusCommissionEmployee basePlusCommissionEmployee{
//            "Bob", "Lewis", "444-44-4444", 5000, .04, 300 };
//
//    cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
//         << salariedEmployee.toString()
//         << "\nearned $" << salariedEmployee.earnings() << "\n\n"
//         << commissionEmployee.toString()
//         << "\nearned $" << commissionEmployee.earnings() << "\n\n"
//         << basePlusCommissionEmployee.toString()
//         << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";
//
//
//    vector<Employee*> employees{ &salariedEmployee, &commissionEmployee,
//                                 &basePlusCommissionEmployee };
//
//    cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";
//    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";
//    for (const Employee* employeePtr : employees) {
//        virtualViaPointer(employeePtr);
//    }
//
//    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";
//    for (const Employee* employeePtr : employees) {
//        virtualViaReference(*employeePtr);
//    }
//}  // end main
//
//void virtualViaPointer(const Employee* const baseClassPtr) {
//    cout << baseClassPtr->toString()
//         << "\nearned $" <<  baseClassPtr->earnings() << "\n\n";
//}
//
//void virtualViaReference(const Employee & baseClassRef) {
//    cout << baseClassRef.toString()
//         << "\nearned $" << baseClassRef.earnings() << "\n\n";
//}

using namespace std;

class Base {
public:
    Base(const string& s)
            : name(s) {
        cout << "Base constructor for "
             << s << endl;
    }
    virtual void what() {
        cout << name
             << ": base class object" << endl;
    }
protected:
    string name;
};

class Derived : public Base {
public:
    Derived(const string& sname)
            : Base(sname) {
        cout << "Derived constructor for "
             << sname << endl;
    }
    void what() {
        cout << name
             << ": derived class object"<< endl;
    }
};


int main() {

    Base base{ "B1" };
    Derived derived{"D1"};
    Base* basePtr = &derived;
    basePtr -> what();


}
