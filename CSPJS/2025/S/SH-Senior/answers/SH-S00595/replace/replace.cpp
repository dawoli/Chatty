#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5;
int n,q;
unordered_map<string,map<string,vector<pair<string,string>>>> m;
vector<string> sames;

pair<int,int> find(string p,string q){
	pair<int,int> ret={0,p.length()-1};
	while (ret.first<p.length() and p[ret.first]==q[ret.first]) ret.first++;
	while (ret.second>=0 and p[ret.second]==q[ret.second]) ret.second--;
	return ret;
}

bool check(string l,string s){
	if (l.length()<s.length()) return false;
	for (int i=0; i<s.length(); i--){
		if (l[l.length()-1-i]!=s[s.length()-1-i]) return false;
	}
	return true;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	string s1,s2;
	for (int i=0; i<n; i++){
		cin>>s1>>s2;
		auto f=find(s1,s2);
		if (s1==s2) continue;
		auto begin=f.first,end=f.second;
		//cout<<"test "<<s1.substr(begin,end-begin+1)<<' '<<s2.substr(begin,end-begin+1)<<' '<<s1.substr(0,begin)<<' '<<s1.substr(end+1,(int)s1.length()-end)<<'\n';
		m[s1.substr(begin,end-begin+1)][s2.substr(begin,end-begin+1)].push_back({s1.substr(0,begin),s1.substr(end+1,(int)s1.length()-end)});
	}
	//cout<<"done\n";
	while (q-->0){
		int cnt=0;
		cin>>s1>>s2;
		auto f=find(s1,s2);
		auto begin=f.first,end=f.second;
		//cout<<"test "<<s1.substr(begin,end-begin+1)<<' '<<s2.substr(begin,end-begin+1)<<' '<<s1.substr(0,begin)<<' '<<s1.substr(end+1,(int)s1.length()-end)<<'\n';
		//m[s1.substr(begin,end-begin+1)][s2.substr(begin,end-begin+1)].push_back({"1","1"});
		//cout<<"done\n";
		for (auto e : m[s1.substr(begin,end-begin+1)][s2.substr(begin,end-begin+1)]) {
			if (check(s1.substr(0,begin),e.first) and check(s1.substr(end+1,(int)s1.length()-end),e.second)) cnt++;
		}
		cout<<cnt<<'\n';
	}
}
