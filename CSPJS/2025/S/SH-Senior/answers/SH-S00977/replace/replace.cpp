#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long n,q;
map<string,vector<string>>mp;
string get(string s,int l,int r){
	string re;
	for(int i=l;i<=r;i++){
		re=re+s[i];
	}
	return re;
}
void solve(){
	cin>>a>>b;
	long long d1,d2,l=a.size(),ans=0;
	a=' '+a;
	b=' '+b;
	for(int i=1;i<=l;i++){
		if(a[i]!=b[i]){
			d1=i;
			break;
		}
	}
	for(int i=l;i>=1;i--){
		if(a[i]!=b[i]){
			d2=i;
			break;
		}
	}
	for(int i=1;i<=d1;i++){
		for(int j=d2;j<=l;j++){
			c=get(a,i,j);
			d=get(b,i,j);
			for(int x=0;x<mp[c].size();x++){
				if(mp[c][x]==d){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a].push_back(b);
	}
	while(q--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
