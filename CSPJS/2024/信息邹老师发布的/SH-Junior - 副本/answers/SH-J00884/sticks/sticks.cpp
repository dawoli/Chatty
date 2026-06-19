#include<bits/stdc++.h>
using namespace std;
const int mxn=1e7;
int c[10]={-1,-1,1,7,4,2,0};
int n,t;
int dfs(int s,int h,int x){
	if(s==x){
		if(x==1 && h==6) return 6;
		if(h<2 || h>6) return -1;
		return c[h];
	}
	int mx=mxn;
	for(int i=2;i<=6;i++){
		if((x-s)*6<h-i) continue;
		if((h-i)<2*(x-s)) break;
		int y=dfs(s+1,h-i,x),p=pow(10,x-s);
		if(y==-1) continue;
		if(s==1 && i==6) mx=min(mx,6*p+y);
		else mx=min(mx,c[i]*p+y);
	}
	if(mx<mxn) return mx;
	else return -1;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;continue;
		}
		if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;continue;
		}
		int x=n/7+1,y=n%7,z=min(x-1,6-y),p=pow(10,z),k=1,s=1,mn=mxn,q;
		if(y>1) mn=c[y]*p,q=1;
		for(int i=1;i<=z;i++){
			p/=10;
			int b=dfs(1,y+i*7,i+1)*p;
			if(mn>b){
				mn=b;
				q=i+1;
			}
		}
		int qq=pow(10,z-q+1);
		cout<<mn/qq;
		for(int i=1;i<=x-q;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}
