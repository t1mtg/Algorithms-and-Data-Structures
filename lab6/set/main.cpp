#include <iostream>
#include <vector>
#define inp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;


unsigned int getHash(int key){
    return abs(((abs(key)<<2)^abs(key)) % 1000001);
}


int find(vector<int> &table, int x) {
    for (int i = 0; i < table.size(); ++i) {
        if (x == table[i]) {
            return i;
        }
    }
    return -1;
}

void Insert(vector<vector<int>> &table, int x) {
    int key = getHash(x);
    int value = find(table[key], x);
    if (table[key].empty() || value == -1 || table[key][value] != x) {
        table[key].push_back(x);
    }
}

void Delete(vector<vector<int>> &table, int x) {
    int key = getHash(x);
    int value = find(table[key], x);
    if (!table[key].empty() && table[key][value] == x) {
        swap(table[key][value],table[key].back());
        table[key].pop_back();
    }
}


void Exists(vector<vector<int>> &table, int x) {
    int key = getHash(x);
    int value = find(table[key], x);
    if (!table[key].empty() && value != -1 && table[key][value] == x) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

int main() {
    inp
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    vector<vector<int>> hash_table(1000001);
    string instruction;
    while (cin >> instruction) {
        if (instruction == "insert") {
            int x;
            cin >> x;
            Insert(hash_table, x);
        } else if (instruction == "delete") {
            int x;
            cin >> x;
            Delete(hash_table, x);
        } else if (instruction == "exists") {
            int x;
            cin >> x;
            Exists(hash_table, x);
        }

    }
    return 0;
}