#include <iostream>
using namespace std;
struct Tree {
	int Data;
	int Left;
	int Right;
	int Parent;
}mass[200000];

int Height (struct Tree *mass, int k) {
	int left, right;
	if ((mass[k].Left == 0) && (mass[k].Right == 0)) {
		return 1;
	}
	if (mass[k].Left == 0) {
		left = 0;
	} else {
		left = Height(mass, mass[k].Left);
	}

	if (mass[k].Right == 0) {
		right = 0;
	} else {
		right = Height(mass, mass[k].Right);
	}

	if (left > right) {
		return left + 1;
	} else {
		return right + 1;
	}
}

int main()
{
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int N;
    cin >> N;
	if (N == 0){
		cout << 0;
		return 0;
	}
    for (int i = 1; i <= N; i++) {
    	cin >> mass[i].Data >> mass[i].Left >> mass[i].Right;
    	mass[mass[i].Left].Parent = i;
    	mass[mass[i].Right].Parent = i;
	}
	cout << Height(mass, 1);

	return 0;
}

