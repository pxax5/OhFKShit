#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double loan, rate, pay;
    int year = 1;

    cout << "Enter initial loan: ";
    cin >> loan;
    cout << "Enter interest rate per year (%): ";
    cin >> rate;
    cout << "Enter amount you can pay per year: ";
    cin >> pay;

    cout << fixed << setprecision(2);

    // Header (ต้องตรง)
    cout << left
         << setw(13) << "EndOfYear#"
         << setw(13) << "PrevBalance"
         << setw(13) << "Interest"
         << setw(13) << "Total"
         << setw(13) << "Payment"
         << setw(12) << "NewBalance"
         << endl;

    while (loan > 0) {
        double prevBalance = loan;
        double interest = prevBalance * rate / 100.0;
        double total = prevBalance + interest;

        double payment = (total <= pay) ? total : pay;
        double newBalance = total - payment;

        cout << left
             << setw(13) << year
             << setw(13) << prevBalance
             << setw(13) << interest
             << setw(13) << total
             << setw(13) << payment
             << setw(12) << newBalance
             << endl;

        loan = newBalance;
        year++;
    }

    return 0;
}
