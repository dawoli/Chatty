#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define int long long
#define INF 1e18
#define gc getchar()
#define pss pair<string,string>
#define mp(x,y) make_pair((x),(y))
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;
		char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=gc;
		}
		return x*f;
	}
}
using namespace fastIO;
int n,q;
string s[200009],t[200009];
void get(string &a,string &b){
	int la=0,lb=0,ra=(int)(a.size())-1,rb=(int)(b.size())-1;
	while(la<=ra&&lb<=rb){
		if(a[la]!=b[lb]) break;
		la++,lb++;
	}
	while(la<=ra&&lb<=rb){
		if(a[ra]!=b[rb]) break;
		ra--,rb--;
	}
//	cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<endl;
	a=a.substr(la,ra-la+1);
	b=b.substr(lb,rb-lb+1);
}
map<pss,int> cnt;
string a,b,c,d;
void solve_bf(){
	while(q--){
		cin>>a>>b;
		c=a,d=b;get(c,d);
		if(cnt[mp(c,d)]==0){
			cout<<0;
			if(q) cout<<'\n';
			continue;
		}
		int ans=0;
		for(int i=0;i<min((int)a.size(),(int)b.size());i++){
			rep(j,1,n){
				if((int)a.size()-i<s[j].size()) continue;
				if((int)b.size()-i<t[j].size()) continue;
				int l=i,r=0;
				while(r<s[j].size()){
					if(a[l]!=s[j][r]) break;
					l++,r++;
				}
				if(r!=s[j].size()) continue;
				l=i,r=0;
				while(r<t[j].size()){
					if(b[l]!=t[j][r]) break;
					l++,r++;
				}
				if(r!=t[j].size()) continue;
				r=l;
				l=i+s[j].size();
				while(l<a.size()){
					if(a[l]!=b[r]){
						ans--;
						break;
					}
					l++,r++;
				}
				ans++;
		//		cout<<j<<endl;
			}
			if(a[i]!=b[i]) break;
		}
		cout<<ans;
		if(q) cout<<'\n';
	}
	cout<<endl;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	rep(i,1,n){
		cin>>s[i]>>t[i];
		a=s[i],b=t[i];
		get(a,b);
		cnt[mp(a,b)]++;
	}
	solve_bf();
	return 0;
}

