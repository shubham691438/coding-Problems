#include <iostream>
#include <string>

using namespace std;
int countDigits(const string& str) {

    int count = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    string input ;
    cin>>input;
    int result = countDigits(input);
    cout  << result << endl;
    return 0;
}