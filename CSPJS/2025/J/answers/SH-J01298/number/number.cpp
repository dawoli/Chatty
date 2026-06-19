#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int A[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
	cin >> S;
	int Len = S.size(),Cur = 0;
	S = '?' + S;
	for (int i = 1;i <= Len;i++)
		if ('0' <= S[i] && S[i] <= '9') A[++Cur] = S[i] - '0';
	sort(A + 1,A + Cur + 1);
	for (int i = Cur;i >= 1;i--) cout << A[i];
	return 0;
}
