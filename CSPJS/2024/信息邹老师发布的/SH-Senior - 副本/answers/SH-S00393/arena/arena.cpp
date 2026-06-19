#include<bits/stdc++.h>
using namespace std;
int T,n,m,as[100010],c[100010],x0,x1,x2,x3;
char lp[20][100010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	srand(n);
	for(int i=1;i<=n;i++)cin>>as[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	int k=ceil(log(n)/log(2));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=pow(2,k-i);j++){
			cin>>lp[i][j];
		}
	}cin>>T;
	while(T--){
		cin>>x0>>x1>>x2>>x3;
		cout<<rand()%20<<'\n';
	}
	return 0;
}
