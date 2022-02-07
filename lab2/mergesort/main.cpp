#include <iostream>
#include <vector>
using namespace std;
vector<int> merge (vector<int> left, vector<int> right) {
    vector<int> output;
    int pointer1 = 0, pointer2 = 0;

    while (pointer1 < left.size() && pointer2 < right.size()) {
        if (left[pointer1] <= right[pointer2]) {
            output.push_back(left[pointer1]);
            pointer1++;
        } else {
            output.push_back(right[pointer2++]);
        }
    }

    for(; pointer1 < left.size(); pointer1++)
        output.push_back(left[pointer1]);

    for(; pointer2 < right.size(); pointer2++)
        output.push_back(right[pointer2]);

    return output;
}

vector<int> merge_sort (vector<int> input) {
    if (input.size() <= 1)
        return input;

    vector<int> left, right;
    for(int i=0; i < input.size() / 2; i++)
        left.push_back(input[i]);
    for(int i = input.size() / 2; i < input.size(); i++)
        right.push_back(input[i]);
    return merge(merge_sort(left), merge_sort(right));
}

int main () {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    input = merge_sort(input);
    for (int i = 0; i < N; i++) {
        cout <<  input[i] << " ";
    }
    return 0;
}
