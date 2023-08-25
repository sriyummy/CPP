/*Write a program to create a structure to store the information of n number of Employees.
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%.
Display the information of employees with gross salary. Use array of structure.  */

#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    int emp_ID;
    string name, dsgn;
    float bs, hra_pc, da_pc;
};

float calcHRA(float pctg, float basic_salary)
{
    float HRA = (pctg / 100) * basic_salary;
    return HRA;
}

float calcDA(float pctg, float basic_salary)
{
    float DA = (pctg / 100) * basic_salary;
    return DA;
}

int main()
{
    int n, j;
    float hra, da, gs;

    cout << "Enter the number of employees you have to take the data of: " << endl;
    cin >> n;
    Employee emp[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee " << i + 1 << "'s details: " << endl;

        cout << "\nEmployee ID: " << endl;
        cin >> emp[i].emp_ID;
        cout << "Name: " << endl;
        cin >> emp[i].name;
        cout << "Designation: " << endl;
        cin >> emp[i].dsgn;
        cout << "Basic Salary: " << endl;
        cin >> emp[i].bs;
        cout << "HRA %: " << endl;
        cin >> emp[i].hra_pc;
        cout << "DA %: " << endl;
        cin >> emp[i].da_pc;
        cout << "\n\n\n" << endl;
    }

    cout << "Employee Details with Gross Salary: " << endl;
    for (j = 0; j < n; j++)
    {
        cout << "\nName: " << emp[j].name << endl;
        cout << "Designation: " << emp[j].dsgn << endl;
        cout << "Employee ID: " << emp[j].emp_ID << endl;
        cout << "Basic Salary: " << emp[j].bs << endl;
        hra = calcHRA(emp[j].hra_pc, emp[j].bs);
        cout << "HRA: " << hra << endl;
        da = calcDA(emp[j].da_pc, emp[j].bs);
        cout << "DA: " << da << endl;
        cout << "Gross Salary: " << emp[j].bs + hra + da << endl;
        cout << "\n\n\n" << endl;
    }

    return 0;
}