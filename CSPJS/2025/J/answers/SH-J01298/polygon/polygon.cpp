#include<iostream>
#include<algorithm>
using namespace std;

const int NN = 5005,MOD = 998244353;
int A[NN],N,Maxn,Sum;
long long Ans = 0;
bool Plan[NN];

void dfs(int Step) {
	if (Step > N) {
		if (Sum <= Maxn * 2) return ;
		Ans++; Ans %= MOD;
		return ;
	}
	int Tmp = Maxn;
	Plan[Step] = true,Maxn = max(Maxn,A[Step]),Sum += A[Step];
	dfs(Step + 1);
	Plan[Step] = false,Maxn = Tmp,Sum -= A[Step];
	dfs(Step + 1);
	return ;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> N;
	for (int i = 1;i <= N;i++) cin >> A[i];
	dfs(1);
	cout << Ans << endl;
	return 0;
} 
