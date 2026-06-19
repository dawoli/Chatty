#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int a[10010],nw,ls=INT_MAX;
int n,t,weimin=INT_MAX;
void dfs(int x,int sum){
	if(sum==1){
		return;
	}
	if(sum==0){
		if(x>weimin){
			return;
		} 
		nw=a[1];
		for(int i=2;i<x;i++){
			nw=nw*10+a[i];
		}
		if(nw<ls) ls=nw;
		weimin=x;
//		for(int i=1;i<x;i++) cout<<a[i];
//		cout<<endl;
		return ;
	}
	for(int i=0;i<10;i++){
		if(i==0&&x==1) continue; 
		if(sum>=num[i]){
			a[x]=i;
			dfs(x+1,sum-num[i]);
			a[x]-=i;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));nw=0;ls=INT_MAX;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(n%7==1&&n!=1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		dfs(1,n);
		cout<<ls<<endl;
	}
	return 0;

} 
