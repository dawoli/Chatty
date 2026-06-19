#include<bits/stdc++.h>
using namespace std;
int n,a[5005],l,mx;
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l+=a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]&&a[3]-a[1]<a[2]) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
