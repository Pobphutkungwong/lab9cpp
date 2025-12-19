#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double loan, rate, amount;
    double prev, interest_amt, total, newbalance;
    

    cout << "Enter initial loan: ";
    cin >> loan;
    cout << "Enter interest rate per year (%): ";
    cin >> rate; // เก็บอัตราดอกเบี้ยแยกไว้
    cout << "Enter amount you can pay per year: ";
    cin >> amount;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    newbalance = loan;
    
    for (int i = 1; newbalance > 0; i++) {
        prev = newbalance;
        interest_amt = prev * (rate / 100.0);
        total = prev + interest_amt;

        double actual_payment = amount;
        if (total < amount) {
            actual_payment = total;
        }
        
        newbalance = total - actual_payment;

        cout << fixed << setprecision(2);
        cout << setw(13) << left << i;
        cout << setw(13) << left << prev;
        cout << setw(13) << left << interest_amt;
        cout << setw(13) << left << total;
        cout << setw(13) << left << actual_payment;
        cout << setw(13) << left << newbalance;
        cout << "\n";

        if (interest_amt >= amount && newbalance > 0) break;
    }

}