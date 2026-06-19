#include <bits/stdc++.h>
using namespace std;
int a[225],b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int n,m,f;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		f=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	int xs=1,mx=1;
	for(int i=1;i<=n*m;i++){
		int flag=0;
		if(a[i+1]==f&&n*m%2==1){
			cout << mx << " "<< xs;
			return 0;
		}
		if(n*m%2==0&&a[i]==f){
			cout << mx << " " << xs;
			return 0;
		}
		if(mx%2==1&&xs<n){
			xs+=1; 
			flag=1;  
		}  
		if(mx%2==0&&xs>1&&flag==0){
			xs-=1;
		}   
		if(xs==n&&mx<=m&&flag==0){
			mx+=1;
			flag=1;
		}         
		if(xs==1&&mx<=m&&flag==0){
			mx+=1;
			flag=1;
		}                          
	}
	return 0;
}
