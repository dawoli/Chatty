#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	int n,ans=0,sum=-1,summ=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		summ+=a[i];
		if(a[i]>sum) sum=a[i];
	}
if(n<=3){
	if(summ>2*sum)cout<<1;
else cout<<0;
}	
else{
	int ans=1,anss=1;
	for(int j=1;j<=n-3;j++){
		int anss=1,ansss=1;
		for(int k=0;k<j;k++) anss*=(n-k),ansss*=(k+1);
		ans+=anss/ansss;
		
	}
	cout<<ans;
}
	return 0;
}
