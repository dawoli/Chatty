#include <bits/stdc++.h>
using namespace std;
int n,m,R;
int k,ax,ay;
int s[150];
int g[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	s[1] = R;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i] == R){
			k = i;
			break;
		}
	}
	ax = k/m;
	if(k%m) ax++;
	if(ax%2){
		ay = k%m;
		if(ay==0) ay = m;
	}else{
		ay = n-k%m+1;
		if(ay==m+1) ay = 1;
	}
	cout<<ax<<' '<<ay;
	return 0;
}
