#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans,a[100010],b[100010],c[100010],c1,c2,c3,l1[100010],l2[100010],l3[100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,c1=c2=c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				if(b[i]>=c[i])l1[++c1]=a[i]-b[i];
				else l1[++c1]=a[i]-c[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				if(a[i]>=c[i])l2[++c2]=b[i]-a[i];
				else l2[++c2]=b[i]-c[i];
			}
			else{
				ans+=c[i];
				if(b[i]>=a[i])l3[++c3]=c[i]-b[i];
				else l3[++c3]=c[i]-a[i];
			}
		}
		if(c1>n/2){
			sort(l1+1,l1+c1+1);
			for(int i=1;i<=c1-n/2;i++)ans-=l1[i];
		}
		if(c2>n/2){
			sort(l2+1,l2+c2+1);
			for(int i=1;i<=c2-n/2;i++)ans-=l2[i];
		}
		if(c3>n/2){
			sort(l3+1,l3+c3+1);
			for(int i=1;i<=c3-n/2;i++)ans-=l3[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
