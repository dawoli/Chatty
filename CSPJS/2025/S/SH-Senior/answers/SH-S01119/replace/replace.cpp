/*========replace==========*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*========replace==========*/

int n,q;
vector<pair<string,string>> rep;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	rep.push_back({"",""});
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		rep.push_back({a,b});
	}
	while(q--){
		int ways=0;
		string fr,to;
		cin>>fr>>to;
		for(int i=1;i<=n;i++){
			pair<string,string> x=rep[i];
			if(fr.find(x.first)<fr.length()){
				string tempstr=fr;
				if(tempstr.replace(tempstr.find(x.first),x.first.length(),x.second)==to){
					ways++;
				}
			}
		}
		cout<<ways<<endl;
	}
	return 0;
}
