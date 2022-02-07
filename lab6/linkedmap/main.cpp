#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

struct Node {
    string first;
    string second;
    Node *next;
    Node *prev;
    Node *forward;
    Node *previous;

    Node(string &n1, string &n2) : next(nullptr), prev(nullptr), forward(nullptr), previous(nullptr) {
        this->first = n1;
        this->second = n2;
    }
};


struct list {
    Node *root;
    Node *tail;

    list() : root(nullptr), tail(nullptr) {};

    void push_back(string key, string value) {
        Node *temp = new Node(key, value);
        if (!root && !tail) {
            root = temp;
            tail = temp;
            return;
        }
        tail->forward = temp;
        temp->previous = tail;
        tail = temp;
    };

    Node *find(string &key) {
        Node *temp = root;
        while (temp) {
            if (temp->first == key) {
                return temp;
            }
            temp = temp->forward;
        }
        return nullptr;
    }

    void erase(string key) {
        Node *temp = root;
        if (!root && !tail) {
            return;
        }
        while (temp) {
            if (temp->first == key) {
                if (temp == tail && temp == root) {
                    root = nullptr;
                    tail = nullptr;
                } else if (temp == root) {
                    root = root->forward;
                } else if (temp == tail) {
                    tail = tail->previous;
                } else {
                    Node *prev = temp->previous, *next = temp->forward;
                    prev->forward = next;
                    next->previous = prev;
                }
                delete temp;
            }
            temp = temp->forward;
        }
    }
};


unsigned int getHash(string &key) {
    int hash_value;
    hash_value = 0;
    for (int i = 0; i < key.size(); i++) {
        hash_value += key[i] * (i + 1);
    }
    return abs((hash_value)) % 100001;
}



void Put(vector<list> &table, string &first, string &second, Node *&last_added) {
    unsigned int key = getHash(first);
    table[key].push_back(first, second);
    if (last_added != nullptr) {
        last_added->next = table[key].tail;
        table[key].tail->prev = last_added;
    }
    last_added = table[key].tail;
}

void Delete(vector<list> &table, string &first, Node *&last_added) {
    unsigned int key = getHash(first);
    Node *value = table[key].find(first);
    if (value && value->first == first) {
        if (last_added == value && value->prev) {
            last_added = value->prev;
        } else if (last_added == value) {
            last_added = nullptr;
        }
        value->prev->next = value->next;
        value->next->prev = value->prev;
        table[key].erase(first);
    }
}

Node *Get(vector<list> &table, string &first) {
    return table[getHash(first)].find(first);
}


int main() {
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    vector<list> hash_table(100001);
    string instruction;
    Node *last_added = nullptr;
    while (fin >> instruction) {
        if (instruction == "put") {
            string first;
            string second;
            fin >> first >> second;
            Put(hash_table, first, second, last_added);
        } else if (instruction == "delete") {
            string first;
            fin >> first;
            Delete(hash_table, first, last_added);
        } else if (instruction == "get") {
            string first;
            fin >> first;
            Node *temp = Get(hash_table, first);
            if (temp != nullptr) {
                fout << temp->second << endl;
            } else {
                fout << "none" << endl;
            }
        } else if (instruction == "prev") {
            string first;
            fin >> first;
            Node *temp = Get(hash_table, first);
            if (temp != nullptr && temp->prev != nullptr) {
                fout << temp->prev->second << endl;
            } else {
                fout << "none" << endl;
            }
        } else if (instruction == "next") {
            string first;
            fin >> first;
            Node *temp = Get(hash_table, first);
            if (temp != nullptr && temp->next != nullptr) {
                fout << temp->next->second << endl;
            } else {
                fout << "none" << endl;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
