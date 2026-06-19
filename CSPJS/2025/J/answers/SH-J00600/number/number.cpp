#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
#define INF 1e18
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
string s;
int cnt[19];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	rep(i,0,n-1){
		if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
	}
	Rep(i,9,0){
		while(cnt[i]--){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}

