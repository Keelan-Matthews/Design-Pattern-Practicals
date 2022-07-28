#include <iostream>
using namespace std;

void recursive(int n) {
    cout << n << ", ";

    if (n <= 0) return;
    recursive(n-7);

    cout << n << ", ";
}

int A(int m, int n) {
    if (m == 0) 
        return n + 1;
    else if ((m > 0) && (n == 0)) 
        return A(m - 1, 1); 
    else if ((m > 0) && (n > 0))
        return A(m - 1, A(m, n - 1));

    return 0;
}

int main() {
    recursive(20);
    cout << endl;

    cout << A(4,2) << endl;
    return 0;
}