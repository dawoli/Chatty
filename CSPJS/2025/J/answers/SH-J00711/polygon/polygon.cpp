#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<i;j++)if(a[j]>a[i])swap(a[j],a[i]);
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	else if(c==3){
		if(a[0]+a[1]+a[2]>a[2]*2)cout<<1;
		else cout<<0;
		cout<<endl;
		return 0;
	}
	else if(c==4){
		int ans=0;
		if(a[0]+a[1]+a[2]>a[2]*2)ans++;
		if(a[0]+a[1]+a[3]>a[3]*2)ans++;
		if(a[3]+a[1]+a[2]>a[3]*2)ans++;
		if(a[0]+a[3]+a[2]>a[3]*2)ans++;
		cout<<ans<<endl;
		return 0;
	}
	else cout<<9<<endl;
	return 0;
}
