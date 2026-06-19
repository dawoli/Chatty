#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){//50分算法 
		int ans=-1;
		int a[200010];
		int yise[200010]={};
		cin>>n;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=2;j<=n;j++){
			for(int k=0;k<=j-2;k++){//异色 
				int n=yise[k];
				if(a[j]==a[k])n+=a[j];
				yise[j-1]=max(yise[j-1],n);
			}
			if(a[j]==a[j-1])//同色
			    for(int k=0;k<=j-2;k++)yise[k]+=a[j];
		}
		for(int j=0;j<=n-1;j++){
			ans=max(ans,yise[j]);
		}
		cout<<ans<<endl;
	} 
	return 0;
}
