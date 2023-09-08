//// Fig. 9.1: Time.h
//// include guard: prevent multiple inclusions of header
//
//#ifndef TIME_H
//#define TIME_H
//#include <string>
//
//class Time {
//public:
//    void setTime(int, int, int); // set hour, minute and second
//    std::string toUniversalString() const; // 24-hour time format string
//    std::string toStandardString() const; // 12-hour time format string
//private:
//    unsigned int hour{ 0 };  // 0 - 23 (24-hour clock format)
//    unsigned int minute{ 0 }; // 0 - 59
//    unsigned int second{ 0 }; // 0 - 59
//};
//
//#endif
//// Fig. 9.2: Time.cpp
//#include <iomanip>   // for setw and setfill stream manipulators
//#include <stdexcept> // for invalid_argument exception class
//#include <sstream>   // for ostringstream class
//#include <string>
//#include "Time.h"   // include definition of class Time from Time.h
//using namespace std;
//
//void Time::setTime(int h, int m, int s) {
//    // validate hour, minute and second
//    if ((h >=0 && h <24) && (m >=0 && m <60) && (s >=0 && s <60)) {
//        hour = h;
//        minute = m;
//        second = s;
//    }
//    else {
//        throw invalid_argument("hour, minute and/or second was out of range");
//    }
//}
//// return Time as a string in universal-time format (HH:MM:SS)
//string Time::toUniversalString() const {
//    ostringstream output;
//
//    output << setfill('0') << setw(2) << hour << ":"
//           << setw(2) << minute << ":" << setw(2) << second;
//    return output.str();         // returns the formatted string
//}
//
//// return Time as string in standard-time format (HH:MM:SS AM or PM)
//string Time::toStandardString() const {
//    ostringstream output;
//    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
//           << setfill('0') << setw(2) << minute << ":" << setw(2)
//           << second <<(hour < 12 ? " AM" : " PM");
//    return output.str(); // returns the formatted string
//}
//
//#include <iostream>
//#include <stdexcept> // invalid_argument exception class
//#include "Time.h"
//using namespace std;
//
//// displays a Time in 24-hour and 12-hour formats
//void displayTime(const string& message, const Time& time) {
//    cout << message << "\nUniversal time: " << time.toUniversalString()
//         << "\nStandard time: " << time.toStandardString() << "\n\n";
//}
//
//int main() {
//    Time t; // instantiate object t of class Time
//    displayTime("Initial time:", t); // display t's initial value
//    t.setTime(13, 27, 6); // change time
//    displayTime("After setTime:", t); // display t's new value
//
//    try {// attempt to set the time with invalid values
//        t.setTime(99, 99, 99); // all values out of range
//    }
//    catch (invalid_argument& e) {
//        cout << "Exception: " << e.what() << "\n\n";
//    }
//
//    // display t's value after attempting to set an invalid time
//    displayTime("After attempting to set an invalid time:", t);
//}



//
//
//// CreateAndDestroy class definition.
//#include <string>
//
//#ifndef CREATE_H
//#define CREATE_H
//
//class CreateAndDestroy {
//public:
//    CreateAndDestroy(int, std::string); // constructor
//    ~CreateAndDestroy(); // destructor
//
//private:
//    int objectID; // ID number for object
//    std::string message; // message describing object
//};
//
//#endif
//
//#include <iostream>
////#include "CreateAndDestroy.h“   // include CreateAndDestroy class definition
//using namespace std;
//
//// constructor sets object's ID number and descriptive message
//CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
//        : objectID{ID}, message{messageString} {
//    cout << "Object " << objectID << " constructor runs " << message << endl;
//}
//
//// destructor
//CreateAndDestroy::~CreateAndDestroy() {
//    cout << (objectID == 1 || objectID == 6 ? "\n" : "");
//    cout << "Object " << objectID << " destructor runs " << message << endl;
//}
//
//#include <iostream>
////#include "CreateAndDestroy.h"  // include CreateAndDestroy class definition
//using namespace std;
//
//void create(); // prototype
//CreateAndDestroy first{1, "(global before main)"}; // global object
//
//int main() {
//    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
//    CreateAndDestroy second{2, "(local in main)"};
//    static CreateAndDestroy third{3, "(local static in main)"};
//
//    create(); // call function to create objects
//    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
//    CreateAndDestroy fourth{4, "(local in main)"};
//    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
//}
//
//void create() {
//    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
//    CreateAndDestroy fifth{5, "(local in create)"};
//    static CreateAndDestroy sixth{6, "(local static in create)"};
//    CreateAndDestroy seventh{7, "(local in create)"};
//    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
//}




#include <iostream>

using namespace std;

class Phone {
public:
    Phone(string brand="Unknown", int price=1'000'000)
            : phoneBrand(brand), phonePrice(price) {}
    void printPhoneInfo() {
        cout << "Phone brand: " << phoneBrand << endl;
        cout << "Price: " << phonePrice << endl << endl;
    }
private:
    string phoneBrand;
    int phonePrice;
};


int main(){
    Phone p1("nokia",400000);
    Phone p2("ip");
    Phone p3;
    p1.printPhoneInfo();
    p2.printPhoneInfo();
    p3.printPhoneInfo();
}

