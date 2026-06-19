#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9; 
int n,q,cnt,ls[N],rs[N]; 
vector<int>son[N];
map<pair<string,string>,int>f;
string s1[N],s2[N],t1,t2;
int find(int u,string t,int lt,int rt){
	int ans=0;
	for(int i=0;i<son[u].size();i++){
		int j=son[u][i];
		int l=lt-ls[j],r=rt+rs[j];
		if(l<0||r>=t.size())continue;
		string ta=t;
		ta.erase(r+1);
		ta.erase(0,l);
		if(ta==s1[j])ans++;
//		cout<<ta<<" ";
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l=0,r=s1[i].size()-1;
		for(;l<s1[i].size();l++)
			if(s1[i][l]!=s2[i][l])break;
		if(l>r)continue;
		for(;r>=0;r--)
			if(s1[i][r]!=s2[i][r])break;
		ls[i]=l;
		rs[i]=s1[i].size()-r-1;
		string sa,sb;
		sa=s1[i];
		sa.erase(r+1);
		sa.erase(0,l);
		sb=s2[i];
		sb.erase(r+1);
		sb.erase(0,l);
//		cout<<sa<<" "<<sb<<endl<<endl;
		pair<string,string> s=make_pair(sa,sb);
		if(!f[s])f[s]=++cnt;
		son[f[s]].push_back(i);
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=t1.size()-1;
		for(;l<t1.size();l++)
			if(t1[l]!=t2[l])break;
		for(;r>=0;r--)
			if(t1[r]!=t2[r])break;
		string ta,tb;
		ta=t1;
		ta.erase(r+1);
		ta.erase(0,l);
		tb=t2;
		tb.erase(r+1);
		tb.erase(0,l);
		pair<string,string> t=make_pair(ta,tb);
//		cout<<l<<" "<<r<<endl;
		cout<<find(f[t],t1,l,r)<<endl;
	}
	return 0;
}
