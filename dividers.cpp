#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else {
        int result = 2;
        for (long long int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                if (n / i == i) result++;
                else result += 2;
            }
        }
        cout << result;
    }

    return 0;
}
