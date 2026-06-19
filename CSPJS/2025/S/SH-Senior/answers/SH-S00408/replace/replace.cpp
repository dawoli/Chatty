#include<bits/stdc++.h>
using namespace std;
int n,q,pi[2000009];
vector<int> p[800009];
string s1[200009],s2[200009];
void cal_p(string x,int id) {
	p[id].push_back(0);
	for(int i=1;i<x.size();i++) {
		int j=p[id][i-1];
		while(j&&x[i]!=x[j]) j=p[id][j];
		if(x[i]==x[j]) j++;
		p[id].push_back(j);
		//cout<<p[id][i]<<" ";
	}
}
bool comp(string s,int id,string nd) {
	int mx=max(s.size(),s1[id].size());
	for(int i=0;i<=mx;i++) pi[i]=0;
	if(s[0]==s1[id][0]) pi[0]=1;
	for(int i=1;i<s.size();i++) {
		int j=pi[i-1];
		if(j==s1[id].size()) {
			if(s1[id][0]==s[i]) {
				pi[i]=1;
			}
			else pi[i]=0;
			continue;
		}
		while(j&&s1[id][j]!=s[i]) j=p[id][j-1];
		if(s1[id][j]==s[i]) j++;
		pi[i]=j;
	//	cout<<pi[i]<<" "<<i<<"\n";
	}
	//cout<<44353<<"\n";
	string tmp=s;
	for(int i=0;i<s.size();i++) {
		if(pi[i]==s1[id].size()) {
			for(int j=i-s1[id].size()+1,now=0;j<=i;j++,now++) {
				tmp[j]=s2[id][now];
			}
			if(tmp==nd) return true;
		}
		tmp=s;
	}//±È½ÏtmpÓës2 
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>=100000) {
		for(int i=1;i<=q;i++) cout<<0<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		cal_p(s1[i],i);
		//cal_p(s2[i],i*2);
	}
	for(int i=1;i<=q;i++) {
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++) {
			if(comp(t1,j,t2)) ans++;
			//cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
