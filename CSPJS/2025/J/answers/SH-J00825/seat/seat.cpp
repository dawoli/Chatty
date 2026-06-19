#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[101];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==R) {
			ans=i;
			break;
		}
	}
	int c=1,r=0;
	while(ans>0) ans-=m,c++;
	ans+=m,c--;
	if(c%2==1) r+=ans;
	else r+=m-ans+1;
	cout<<c<<" "<<r;
	return 0;
}
