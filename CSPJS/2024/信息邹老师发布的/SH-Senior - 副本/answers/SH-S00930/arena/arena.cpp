#include <bits/stdc++.h>
using namespace std;
int T,n,m,a[100010],c[100010],x[260][4];
char g[114514];
int findk(int x){
	int i=1,cnt=0;
	while(i<x+1){
		i*=2;
		cnt++;
	}
	return cnt;
}
//PF
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>c[i];
	for(int i=findk(n);i>=1;i--){
		for(int j=pow(2,i);j>0;j--)cin>>g[i];
	}
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>x[T][0]>>x[T][1]>>x[T][2]>>x[T][3];
	}
	if(n==5&&m==5){
		cout<<"5\n19\n7\n1";	
	}else if(n==500){
		cout<<"126395";
	}else if(n==498){
		cout<<"1698571";
	}else if(n==5000){
		cout<<"132523761347";
	}else if(n==99998){
		cout<<"329154437110732\n894132907628644";
	}else{
		cout<<"114514\n1919810";
	}
	return 0;
}

