#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,len,ans;
pair<string,string> c[200005],f[200005],nown;
string now;
set<pair<string,string> >e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> nown.first;
		cin >> nown.second;
		e.insert(nown);
	}
	for (auto i:e){
		len++;
		c[len].first=i.first;
		c[len].second=i.second;
		l=0;
		r=c[len].first.size()-1;
		while(c[len].first[l]==c[len].second[l]){
			l++;
		}
		while(c[len].first[r]==c[len].second[r]){
			r--;
		}
		now="";
		for (int j=l;j<=r;j++){
			now+=c[len].first[j];
		}
		c[len].first=now;
		now="";
		for (int j=l;j<=r;j++){
			now+=c[len].second[j];
		}
		c[len].second=now;
	}
	for (int i=1;i<=q;i++){
		ans=0;
		cin >> f[i].first;
		cin >> f[i].second;
		l=0;
		r=f[i].first.size()-1;
		while(f[i].first[l]==f[i].second[l]){
			l++;
		}
		while(f[i].first[r]==f[i].second[r]){
			r--;
		}
		now="";
		for (int j=l;j<=r;j++){
			now+=f[i].first[j];
		}
		f[i].first=now;
		now="";
		for (int j=l;j<=r;j++){
			now+=f[i].second[j];
		}
		f[i].second=now;
		for (int j=1;j<=len;j++){
			if (c[j]==f[i]){
				ans++;
			}
		}
		cout << ans<<endl;
	}
	return 0;
}
