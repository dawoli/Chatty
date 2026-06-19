#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n;
int a[N];
int ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i+2;k<=n;k++)
				if(a[i]+a[j]+a[k]==a[k]*2) ans++;
	for(int i=4;i<n;i++) ans+=i;			
	cout<<ans+1;
	return 0;
}
