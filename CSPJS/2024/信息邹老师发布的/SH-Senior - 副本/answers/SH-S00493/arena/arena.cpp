#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a1[10005],a[10005];
int c[10005];
bool d[30][10005];
long long x[5];
pair<long long,int> res[30][20005];
long long solve(int c1){
	int k=0;while((1<<k)<c1) k++;
	for(int i = 1;i<=(1<<k);i++) res[0][i]=make_pair((long long)i,0);
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=(1<<(k-i));j++){
			if(d[i][j]==0){
				if(res[i-1][(j<<1)-1].second==0){
					if(res[i-1][(j<<1)-1].first>c1){
						res[i][j].first=res[i-1][(j<<1)-1].first+res[i-1][(j<<1)].first;
						res[i][j].second=1;
					}else{
						if(a[res[i-1][(j<<1)-1].first]>=i) res[i][j]=res[i-1][(j<<1)-1];
						else res[i][j]=res[i-1][(j<<1)];
					}
				}else{
					res[i][j].first=res[i-1][(j<<1)-1].first+res[i-1][(j<<1)].first;
					res[i][j].second=1;
				}
			}else{
				if(res[i-1][(j<<1)].second==0){
					if(res[i-1][(j<<1)].first>c1){
						res[i][j].first=res[i-1][(j<<1)-1].first+res[i-1][(j<<1)].first;
						res[i][j].second=1;
					}else{
						if(a[res[i-1][(j<<1)].first]>=i) res[i][j]=res[i-1][(j<<1)];
						else res[i][j]=res[i-1][(j<<1)-1];
					}
				}else{
					res[i][j].first=res[i-1][(j<<1)-1].first+res[i-1][(j<<1)].first;
					res[i][j].second=1;
				}
			}
		}
	}/*
	for(int i = 0;i<=k;i++){
		for(int j = 1;j<=(1<<(k-i));j++){
			cout<<res[i][j].first<<" ";
		}
		cout<<endl;
	}*/
	return res[k][1].first;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%lld",&a1[i]);
	for(int i = 1;i<=m;i++) scanf("%d",&c[i]);
	int k=0;while((1<<k)<n) k++;
	for(int i = 1;i<=k;i++){
		string s;cin>>s;
		for(int j = 1;j<=(1<<(k-i));j++){
			d[i][j]=s[j-1]-'0';
		}
	}
	int t;scanf("%d",&t);
	while(t--){
		for(int i = 0;i<=3;i++) scanf("%lld",&x[i]);
		for(int i = 1;i<=n;i++) a[i]=a1[i]^x[i%4];
		long long ans=0;
		for(int i = 1;i<=m;i++){
			//cout<<i<<" "<<solve(c[i])<<endl;
			ans^=((long long)(i)*solve(c[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 5
0 0 0 0 0
5 4 1 2 3
1001
10
1
4
2 1 0 0
1 2 1 0
0 2 3 1
2 2 0 1
*/
