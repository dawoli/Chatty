#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[109];//n 行 ，m 列 
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int x=a[0],y;
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==x){
			y=n*m-i;
			break;
		} 
	}
	cout<<y<<endl;
	int b,c;//b 行，c 列 
	if(y%n)
		b=y/n+1;
	else
		b=y/n;
	if(b%2)
		c=y%(2*n);
	else
		c=n-((y+n)%(2*n))+1;
	cout<<b<<" "<<c;
	return 0;
}
