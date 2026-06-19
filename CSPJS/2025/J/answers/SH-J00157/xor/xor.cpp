#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;
ll n,m,k;
ll ans;
ll f[N][N];
struct node{
	int s,e;
}st[N*N];
bool cmp(node a,node b){
	return a.e < b.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j] = f[i][j-1]^f[j][j];
			if(f[i][j] == k){
				st[++m].s = i;
				st[m].e = j;
			}
		}
	}
	sort(st+1,st+m+1,cmp);
	int ls = 0;
	for(int i=1;i<=m;i++){
		if(st[i].s > ls){
			ans++;
			ls = st[i].e;
		}
	}
	cout<<ans;
	return 0;
}
