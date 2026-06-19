#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//’Î∂‘B
const int MAXN=2e5+5;
const int MAXM=5e6+5;
struct Node{
	int l,r;
	long long len;
};
vector<Node> vz[MAXM];
vector<Node> vf[MAXM];
int n,q;
string s1,s2;
string t1,t2;
int l,r;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int i=1;i<=s1.size();i++){
			if(s1[i]=='b')l=i;
			if(s2[i]=='b')r=i;
			//if(s1[i]!='a'&&s1[i]!=b)
		}
		if(l>=r)vz[l-r].push_back({l,r,s1.size()});
		else if(l<r)vf[r-l].push_back({l,r,s1.size()});
		//cout<<l<<' '<<r<<endl;
	}
	/*
	for(int i=1;i<=3;i++){
		for(auto u:vf[i]){
			cout<<u.l<<u.r<<u.len<<endl;
		}
	}
	*/
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue ;
		}
		for(int i=1;i<=t1.size();i++){
			if(s1[i]=='b')l=i;
			if(s2[i]=='b')r=i;
			//if(s1[i]!='a'&&s1[i]!=b)
		}
		int len=t1.size();
		//cout<<l<<' '<<r<<endl;
		if(l>=r){
			for(auto u:vz[l-r]){
				if(l>=u.l&&len-l>=u.len-u.l&&r>=u.r&&len-r>=u.len-u.r)cnt++;
			}
		}
		else if(l<r){
			for(auto u:vf[r-l]){
				if(l>=u.l&&len-l>=u.len-u.l&&r>=u.r&&len-r>=u.len-u.r)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
