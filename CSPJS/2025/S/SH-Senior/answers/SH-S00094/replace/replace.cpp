#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define M 5300009
#define ll long long
ll n,q,ans,f[M];
string s1[N],s2[N],t1[N],t2[N];
void sol1(){
	string x=t1[1],y=t2[1];
	for(int i=1;i<=n;i++){
		string u=x+"#"+s1[i],v=y+"#"+s2[i];
//		cout<<u<<v;
		fill(f,f+u.size()+9,-1);
		vector<int>v1,v2;
		for(int k=1;k<u.size();k++){
			int j=f[k-1];
			while(u[j+1]!=u[k]&&j>=0)j=f[j];
			if(u[j+1]==u[k])f[k]=f[j]+1;
		}
		for(int t=0;t<u.size();t++)cout<<f[t]<<" ";
		for(int k=x.size()+1;k<u.size();k++)
			if(f[k]==x.size())v1.push_back(k);
		fill(f,f+v.size()+9,-1);
		for(int k=1;k<v.size();k++){
			int j=f[k-1];
			while(v[j]!=v[k]&&j>=0)j=f[j];
			if(v[j]==v[k])f[k]=f[j]+1;
		}
		for(int k=y.size()+1;k<v.size();k++)
			if(f[k]==y.size())v2.push_back(k);
//		for(auto t:v1)cout<<t<<"\n";
//		for(auto t:v2)cout<<t<<"\n";
		int m1=0,m2=0,ans1=0;
		while(m1<v1.size()&&m2<v2.size()){
			while(v1[m1]<v2[m2]&&m1<v1.size()-1)m1++;
			if(v1[m1]==v2[m2])ans1++;
			m2++; 
		}
		cout<<ans1<<"\n";
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
//		L1+=(s1.size()+s2.size());
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
//		L2+=(t1.size()+t2.size());
	}
	if(q==1)sol1();
	return 0;
} 
