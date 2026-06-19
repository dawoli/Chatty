#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mol=998244353;
const int N=550;
int n,m,cnt;
string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(!c[i]) cnt++;
	}
	sort(c+1,c+n+1);
	int ans=1;
	if(cnt>=m){
		for(int i=1;i<=cnt;++i){
			ans=(ans*i)%mol;
		}
		cout<<ans;
	}
	if(cnt<m){
		cout<<0;
	}
	return 0;
}
