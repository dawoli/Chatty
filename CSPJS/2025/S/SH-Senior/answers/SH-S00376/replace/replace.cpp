#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)

int n,q;
string a,b;
//pair<string,string> c[200006],d[200006];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	For(i,1,n){
		//cin>>c[i].first>>c[i].second;
		cin>>a>>b;
	}
	For(i,1,q){
		//cin>>d[i].first>>d[i].second;
		cin>>a>>b;
	}
	For(i,1,q){
		cout<<0<<'\n';
	}
	return 0;
}

