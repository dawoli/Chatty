#include<bits/stdc++.h>
using namespace std;
int c,n,cnt=0,w;
int a[5090];
int data[5090];
void dfs(int x){
	if(x==c){
		int sum=0,maxs=0;
		for(int i=1;i<x;i++){
//			cout<<data[i]<<' ';
			sum+=a[data[i]];
			maxs=max(maxs,a[data[i]]);
//			cout<<data[x]<<' ';
		}
		if(sum>2*maxs){
			cnt++;
//			cout<<"T";
		}
//		cout<<'\n';
		return;
	}
	for(int i=data[x-1]+1;i<=w;i++){
		data[x]=i;
//		cout<<data[x]<<' '<<data[x-1];
		dfs(x+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=w;j++){
			if(x==a[j]){
				continue;
			}
		}
		w++;
		a[w]=x;
	}
	sort(a+1,a+1+w);
//	for(int i=1;i<=w;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
	for(int i=3;i<=n;i++){
		c=i+1;
		dfs(1);
	}
	cout<<cnt;
	return 0;
}

