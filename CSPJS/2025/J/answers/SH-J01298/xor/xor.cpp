#include<iostream>
#include<algorithm>
using namespace std;

const int NN = 1e6 + 5;
int A[NN],Xor[NN];
struct Node {int B,E;} S[NN];

bool Cmp(Node x,Node y) { 
	return x.E < y.E;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int N,K,Cur = 0;
	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		Xor[i] = Xor[i - 1] ^ A[i];
	}
	for (int i = 1;i <= N;i++)
		for (int j = i;j <= N;j++) {
			if ((Xor[j] ^ Xor[i - 1]) == K) {
				S[++Cur].B = i,S[Cur].E = j;
			}
		}
	sort(S + 1,S + Cur + 1,Cmp);
	int Maxe = 0,Ans = 0;
	for (int i = 1;i <= Cur;i++)
		if (S[i].B > Maxe) Maxe = S[i].E,Ans++;
	cout << Ans << endl; 
	return 0;
}
