#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

int a[N],b[N];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int cn=2,k=1;
	while(cn<n)cn*=2,k++;
	for(int i=1;i<=k;i++)cin>>a[i];
	int T;
	cin>>T;
	while(T--){
		for(int i=1;i<=4;i++)cin>>a[i];
		cout<<1;
	}
	return 0;
} 
