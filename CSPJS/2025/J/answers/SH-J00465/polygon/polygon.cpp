#include<bits/stdc++.h>
using namespace std;
long long counter=0;
const long long MOD=998244353; 
void dfs(long long n,vector<long long> &v,long long div,
		vector<bool> &pal,vector<long long> &a,long long dep){
	if(a.size()>div) return;
	if(a.size()==div){
		long long sum=0;
		long long maxn=-1;
		for(long long i=0;i<a.size();i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(div>=3&&sum>2*maxn){
			/*
			for(int i=0;i<a.size();i++){
				cout<<a[i]<<" ";
			}
			*/
			//cout<<endl;
			counter++;
		}
		return;
		
	} 
	for(long long i=dep;i<n;i++){
		if(pal[i]==false){
			pal[i]=true;
			a.push_back(v[i]);
			long long x=dep;
			dep=(i+1);
			dfs(n,v,div,pal,a,dep);
			dep=x;
			pal[i]=false;
			a.pop_back();
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	vector<long long> v(n+5);
	vector<long long> a; 
	vector<bool> pal(n+5);
	for(long long i=0;i<n;i++){
		cin>>v[i];
		pal[i]=false;
	}
	for(long long i=3;i<=n;i++){
		dfs(n,v,i,pal,a,0);
	}
	cout<<counter%MOD<<endl;
	return 0;
}
