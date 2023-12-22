#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
struct Employee {
    string f_name;
    string l_name;
    char gender; // 'f' or 'm'
    string id_num;
    double pay_rate;
    double hrs_worked;
    friend ostream& operator<<(ostream& outs, const Employee& emp) {
        outs << emp.f_name << " " << emp.l_name << " " << endl;
        return outs;
    }
    friend istream& operator>>(istream& ins, Employee& emp) {
        ins >> emp.f_name >> emp.l_name >> emp.gender;
        return ins;
    }
    Employee& operator=(const Employee& init) {
        if (this == &init)
            return *this;
        f_name = init.f_name;
        l_name = init.l_name;
        gender = init.gender;
        id_num = init.id_num;
        pay_rate = init.pay_rate;
        hrs_worked = init.hrs_worked;

        return *this;
    }
};
double calculateWeeklyGrossPay(Employee emp);
string getSalutation(Employee emp);
#endif
