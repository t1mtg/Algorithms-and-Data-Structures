
#include <iostream>

#include <functional>

#include <vector>

#include <list>



#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);



using namespace std;



template<typename T>

class Set {

private:

    vector<list<T>> hashTable;

public:

    Set() {

        hashTable.resize(100000);

    }



    long long int getHash(T x) {

        return (x+1000000000)%100000;

    }



    void insert(T x) {

        if (!exists(x)) {

            hashTable[getHash(x)].push_back(x);

        }

    }



    bool exists(T x) {

        list<T> *currentList = &hashTable[getHash(x)];

        return find(currentList->begin(), currentList->end(), x) != currentList->end();

    }



    void erase(T x) {

        list<T> *currentList = &hashTable[getHash(x)];

        auto it = find(currentList->begin(), currentList->end(), x);

        if (it != currentList->end()) {

            currentList->erase(it);

        }

    }

};



int main() {

    fast

    freopen("set.in", "r", stdin);

    freopen("set.out", "w", stdout);

    Set<int> set;

    string instruction;

    int x;

    while (cin >> instruction) {

        if (instruction == "insert") {

            cin >> x;

            set.insert(x);

        } else if (instruction == "exists") {

            cin >> x;

            cout << (set.exists(x) ? "true" : "false") << endl;

        } else if (instruction == "delete") {

            cin >> x;

            set.erase(x);

        }

    }

    return 0;

}
