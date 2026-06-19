#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	int c=0,r=0;
	int a[105]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	int v=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pm=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			pm=i;
			break;
		}
	}
	c=(pm+n-1)/n;
	r=pm%(2*m);
	if(r>m){
		r=2*m-r+1;
	}
	
	
	cout<<c<<' '<<r;
	
	return 0;
}
