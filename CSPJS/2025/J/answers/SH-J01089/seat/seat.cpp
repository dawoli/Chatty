#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num,a[105],my,l=1,r,mid,rank,x,y,e;
double d;
bool b=1;
bool cmp(int o,int p){
	return o>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	r=num=n*m;
	for(int i=1;i<=num;i++) cin>>a[i];
	my=a[1];
	sort(a+1,a+num+1,cmp);
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]>my) l=mid+1;
		if(a[mid]<my) r=mid-1;
		if(a[mid]==my){
			rank=mid;
			b=0;
			break;
		}
	}
	if(b) rank=l;
	d=ceil( ((double)rank) / ((double)n) );
	y=int(d);
	e=rank-((y-1)*n);
	if(y%2==0) x=n+1-e;
	else x=e;
	cout<<y<<" "<<x;
} 

