#include <bits/stdc++.h>
using namespace std;
const int M=1e5+2;
int n;
int r[M],num[M],f[M];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>r[i];
		num[r[i]]++;
	}
	sort(r+1,r+n+1);
	n=unique(r+1,r+n+1)-r-1;
	f[1]=num[r[1]];
	for (int i=2;i<=n;i++) f[i]=num[r[i]]+max(f[i-1]-num[r[i]],0);
	cout<<f[n];
	return 0;
}
