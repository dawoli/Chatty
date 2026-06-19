#include<iostream>
#include<algorithm>
using namespace std;

const int NN = 105;
struct Node {
	int Sco,Id;
} A[NN];

bool Cmp(Node X,Node Y) {
	return X.Sco > Y.Sco;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int N,M;
	cin >> N >> M;
	for (int i = 1;i <= N * M;i++) {
		cin >> A[i].Sco;
		A[i].Id = i;
	}
	sort(A + 1,A + N * M + 1,Cmp);
	for (int i = 1;i <= M;i++) {
		if (i % 2 == 1) {
			for (int j = 1;j <= N;j++) {
				if (A[(i - 1) * N + j].Id == 1) {
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		}
		else {
			for (int j = N;j >= 1;j--) {
				if (A[(i - 1) * N + N - j + 1].Id == 1) {
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
