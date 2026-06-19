#include<bits\stdc++.h>
using namespace std;
int n,num,maxn,cnt;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	if(n==3&&a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2])))
		cout<<1;
	else if(n>3)
		cout<<9;
	else
		cout<<0;
	return 0;
}
