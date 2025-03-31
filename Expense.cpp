#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class input {
protected:
    char ch;
    string* isource;
    double* inarr;
    string* idate;
    string* esource;
    double* exarr;
    string* edate;
    int income, expense;
    int incomeCapacity, expenseCapacity;

public:
    input() {
        income = expense = 0;
        incomeCapacity = expenseCapacity = 5;  // Initial allocation size

        isource = new string[incomeCapacity];
        inarr = new double[incomeCapacity];
        idate = new string[incomeCapacity];

        esource = new string[expenseCapacity];
        exarr = new double[expenseCapacity];
        edate = new string[expenseCapacity];
    }

    ~input() {
        delete[] isource;
        delete[] inarr;
        delete[] idate;
        delete[] esource;
        delete[] exarr;
        delete[] edate;
    }

    void changeincome() {
        incomeCapacity *= 2;
        string* new_isource = new string[incomeCapacity];
        double* new_inarr = new double[incomeCapacity];
        string* new_idate = new string[incomeCapacity];

        for (int i = 0; i < income; i++) {
            new_isource[i] = isource[i];
            new_inarr[i] = inarr[i];
            new_idate[i] = idate[i];
        }

        delete[] isource;
        delete[] inarr;
        delete[] idate;

        isource = new_isource;
        inarr = new_inarr;
        idate = new_idate;
    }

    void changeexpense() {
        expenseCapacity *= 2;
        string* new_esource = new string[expenseCapacity];
        double* new_exarr = new double[expenseCapacity];
        string* new_edate = new string[expenseCapacity];

        for (int i = 0; i < expense; i++) {
            new_esource[i] = esource[i];
            new_exarr[i] = exarr[i];
            new_edate[i] = edate[i];
        }

        delete[] esource;
        delete[] exarr;
        delete[] edate;

        esource = new_esource;
        exarr = new_exarr;
        edate = new_edate;
    }

    void getincome() {
        double sum = 0;
        cout << "Want to enter income details? (Y/N): ";
        cin >> ch;

        while ((ch == 'y' || ch == 'Y')) {
            if (income == incomeCapacity) {
                changeincome();
            }

            cout << "Enter source of income: ";
            cin >> isource[income];
            cout << "Enter income amount: ";
            cin >> inarr[income];
            cout << "Enter date of income: ";
            cin >> idate[income];

            sum += inarr[income];
            income++;
            cout << "Total Income so far: " << sum << endl;

            cout << "Want to enter more details? (Y/N): ";
            cin >> ch;
        }
    }

    void getexpense() {
        double sum = 0;
        cout << "Want to enter expense details? (Y/N): ";
        cin >> ch;

        while ((ch == 'y' || ch == 'Y')) {
            if (expense == expenseCapacity) {
                changeexpense();
            }

            cout << "Enter source of expense: ";
            cin >> esource[expense];
            cout << "Enter amount spent: ";
            cin >> exarr[expense];
            cout << "Enter date of expense: ";
            cin >> edate[expense];

            sum += exarr[expense];
            expense++;
            cout << "Total Expense so far: " << sum << endl;

            cout << "Want to enter more details? (Y/N): ";
            cin >> ch;
        }
    }
};

class view : public input {
public:
    void viewincome() {
        cout << "\nINCOME DETAILS\n";
        cout << left << setw(12) << "DATE" << setw(15) << "SOURCE" << setw(10) << "INCOME" << endl;
        for (int k = 0; k < income; k++) {
            cout << left << setw(12) << idate[k] << setw(15) << isource[k] << setw(10) << inarr[k] << endl;
        }
    }

    void viewexpense() {
        cout << "\nEXPENSE DETAILS\n";
        cout << left << setw(12) << "DATE" << setw(15) << "SOURCE" << setw(10) << "EXPENSE" << endl;
        for (int k = 0; k < expense; k++) {
            cout << left << setw(12) << edate[k] << setw(15) << esource[k] << setw(10) << exarr[k] << endl;
        }
    }
};

int main() {
    int choice;
    view obj;

    cout << "\n----- EXPENSE TRACKER -----\n";
    while (true) {
        cout << "\n--- MENU ---\n1. Add Income\n2. Add Expense\n3. View Income\n4. View Expense\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.getincome();
                break;
            case 2:
                obj.getexpense();
                break;
            case 3:
                obj.viewincome();
                break;
            case 4:
                obj.viewexpense();
                break;
            case 5:
                cout << "Closing the application.\n";
                return 0;
            default:
                cout << "Invalid Input. Please enter a valid option from the menu.\n";
        }
    }
    return 0;
}
