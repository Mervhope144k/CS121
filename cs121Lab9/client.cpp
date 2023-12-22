#include "Employee.h"

int main() {
    Employee employ1, employ2, employ3;

    // Initialize three employees
    for (int i = 0; i < 3; ++i) {
        cout << "Enter employee " << i + 1 << " details:" << endl;
        cout << "First Name: ";
        cin >> employ1.f_name;
        cout << "Last Name: ";
        cin >> employ1.l_name;
        cout << "Gender (m/f): ";
        cin >> employ1.gender;
        cout << "ID Number: ";
        cin >> employ1.id_num;
        cout << "Pay Rate: ";
        cin >> employ1.pay_rate;
        cout << "Hours Worked: ";
        cin >> employ1.hrs_worked;

        // Print employee details with salutation and weekly gross pay
        string salutation = getSalutation(employ1);
        double gross_pay = calculateWeeklyGrossPay(employ1);
        cout << salutation << employ1.f_name << "'s weekly gross pay: $" << gross_pay << endl;
    }

    return 0;
}