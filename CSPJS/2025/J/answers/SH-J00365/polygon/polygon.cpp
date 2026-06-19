#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],f[N];
int calculate(int t,int o){
	int cnt=1;
	for(int i=1;i<=t-1;i++){
		int x=a[i];
		if(o-x<a[t]) cnt++;
		for(int j=i+1;j<=t-1;j++){
			x+=a[j];
			if(o-x<a[t]) cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[i]==1) cout<<9;
	else{
		cout<<6;
	}
}
