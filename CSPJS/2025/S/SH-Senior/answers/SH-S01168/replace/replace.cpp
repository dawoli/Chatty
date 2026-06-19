#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int n,q;
struct node{
	string a,b;
}s[N], t;
ll ans;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		cin>>t.a>>t.b;
		ans=0;
		if(t.a.size() != t.b.size()){
			cout<<0<<'\n';
			continue;
		}
		int t_sz=t.a.size();
		for(int i=1;i<=n;i++){
			int s_sz=s[i].a.size();
			if(s_sz > t_sz) continue;
			int loc=0;
			while(loc+s_sz <= t_sz){
				if(t.a.substr(loc,s_sz) == s[i].a){
					string x=t.a.substr(0,loc) , z=t.a.substr(loc+s_sz, t_sz-loc-s_sz);
					if(x+s[i].b+z == t.b) ans++;
				}
				loc++;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}

