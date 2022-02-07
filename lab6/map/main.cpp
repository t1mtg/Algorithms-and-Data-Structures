#include <iostream>
#include <vector>
#include <string>
#define inp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int getHash(string key){
    int hash = 0;
    for (int i = 0; i < key.size(); i++) {
        hash = abs(5 * hash + key[i]) % 100001;
    }
    return hash;
}

int find(vector<pair<string, string>> &table, string &x) {
    for (int i = 0; i < table.size(); ++i) {
        if (x == table[i].first) {
            return i;
        }
    }
    return -1;
}

void Put(vector<vector<pair<string, string>>> &table, string &first, string &second) {
    int key = getHash(first);
    int value = find(table[key], first);
    if (!table[key].empty() && table[key][value].first == first) {
        table[key][value].second = second;
    }
    if (table[key].empty() || table[key][value].first != first) {
        table[key].push_back(make_pair(first, second));
    }
}

void Delete(vector<vector<pair<string, string>>> &table, string &first) {
    int key = getHash(first);
    int value = find(table[key], first);
    if (!table[key].empty() && table[key][value].first == first) {
        swap(table[key][value],table[key].back());
        table[key].pop_back();
    }
}

void Get(vector<vector<pair<string, string>>> &table, string &first) {
    int key = getHash(first);
    int value = find(table[key], first);
    if (!table[key].empty() && table[key][value].first == first) {
        cout << table[key][value].second << endl;
    } else {
        cout << "none" << endl;
    }
}

void Next(vector<vector<pair<string, string>>> &table, string &first) {

}
int main() {
    inp
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    vector<vector<pair<string, string>>> hash_table(100001);
    string instruction;
    while (cin >> instruction) {
        if (instruction == "put") {
            string first;
            string second;
            cin >> first >> second;
            Put(hash_table, first, second);
        } else if (instruction == "delete") {
            string first;
            cin >> first;
            Delete(hash_table, first);
        } else if (instruction == "get") {
            string first;
            cin >> first;
            Get(hash_table, first);
        }
    }
    return 0;
}