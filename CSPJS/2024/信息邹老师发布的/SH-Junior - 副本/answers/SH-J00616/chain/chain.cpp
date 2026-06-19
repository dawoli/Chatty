#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int K=2e5+5;
const int M=100+5;
const int maxn=2e5;
int t;
int n,k,q;
int l[N];
int s[K],vis[K],tot;
int f[M][K],fl[M][K],fll[M][K],ff[M][K];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		tot=0;
		cin>>n>>k>>q;
		for(int i=1;i<=maxn;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>l[i];
			vis[tot+1]=1;
			for(int j=1;j<=l[i];j++){
				cin>>s[++tot];
			}
		}
		for(int i=1;i<=100;i++){
			for(int j=1;j<=maxn;j++){
				f[i][j]=fll[i][j]=fl[i][j]=0;
			}
		}
		for(int i=1;i<=100;i++){
			int flag=1;
			for(int j=1;j<=maxn;j++){
				fll[i-1][j]=0;
			}
			fll[0][1]=1;
			for(int j=1;j<=tot;j++){
				if(vis[j]){
					for(int z=flag;z<j;z++){
						fll[i-1][s[z]]|=f[i-1][z];
					}
					flag=j;
				}
				f[i][j]|=fll[i-1][s[j]];
			}
			for(int j=1;j<=maxn;j++){
				fll[i-1][j]=0;
			}
			fll[0][1]=1;
			flag=tot;
			for(int j=tot;j>=1;j--){
				if(vis[j+1]){
					for(int z=j+1;z<=flag;z++){
						fll[i-1][s[z]]|=f[i-1][z];
					}
					flag=j;
				}
				f[i][j]|=fll[i-1][s[j]];
			}
			int now=0;
			flag=1;
			for(int j=1;j<=tot;j++){
				if(vis[j]){
					flag=j;
					now=0;
				}
				else{
					if(j>=k+flag){
						now-=f[i][j-k];
					}
					now+=f[i][j-1];
				}
				if(now)	ff[i][j]=1;
				else	ff[i][j]=0;
			}
			for(int j=1;j<=tot;j++){
				f[i][j]=ff[i][j];
			}
			for(int j=1;j<=tot;j++){
				fl[i][s[j]]|=f[i][j];
			}
		}
		int r,c;
		while(q--){
			cin>>r>>c;
			cout<<fl[r][c]<<endl;
		}
	}
	return 0;
}
