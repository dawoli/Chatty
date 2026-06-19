#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;
int n,a[maxn],s,tot=1,num[maxn],c[maxn],m,t;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k=1;
	while((1<<k)<n) k++;
	string aa;
	for(int i=1;i<=k;i++){
		cin>>aa;
	}
	cin>>s;
	for(int i=1;i<=m;i++){
		k=0;
		while((1<<k)<c[i]) k++;
		a[i]=k;
	}
	long long int ans=a[1];
	for(int i=2;i<=n;i++){
		ans^=(i*a[i]);
	}
	for(int i=1;i<=s;i++){
		cout<<ans<<endl;
	}
	return 0;
}




















