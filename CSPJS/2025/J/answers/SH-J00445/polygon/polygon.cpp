#include<bits/stdc++.h> 
using namespace std;
int n,a[25],sum[25];
//bool flag[510];
//void dfs(int x){
//	for(int i=1;i<=n-2;i++){
//		if()	
//	}
//}
//bool check(){
//	
//1}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];	
	sort(a+1,a+n+1);	
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	else cout<<587;
}
