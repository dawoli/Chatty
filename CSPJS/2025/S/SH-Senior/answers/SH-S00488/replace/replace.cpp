#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
int n,q;
vector<pair<string,string> >m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2; cin>>s1>>s2;
		m.push_back({s1,s2});
	}
	while(q--){
		string s,ss;
		cin>>s>>ss;
		if(s.size()!=ss.size()){
			cout<<0<<endl;
			continue;
		}
		int h=s.size();
		int ans=0;
		for(int i=0;i<h;i++){
			if(i!=0&&s.substr(0,i)!=ss.substr(0,i)) break;
			for(int j=0;j<n;j++){
				if(s.substr(i,m[j].first.size())==m[j].first&&s.substr(i+m[j].first.size(),h-i-m[j].first.size())==ss.substr(i+m[j].first.size(),h-i-m[j].first.size())&&m[j].second==ss.substr(i,m[j].second.size())){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
