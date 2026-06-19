#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s1[MAXN],s2[MAXN],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		int tz=t1.size();
		for(int j=1;j<=n;j++){
			int sz=s1[j].size();
			for(int k=0;k+sz<=tz;k++){
				if(t1.substr(k,sz)==s1[j]&&t1.substr(0,k)+s2[j]+t1.substr(k+sz)==t2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
