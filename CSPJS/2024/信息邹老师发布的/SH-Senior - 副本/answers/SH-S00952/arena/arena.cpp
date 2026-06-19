#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],c[N],x[18][N],ans=0,now,d[N];map<int,int>mp;
vector<int> f(vector<int>v1,vector<int>v2,int op,int num){
	int l=0,r=0;
	vector<int>v3;
	if(op==0){
		for(int i:v1){
			if(a[i]>=num||i>now)v3.push_back(i);
			if(r==0&&(a[i]<num||i>now)){r=1;for(int j:v2)v3.push_back(j);}
		}
	}
	else{
		for(int i:v2){
			if(a[i]>=num||i>now)v3.push_back(i);
			else if(l==0&&(a[i]<num||i>now)){l=1;for(int j:v1)v3.push_back(j);}
		}
	}
	//cout<<"?\n";for(int i:v1)cout<<i<<' ';cout<<endl;for(int i:v2)cout<<i<<' ';cout<<endl;for(int i:v3)cout<<i<<' ';cout<<endl;
	return v3;
}
vector<int> get(int l,int r,int k){//cout<<l<<' '<<r<<' '<<k<<"*"<<endl;
	vector<int>v1;
	if(k==0){v1.push_back(l);return v1;}
	vector<int> z=get(l,l+r>>1,k-1),y=get((l+r>>1)+1,r,k-1);
	return f(z,y,x[k][l>>k],k);
}
int main(){
	freopen("arena1.in","r",stdin);
	freopen("arena.out","w",stdout);
	int t,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",&d[i]);
	for(int i=1;i<=m;++i)scanf("%d",&c[i]);
	string s;
	int tmp=ceil(log2(n));
	for(int i=1;i<=tmp;++i){cin>>s;for(int j=0;j<s.length();++j)x[i][j]=s[j]-'0';}
	scanf("%d",&t);
	while(t--){
		int o,p,q,r;
		scanf("%d%d%d%d",&o,&p,&q,&r);
		for(int i=3;i<n;i+=4)a[i]=d[i]^o;
		for(int i=0;i<n;i+=4)a[i]=d[i]^p;
		for(int i=1;i<n;i+=4)a[i]=d[i]^q;
		for(int i=2;i<n;i+=4)a[i]=d[i]^r;//for(int i=0;i<n;++i)cout<<a[i]<<' ';cout<<endl;
		int ans1=0;
		for(int i=1;i<=m;++i){now=c[i]-1;int s=ceil(log2(c[i])),ans=0;vector<int>v=get(0,(1<<s)-1,s);for(int j:v)ans+=j+1;ans1^=ans*i;}
		cout<<ans1<<endl;
	}
}
