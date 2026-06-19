#include<bits/stdc++.h>
using namespace std;
int n,a[50],cnt,sumnum,max_n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];

	for(int i=1;i<=n;i++){
		sumnum+=a[i];
		max_n=max(a[i],max_n);
	}
	if(sumnum>2*max_n)	cnt++;
	cout<<cnt;
	return 0;
}
