#include<bits/stdc++.h>
using namespace std;
pair<string,string>s;
int main(){
	int n,q;
	cin>>n>>q;
	vector<pair<string,string>>ve;
	for(int i = 1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		ve.push_back(make_pair(a,b));
	}
	for(int o = 1;o<=q;o++){
		long long ans = 0;
		string x,y;
		cin>>x>>y;
		string u,v,w;
		string uu,vv,ww;
		for(int i = 1;i<=n;i++){
			bool f = true;
			string a = ve[i].first;
			string b = ve[i].second;
			if(x.find(a)<x.size() && y.find(b)<y.size() && x.find(a)==y.find(b)){
				for(int i = 0;i<x.find(a);i++){
					u.push_back(a[i]);
					uu.push_back(b[i]);
					if(u!=uu){
						f = false;
						break;
					}
				}
				if(f){
					for(int i = x.find(a)+a.size();i<x.size();i++){
						w.push_back(a[i]);
						ww.push_back(b[i]);
						if(w!=ww){
							f = false;
							break;
						}
					}
				}
				if(f) ans++;
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
