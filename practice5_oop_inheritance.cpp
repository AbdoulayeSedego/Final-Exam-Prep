#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    // Constructor to initialize all members
    Employee(string empName, int empId, double salary) {
        name = empName;
        id = empId;
        baseSalary = salary;
    }

    // Virtual function for polymorphism
    virtual double calculatePay() {
        return baseSalary;
    }

    // Display employee details
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Base Salary: $" << baseSalary << endl;
    }
};

// Derived class: HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    // Constructor calls base constructor + initializes new members
    HourlyEmployee(string empName, int empId, double salary, double hours, double rate)
        : Employee(empName, empId, salary) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    // Override calculatePay
    double calculatePay() override {
        return hoursWorked * hourlyRate;
    }

    // Override displayInfo to include additional details
    void displayInfo() override {
        cout << "--- Hourly Employee ---" << endl;
        Employee::displayInfo();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
    }
};

// Derived class: SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double bonus;

public:
    // Constructor calls base constructor + initializes bonus
    SalariedEmployee(string empName, int empId, double salary, double empBonus)
        : Employee(empName, empId, salary) {
        bonus = empBonus;
    }

    // Override calculatePay
    double calculatePay() override {
        return baseSalary + bonus;
    }

    // Override displayInfo to include additional details
    void displayInfo() override {
        cout << "--- Salaried Employee ---" << endl;
        Employee::displayInfo();
        cout << "Bonus: $" << bonus << endl;
    }
};

// Derived class: CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;

public:
    // Constructor calls base constructor + initializes commission details
    CommissionEmployee(string empName, int empId, double salary, double sales, double rate)
        : Employee(empName, empId, salary) {
        salesAmount = sales;
        commissionRate = rate;
    }

    // Override calculatePay
    double calculatePay() override {
        return baseSalary + (salesAmount * commissionRate);
    }

    // Override displayInfo to include additional details
    void displayInfo() override {
        cout << "--- Commission Employee ---" << endl;
        Employee::displayInfo();
        cout << "Sales Amount: $" << salesAmount << endl;
        cout << "Commission Rate: " << (commissionRate * 100) << "%" << endl;
    }
};

int main() {
    cout << "=== Employee Management System ===" << endl << endl;

    // Create one object of each employee type
    HourlyEmployee hourly("Alice Johnson", 101, 0, 40, 25.00);
    SalariedEmployee salaried("Bob Williams", 102, 5000, 1000);
    CommissionEmployee commission("Carol Davis", 103, 2000, 15000, 0.10);

    // Display info and calculated pay for Hourly Employee
    hourly.displayInfo();
    cout << "Calculated Pay: $" << hourly.calculatePay() << endl;
    cout << endl;

    // Display info and calculated pay for Salaried Employee
    salaried.displayInfo();
    cout << "Calculated Pay: $" << salaried.calculatePay() << endl;
    cout << endl;

    // Display info and calculated pay for Commission Employee
    commission.displayInfo();
    cout << "Calculated Pay: $" << commission.calculatePay() << endl;
    cout << endl;

    // Demonstrate polymorphism with base class pointers
    cout << "=== Polymorphism Demo (using base class pointers) ===" << endl << endl;

    Employee* employees[3];
    employees[0] = &hourly;
    employees[1] = &salaried;
    employees[2] = &commission;

    for (int i = 0; i < 3; i++) {
        employees[i]->displayInfo();
        cout << "Calculated Pay: $" << employees[i]->calculatePay() << endl;
        cout << endl;
    }

    return 0;
}
