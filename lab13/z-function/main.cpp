#include <iostream>
#include <vector>
using namespace std;

vector<int> zFunction(string &str) {
    size_t strLen = str.length();
    vector<int> zArr(strLen);
    int left = 0, right = 0;

    for (int i = 1; i < strLen; i++) {
        zArr[i] = min(right - i, zArr[i - left]);
        zArr[i] = max(0, zArr[i]);

        while ((i + zArr[i] < strLen) && (str[zArr[i]] == str[i + zArr[i]])) {
            zArr[i]++;
        }

        if (i + zArr[i] > right) {
            left = i;
            right = i + zArr[i];
        }
    }

    return zArr;
}


int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    string p, t;
    cin >> p >> t;

    vector<long long> answer;
    string pString = p + '#' + t;
    vector<int> z = zFunction(pString);

    for (size_t i = p.length() + 1; i < t.length() + 2; i++) {
        if (z[i] == p.length()) {
            answer.push_back(i - p.length());
        }
    }
    cout << answer.size() << endl;
    for (auto &i : answer) {
        cout << i << " ";
    }

    return 0;
}

