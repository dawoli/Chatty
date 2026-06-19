#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+2;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++) 
string s1[maxn],s2[maxn];string t1,t2;
bool  ck(int x,int y,int z){
	if(s1[x].length()!=y)return false;
	rep(i,z-1,z-2+y){
		if(s1[x][i-z+1]!=t1[i])return false;
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	ll ans;
	rep(i,1,n)cin>>s1[i]>>s2[i];
	rep(i,1,q){
		ans=0;
		cin>>t1>>t2;
		rep(j,1,t1.length()){
			rep(p,1,t1.length()+1-j){d
				rep(o,1,n){
					if(ck(o,j,p)){
						string tmp="";
						rep(pp,0,p-2)tmp+=t1[pp];
						tmp+=s2[o];
						rep(pp,p+j-1,t1.length()-1)tmp+=t1[pp];
						if(tmp==t2)ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;	
}
