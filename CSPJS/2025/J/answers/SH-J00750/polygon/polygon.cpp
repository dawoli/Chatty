#include<bits/stdc++.h>
using namespace std;
const int m=998244353;
int n,cnt;
int a[5010],b[5010];

void dfs(int l,int s,int p){
	if(a[l]*2<s && p>=3){
		cnt++;
		cnt%=m;
//		for(int i=1;i<=p;i++) cout<<b[i]<<' ';
//		cout<<'\n';
	}

	for(int i=l+1;i<=n;i++){
		b[p+1]=i;
		dfs(i,s+a[i],p+1);
		b[p+1]=0;
	}
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		b[1]=i;
		dfs(i,a[i],1);

	}
	cout<<cnt;

	return 0;
}
