#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<pair<int,int>,pair<string,string> >,int> t;
string s[200005][2];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	if(q!=1) {
		for(int i=1;i<=n;i++) {
			string a,b;
			cin >> a >> b;
			int l=0,r=a.size()-1;
			for(l=0;l<a.size();l++) {
				if(a[l]!=b[l]) break;
			}
			for(r=a.size()-1;r>=0;r--) {
				if(a[r]!=b[r]) break;
			}
			string aa="",bb="";
			for(int j=l;j<=r;j++) {
				aa+=a[j];
				bb+=b[j];
			}
			t[{{l,a.size()-1-r},{aa,bb}}]++;
		}
		while(q--) {
			string a,b;
			cin >> a >> b;
			if(a.size()!=b.size()) {
				cout << 0 << endl;
				continue;
			}
			int l=0,r=a.size()-1;
			for(l=0;l<a.size();l++) {
				if(a[l]!=b[l]) break;
			}
			for(r=a.size()-1;r>=0;r--) {
				if(a[r]!=b[r]) break;
			}
			string aa="",bb="";
			for(int j=l;j<=r;j++) {
				aa+=a[j];
				bb+=b[j];
			}
			int ans=0;
			for(int i=0;i<=l;i++) {
				for(int j=0;j<=a.size()-1-r;j++) {
					ans+=t[{{i,j},{aa,bb}}];
				}
			}
			cout << ans << endl;
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			cin >> s[i][0] >> s[i][1];
		}
		string a,b;
		cin >> a >> b;
		int l=1,r=a.size()-1;
		if(a.size()!=b.size()) {
			cout << 0 << endl;
			return 0;
		}
		for(l=1;l<a.size();l++) {
			if(a[l]!=b[l]) break;
		}
		for(r=a.size()-1;r>=0;r--) {
			if(a[r]!=b[r]) break;
		}
		string aa="",bb="";
		for(int i=l;i<=r;i++) {
			aa+=a[i];
			bb+=b[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			int ll=1,rr=s[i][0].size()-1;
			for(ll=0;ll<s[i][0].size();ll++) {
				if(s[i][0][ll]!=s[i][1][ll]) break;
			}
			for(rr=s[i][0].size()-1;rr>=0;rr--) {
				if(s[i][0][rr]!=s[i][1][rr]) break;
			}
			string aaa="",bbb="";
			for(int j=ll;j<=rr;j++) {
				aaa+=s[i][0][j];
				bbb+=s[i][1][j];
			}
			if(aaa==aa&&bbb==bb&&ll<=l&&(s[i][0].size()-1-rr)<=(a.size()-1-r)) {
				ans++;
			}
			//if(i==3) cout << ll << ' ' << rr << endl;
		}
		cout << ans << endl;
	}
	return 0;
} 
