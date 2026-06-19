#include<bits/stdc++.h>
using namespace std;
int n,m,a[108],x;
int num,rw,ha;
bool cmp(int c,int d){
	return c>d; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++) scanf("%d",&a[i]);
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++) if(a[i]==x) num=i;
	rw=num/n+1;
	if(rw%2==0) ha=n-(num-(rw-1)*n);
	else ha=num-(rw-1)*n+1;
	printf("%d %d",rw,ha);
	return 0;
}
