#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1009;
const int L=2009;
int T,k,n;
int a[N][L],ai[N][N],t[N];
void solve(int r,int c){
	if(r==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=t[i];j++){
				for(int u=2;u<=k;u++){
					int np=ai[i][j]+u-1;
					if(a[i][np]==c){
						cout<<1<<endl;
						return ;
					}
				}
			}
		}
		cout<<0<<endl;
		return ;
	}
	cout<<(c%r)%2<<endl;
	return ;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int U=1;U<=T;U++){
		int q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>a[i][j];
				if(a[i][j]==1){
					ai[i][++t[i]]=j;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			solve(r,c);
		}
		for(int i=1;i<=n;i++){
			t[i]=0;
		}
	}
	return 0;
}
