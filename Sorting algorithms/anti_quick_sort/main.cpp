#include <iostream>
#include <vector>
using namespace std;
int main() {
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; i++) {
        array[i] = i + 1;
    }
    for (int i = 1; i < N; i++) {
        swap(array[i], array[i/2]);
    }
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    return 0;
}

