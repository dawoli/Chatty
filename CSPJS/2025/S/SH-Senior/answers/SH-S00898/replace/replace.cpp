#include<bits/stdc++.h>
using namespace std;

int n,q;
string substr(string s,int l,int r){
	string res;
	for(int i=l;i<=r;i++){
		res+=s[i];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	vector<pair<string,string>> tups(n);
	vector<int> tupl(n);
	for(int i=0;i<n;i++){
		cin>>tups[i].first>>tups[i].second;
		tupl[i]=strlen(tups[i].first.c_str());
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int t1l=strlen(t1.c_str());
		int cnt=0;
		for(int i=0;i<tups.size();i++){
			string ori=tups[i].first,chg=tups[i].second;
			int orl=tupl[i];
			for(int i=0;i<=t1l-orl;i++){
				if(t1[i]==ori[0]){
					string x=substr(t1,0,i-1);
					string y=substr(t1,i,i+orl-1);
					string z=substr(t1,i+orl,t1l-1);
					if(y==ori&&x+chg+z==t2)cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
}
