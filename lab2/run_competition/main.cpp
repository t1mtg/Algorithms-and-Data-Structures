#include <iostream>
#include <vector>
using namespace std;
struct sportsman {
    string country;
    string name;
};
vector<sportsman> merge (vector<sportsman> left, vector<sportsman> right) {
    vector<sportsman> output;
    int pointer1 = 0, pointer2 = 0;

    while (pointer1 < left.size() && pointer2 < right.size()) {
        if (left[pointer1].country <= right[pointer2].country) {
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

vector<sportsman> merge_sort (vector<sportsman> input) {
    if (input.size() <= 1)
        return input;

    vector<sportsman> left, right;
    for(int i=0; i < input.size() / 2; i++)
        left.push_back(input[i]);
    for(int i = input.size() / 2; i < input.size(); i++)
        right.push_back(input[i]);
    return merge(merge_sort(left), merge_sort(right));
}

int main () {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int N;
    cin >> N;
    vector<sportsman> input(N);
    for (int i = 0; i < N; i++) {
        string temp_country;
        string temp_name;
        cin >> temp_country >> temp_name;
        sportsman temp_struct;
        temp_struct.country = temp_country;
        temp_struct.name = temp_name;
        input[i] = temp_struct;
    }
    input = merge_sort(input);
    string curr_country;
    for (auto now : input) {
        if (now.country != curr_country) {
            cout << "=== " << now.country << " ===" << endl;
            curr_country = now.country;
        }
        cout << now.name << endl;
    }
    return 0;
}


