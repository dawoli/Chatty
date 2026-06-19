#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,m,a[N],b,c,l,r;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==b)c=i;
	l=(c-1)/n+1;
	if(l%2==1) r=(c-1)%n+1;
	else r=n-(c-1)%n;
	cout<<l<<" "<<r;
	return 0;
}
