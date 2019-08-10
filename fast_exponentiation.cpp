#include <iostream>
#include <cmath>
using namespace std;

long long int fe(long long int a, long long int b, long long int m) {
    long long int r = 1;
    while (b) {
        if (b & 1) {
            r *= a;
            r %= m;
        }
        a *= a;
        a %= m;
        b >>=1;
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    long long int m = pow(10,9) + 7;
    long long int a = fe(27, n, m);
    long long int b = fe(7, n, m);

    if (a > b) {
        cout << a - b;
    } else {
        cout << m + (a - b);
    }

    return 0;
}
