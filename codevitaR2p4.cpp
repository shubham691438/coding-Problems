#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

time_t parseDate(const string& dateStr) {
    struct tm tm = {0, 0, 0, 0, 0, 0, 0, 0, 0};  
    istringstream ss(dateStr);
    ss >> get_time(&tm, "%d-%b-%Y");
    return mktime(&tm);
}

double calculateXIRR(const vector<pair<double, time_t>>& cashflows) {
    double irr = 0.01; 
    const double epsilon = 0.00001;
    const int maxIterations = 1000;

    for (int i = 0; i < maxIterations; ++i) {
        double sum = 0.0;
        double sumDerivative = 0.0;

        for (const auto& cf : cashflows) {
            double daysDiff = difftime(cf.second, cashflows.front().second) / (60 * 60 * 24);
            sum += cf.first / pow(1 + irr, daysDiff / 365.0);
            sumDerivative -= (daysDiff / 365.0) * cf.first / pow(1 + irr, (daysDiff / 365.0) + 1);
        }

        double newIRR = irr - (sum / sumDerivative);

        if (fabs(newIRR - irr) < epsilon) {
            return newIRR * 100.0; 
        }

        irr = newIRR;
    }

    return numeric_limits<double>::quiet_NaN();
}

int main() {
    int N;
    cin >> N;

    vector<pair<double, time_t>> cashflows;

    for (int i = 0; i < N; ++i) {
        double payment;
        string dateStr;
        cin >> payment >> dateStr;

        time_t date = parseDate(dateStr);
        cashflows.emplace_back(payment, date);
    }

    double xirr = calculateXIRR(cashflows);

    if (isnan(xirr)) {
        cout << "Failed to converge. Please check your input." << endl;
    } else {
        cout << fixed << setprecision(2) << xirr << endl;
    }

    return 0;
}
