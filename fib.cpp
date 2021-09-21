#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, first = 0, second = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << first << ", ";
            continue;
        }
        if(i == 2) {
            cout << second << ", ";
            continue;
        }
        nextTerm = first + second;
        first= second;
        second = nextTerm;
        
        cout << nextTerm << ", ";
    }
    return 0;
}