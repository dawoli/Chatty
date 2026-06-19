#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(a) {sc<<#a<<"="<<a<<"\n";}
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define qloga(a,l,r) {sc<<#a<<" : ";rep(I,l,r){sc<<a[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : ";for(auto I:a){sc<<I<<" ";}sc<<"\n";}
typedef long long ll;

const int N=500+10;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>q;
	rep(i,1,n)cin>>s1[i]>>s2[i];
	rep(i,1,q)cin>>t1[i]>>t2[i];
	
	rep(x,1,q){
		ll ans=0;
		for(int i=0;i<(int)t1[x].size();i++){
			for(int y=1;y<=n;y++){
				if(i+(int)s1[y].size()-1 >= (int)t1[x].size())continue;
				bool flg=1;
				for(int j=0;j<(int)s1[y].size();j++){
					if(t1[x][i+j]!=s1[y][j] || t2[x][i+j]!=s2[y][j]){flg=0;break;}
				}
				for(int j=0;j<i;j++)if(t1[x][j]!=t2[x][j]){flg=0;break;}
				for(int j=i+(int)s1[y].size();j<(int)t1[x].size();j++)if(t1[x][j]!=t2[x][j]){flg=0;break;}
				if(flg)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
