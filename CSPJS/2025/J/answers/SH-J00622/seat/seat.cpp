#include<iostream>
#include<cmath>
using namespace std;
int n,m,i,j,k,c,r,t,a,s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>t;
		if(i==1)a=t;
		j=1;
		while(s[j]>t)j++;
		for(k=i;k>j;k--)s[k]=s[k-1];
		s[j]=t;
	}
	for(i=1;i<=n*m;i++)if(s[i]==a){
		a=i;break;
	}
	c=ceil(a*1.0/n);
	if(c%2==1)r=(a-1)%n+1;
	else r=n-(a-1)%n;
	cout<<c<<' '<<r;
	return 0;
}
