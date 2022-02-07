#include <iostream>
using namespace std;
struct Tree {
    int Data;
    int Left;
    int Right;
    int Parent;
} mass[200000];

bool flag = true;

bool check(int k, int min, int max) {
    if (mass[k].Data <= min || max <= mass[k].Data) {
        flag = 0;
    }
    if (mass[k].Left != 0) {
        check(mass[k].Left, min, mass[k].Data);
    }
    if (mass[k].Right != 0) {
        check(mass[k].Right, mass[k].Data, max);
    }
}

int main()
{
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> mass[i].Data >> mass[i].Left >> mass[i].Right;
        mass[mass[i].Left].Parent = i;
        mass[mass[i].Right].Parent = i;
    }
    check(1, INT_MIN, INT_MAX);
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}

