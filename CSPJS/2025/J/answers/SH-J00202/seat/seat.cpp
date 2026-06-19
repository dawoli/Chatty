#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int grade=a[1],cnt=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i;i--){
		cnt++;
		if(a[i]==grade)break;
	}
	int d=1,r=0,c=1;
	for(int i=1;i<=cnt;i++){
		if(i!=1&&(i-1)%n==0)d=-d,c++;
		else r+=d;
	}
	cout<<c<<' '<<r;
	return 0;
}
