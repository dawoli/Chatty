#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int tar=a[1],p=0;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==tar){
		p=i;
	}
	int l=((p-1)/n)+1;
	int h=(l%2?(p-1)%n+1:n-((p-1)%n));
	cout<<l<<" "<<h<<endl;
	return 0;
}
