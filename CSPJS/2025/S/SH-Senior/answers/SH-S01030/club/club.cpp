#include<bits/stdc++.h>
using namespace std;
int a[100005][3],d[100005],f[3],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		int m=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				d[i]=0;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				d[i]=1;
			}
			else{
				d[i]=2;
			}
		}
		int k=0;
		for(int i=0;i<n;i++)f[d[i]]++;
		for(int i=0;i<n;i++)ans+=a[i][d[i]];
		if(f[0]>m){
			k=f[0]-m;
			for(int i=0;i<n;i++){
				if(d[i]==0)c[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				else c[i]=INT_MAX; 
			}
		}
		else if(f[1]>m){
			k=f[1]-m;
			for(int i=0;i<n;i++){
				if(d[i]==1)c[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				else c[i]=INT_MAX; 
			}
		}
		else if(f[2]>m){
			k=f[2]-m;
			for(int i=0;i<n;i++){
				if(d[i]==2)c[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
				else c[i]=INT_MAX; 
			}
		}
		sort(c,c+n);
		for(int i=0;i<k;i++){
			ans-=c[i];
		}
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
	} 
	return 0;
} 
