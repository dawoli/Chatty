#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,z;
	cin>>n>>m;
	y=n*m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+y+1);
	for(int i=1;i<=y;i++){
		if(a[i]==x){
			z=i;
			break;
		}
	}
	z=y+1-z;
	int Line,Row;
	if(z%n==0)Line=z/n;
	else Line=z/n+1;
	if(Line%2==1){
		if(z%n==0)Row=n;
		else Row=z%n;
	}
	else {
		if(z%n==0)Row=1;
		else Row=n+1-z%n;
	}
	cout<<Line<<" "<<Row;
	return 0;
} 
