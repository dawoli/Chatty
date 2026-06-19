#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> v; 
int n,q;
string a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	v.push_back(make_pair("",""));
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	while(q--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		int lent=a.size();
		for(int i=0;i<lent;i++){
			for(int j=1;j<=n;j++){
				int lens=v[j].first.size();
				if(i+lens>lent) continue;
				if(a.substr(i,lens)==v[j].first){
//					cout<<i<<" "<<v[j].second<<"\n";
					string now=a;
					for(int k=0;k<lens;k++) now[k+i]=v[j].second[k];
//					cout<<now<<"\n";
					if(now==b) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
