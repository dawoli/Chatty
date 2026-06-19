#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T; 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int a[10005];int n;
		cin>>n;
		for(int j=1;j<=n;j++)cin>>a[j];
		bool pd=false;
		for(int j=1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k])pd=true;
			}
		if(pd==false){
		cout<<0<<endl;continue;
		}
		int zonghe[1000];int sum=0;
		memset(zonghe,0,sizeof(zonghe));
		for(int j=1;j<=n;j++)zonghe[a[j]]++;
		for(int j=1;j<=999;j++)if(zonghe[j]>1)sum+=j*zonghe[j]-j;
		cout<<sum<<endl;	
	}
	return 0;
}
