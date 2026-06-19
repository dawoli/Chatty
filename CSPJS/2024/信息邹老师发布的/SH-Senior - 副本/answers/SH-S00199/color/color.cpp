#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[2000010],b[2000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long ans=0;
		for(int j=1;j<=n;j++)b[j]=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			b[a[j]]++;
		}
		//for(int j=1;j<=n;j++)cout<<b[j];
		//cout<<endl;
		for(int j=1;j<=n;j++){
			if(b[j]>1)ans+=j;
		}
		cout<<ans<<endl;
	}	
	
	return 0;
}
