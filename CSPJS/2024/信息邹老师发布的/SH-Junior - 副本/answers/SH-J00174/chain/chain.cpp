#include<bits/stdc++.h> 
using namespace std;
struct piii{int st,nd,rd;};
const int N=1e5,M=2e5+1;
int t,n,k,qt,l[N],r[N],c[N];//*
vector<int> s[N];
vector<piii> e[M];
set<int> a[101];
queue<piii> q;//*/
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k>>qt;
		for(int i=0;i<M;i++)e[i].clear();
		for(int i=0;i<n;i++){
			cin>>l[i];s[i].clear();
			for(int j=0;j<l[i];j++){
				int ii;cin>>ii;//*
				s[i].push_back(ii);
				for(int jj=j-1;jj>=0&&j-jj<k;jj--)
					e[s[i][jj]].push_back((piii){ii,i,-1});//*/
			}
		}//*
		for(int i=0;i<101;i++)a[i].clear();
		q.push((piii){0,1,-1});
		int mxr=-1;//OK10,15
		for(int i=0;i<qt;i++){
			cin>>r[i]>>c[i];mxr=max(mxr,r[i]);
		}
		mxr=min(mxr,15);
		while(!q.empty()){
			piii pp=q.front();q.pop();
			int r=pp.st,c=pp.nd,p=pp.rd;
			a[r].insert(c);
//			cout<<"h"<<r<<endl;
			if(r>=mxr)continue;
			for(int i=0;i<e[c].size();i++)
				if(e[c][i].nd!=p)
					q.push((piii){r+1,e[c][i].st,e[c][i].nd});
		}//*/
//		cout<<"hi"<<endl;
		for(int i=0;i<qt;i++)cout<<a[r[i]].count(c[i])<<endl;
	} 
	return 0;
}
