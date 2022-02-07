#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector <int> &array, int low, int high, int k) {
    int i = low;
    int j = high;
    int pivot = array[(i+j) / 2];
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(array[i++], array[j--]);
        }
    }
    if ((k-1 <= j) && (low <= k - 1)){
        return quick_sort(array,low,j,k);
    }
    if ((i <= k - 1) && (k - 1 <= high)) {
        return quick_sort(array,i,high,k);

    }

}


int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int N, k, A, B, C, a1, a2;
    cin >> N >> k;
    vector<int> array(N);
    cin >> A >> B >> C >> a1 >> a2;
    array[0] = a1;
    array[1] = a2;
    for (int i = 2; i < N; i++) {
        array[i] = A * array[i-2] + B * array[i-1] + C;
    }
    quick_sort(array, 0, N-1, k);
    cout << array[k-1];
    return 0;
}