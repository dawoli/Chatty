#include<bits/stdc++.h>
using namespace std;
int n,m,att,mx;
int a[10005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int j=100000;
	for(int i=1;i<=n;i++){
		cin>>m;
		a[m]++;
		if(m<j) j=m;
		if(m>mx) mx=m;
	}
	for(int i=j+1;i<=mx;i++){
		if(a[i]==0) continue;
		n-=min(a[j],a[i]);
		a[j]-=min(a[j],a[i]);
		j=i;
	}
	cout<<n;
	return 0;
}

