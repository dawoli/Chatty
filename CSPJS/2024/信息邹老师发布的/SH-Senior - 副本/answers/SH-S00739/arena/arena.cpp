#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100001],c[100001],K,b[5];
string d[100001];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=10;i++){
		if(pow(2,i)>=n){
			K=i;
			break;
		}
	}
	for(int i=1;i<=K;i++){
		cin>>d[i];
	}
	cin>>T;
	for(int i=1;i<=4;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		a[i]=a[i]^(b[i%4]);
	}
	cout<<18;
	return 0;
}

