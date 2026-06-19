#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		string tt[5][8];
		int s[5]={0},ws=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<8;j++){
				cin>>tt[i][j];
				ws+=(tt[i][j]=="math");
				s[i]+=(tt[i][j]=="math");
			}
		}
		int n,m,ans=0;
		cin>>n>>m;
		n-=8-m;
		int w=n/7,fr=n-n/7*7;
		for(int i=m-1;i<5;i++){
			ans+=s[i];
		}
		for(int i=0;i<fr;i++){
			ans+=s[i];
		}
		ans+=ws*w;
		cout<<ans<<endl;
	}
	return 0;
}
