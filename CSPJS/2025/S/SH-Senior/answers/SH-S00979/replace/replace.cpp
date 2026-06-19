#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9,NN=5e6+9;
int next[NN][26],fail[NN],n,nq,nN;
int tag[NN];
vector<int> link[NN];
int add(string& s){
	int cur=0;
	for(int i=0;i<s.size();i++){
		int u=next[cur][s[i]-'a'];
		if(!u)next[cur][s[i]-'a']=++nN;
		cur=next[cur][s[i]-'a'];
	}
	return cur;
}
string prt(int x){
	for(int i=0;i<x;i++){
		for(int j=0;j<26;j++){
			if(next[i][j]==x){
				return prt(i)+(char)('a'+j);
			}
		}
	}
	return "";
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>nq;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		link[add(s)].push_back(add(t));
	}
	queue<int> q;
	for(int i=0;i<26;i++){
		if(next[0][i]){
			q.push(next[0][i]);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int v=next[u][i];
//			if(u==3&&i==4)cout<<"----------"<<prt(fail[u])<<" "<<prt(next[fail[u]][i])<<endl;
			if(v){
				fail[v]=next[fail[u]][i];
				q.push(v);
			}
			else{
				next[u][i]=next[fail[u]][i];
			}
		}
	}
//	cout<<prt(next[0][0])<<endl;
//	cout<<prt(next[0][1])<<endl;
//	cout<<prt(next[0][2])<<endl;
//	cout<<prt(next[0][3])<<endl;
//	cout<<prt(next[0][4])<<endl;
//	for(int i=0;i<=nN;i++){
//		cout<<prt(i)<<" "<<prt(fail[i])<<endl;
//	}
	for(int i=0;i<nq;i++){
		string s,t;
		cin>>t>>s;
		int mci=s.size()-1;
		for(;mci>=0;mci--)if(t[mci]!=s[mci])break;
		mci++;
		int ans=0;
		int cur=0;
		vector<int> tgs;
		for(int i=0;i<s.size();i++){
			cur=next[cur][s[i]-'a'];
			tag[cur]=i+1;
//			cout<<cur<<" "<<i+1<<" "<<prt(cur)<<endl;
			tgs.push_back(cur);
			int cur2=cur;
			while(cur2){
				cur2=fail[cur2];
				tag[cur2]=i+1;
//			cout<<cur2<<" "<<i+1<<" "<<prt(cur2)<<endl;
			prt(cur2);
				tgs.push_back(cur2);
			}
		}
		cur=0;
		for(int i=0;i<t.size();i++){
			cur=next[cur][t[i]-'a'];
			for(int k=0;k<link[cur].size();k++){
				if(tag[link[cur][k]]==i+1&&i>=mci)ans++;
//				,cout<<"*";
			}
//			cout<<cur<<" "<<i+1<<" "<<prt(cur)<<endl;
			prt(cur);
			tgs.push_back(cur);
			int cur2=cur;
			while(cur2){
				cur2=fail[cur2];
//				cout<<link[cur2].size()<<endl;
				for(int k=0;k<link[cur2].size();k++){
					if(tag[link[cur2][k]]==i+1&&i>=mci)ans++;
//					',cout<<"*";
				}
//			cout<<cur2<<" "<<i+1<<" "<<prt(cur2)<<endl;
			prt(cur2);
				tgs.push_back(cur2);
			}
		}
		for(int i=0;i<tgs.size();i++){
			tag[tgs[i]]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
