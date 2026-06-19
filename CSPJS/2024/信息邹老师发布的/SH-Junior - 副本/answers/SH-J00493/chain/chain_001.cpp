#include<bits/stdc++.h>
using namespace std;
const int N=1003,L=2003,R=12,C=200002;
int l[N],pos[N];
vector<int> a[N];
int f[L+C][R];
vector<int> e[L];
vector<int> col[C];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,m,q,suml=0;
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];suml+=l[i];
			pos[i+1]=pos[i]+l[i];
			for(int j=0;j<l[i];j++){
				int x;
				cin>>x;
				a[i].push_back(x);
				col[x].push_back(pos[i]+j);
			}
		}
		for(int i=1;i<=200000;i++) col[i].push_back(suml+i);
		for(int i=1;i<=n;i++){
			for(int j=0;j<l[i];j++){
				for(int k=j+1;k<l[i] && k<j+m;k++){
					for(auto x:col[a[i][k]]){
						if(x<pos[i] || x>=pos[i]+l[i]){
							e[pos[i]+j].push_back(x);
						}
					}
				}
			} 
		}

		for(auto x:col[1]) f[x][0]=1;
		for(int r=0;r<10;r++){
			for(int i=0;i<suml;i++){
				if(!f[i][r]) continue;
				for(auto j:e[i]){
					f[j][r+1]=1;
				}
			}
		}
		/*
		for(int i=0;i<suml;i++){
			cout<<i<<"!\n";
			for(int j=0;j<5;j++) cout<<f[i][j]<<" ";
			cout<<"\n";
		}
		*/
		while(q--){
			int x,y,ans=0;
			cin>>x>>y;
			for(auto z:col[y]){
				if(f[z][x]){
					ans=1;
					break;
				}
			}
			cout<<ans<<"\n";
		}
		
		for(int i=0;i<=n;i++) a[i].clear();
		for(int i=0;i<=200000;i++) col[i].clear();
		for(int i=0;i<=2000;i++) e[i].clear();
		memset(f,0,sizeof f);
	}
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
