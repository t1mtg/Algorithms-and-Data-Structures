#include <iostream>

using namespace std;

int main ()
{
    int a, b;
    freopen("aplusbin.txt", "r", stdin);
    freopen("aplusbout.txt", "w", stdout);
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}