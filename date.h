//
//  Date.h
//  채점퀴즈
//
//  Created by 김승주 on 2023/09/19.
//

#ifndef Date_h
#define Date_h
class Date{
private:
    int month;
    int year;
    int day;
    int checkday(int) const;
public:
    static const int monthperyear=12;
    explicit Date (int=1,int=1,int=1900);
    void print() const;
    ~Date();
};

#endif /* Date_h */
