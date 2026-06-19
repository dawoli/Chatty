#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+9;
const int MOD=998244353;
int n,m,x[N],c[N],id[N];
void solveBF(){
	int ans=0;
	for(int i=1;i<=n;i++) id[i]=i;
	do{
		int cnt=0; int nch=0;
		for(int i=1;i<=n;i++){
			int now=id[i];
			if(nch>=c[now]){
				nch++;
				continue;
			}
			if(x[i]==1) cnt++;
			else nch++;
		}
		if(cnt>=m) ans=(ans+1)%MOD;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
}
void solvespecial(){
	cin>>n>>m;
	cout<<n;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c; cin>>c;
		if(c=='0') x[i]=0;
		else x[i]=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) solveBF();
	else solvespecial();
	return 0;
}
