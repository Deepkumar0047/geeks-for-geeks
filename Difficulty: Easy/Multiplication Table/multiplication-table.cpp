#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // code here
     for (int i = 1; i <= 10; i++) {
        cout << n * i;
            
        if (i < 10)
        cout << " ";
    }

    return 0;
}