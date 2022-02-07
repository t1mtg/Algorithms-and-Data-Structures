#include <iostream>
using namespace std;
int size(int a[]) {
    int s = sizeof(a);
    return s;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << size(a);
    return 0;
}