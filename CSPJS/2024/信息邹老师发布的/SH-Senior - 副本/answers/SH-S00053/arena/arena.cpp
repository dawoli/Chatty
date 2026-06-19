#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N],k[N],nli[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	int cnt=0;
	while(n){
		n/=2;
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		cin>>k[i];
	}
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		cin>>nli[1]>>nli[2]>>nli[3]>>nli[4];
		cout<<nli[1]+nli[2]+nli[3]+nli[4]<<endl;
	}
	return 0;
}
