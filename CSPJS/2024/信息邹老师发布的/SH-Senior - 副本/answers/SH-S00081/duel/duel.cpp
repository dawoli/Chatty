#include<bits/stdc++.h>
using namespace std;
const int N=1e5+999;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int p=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[p]) p++;
	cout<<n-p+1;
	return 0;
}