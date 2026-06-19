#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
int n=0,m=0;
int a[105]={};
bool cmp(int a,int b){
	return a>b;
}
int s=0;
int i;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int ii=1;ii<=n*m;ii++){
		cin>>a[ii];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=n*m;j++){
		if(a[j]==s) i=j;
	}
	int c=i/n+1;
	i%=n;
	if(i==0){
		c--;
		i=n;
	} 
	if(c%2==1){
		cout<<c<<" "<<i;
	
	}
	else{
		cout<<c<<" "<<n+1-i;
	}
	return 0;
} 
