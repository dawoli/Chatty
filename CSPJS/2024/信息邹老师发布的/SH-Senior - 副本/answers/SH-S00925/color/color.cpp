#include<bits/stdc++.h>
using namespace std;

int t,n,a[200010],c[200010],lastl,lasth,sum,ans;

int main()
{
	freopen("color.in","r",stdin);//
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long s=0;s<(1<<n);s++){
			lastl=lasth=0;
			memset(c,0,sizeof(c));
			for(int i=n;i>=1;i--){
				if((s>>i-1)&1){
					if(a[i]==a[lastl])c[i]=a[i];
					lastl=i; 
					//cout<<1;
				}
				else {
					if(a[i]==a[lasth])c[i]=a[i];
				    lasth=i; 
				    //cout<<0;
				}
			}
			//cout<<endl;
			sum=0;
			for(int i=1;i<=n;i++)sum+=c[i];
			//cout<<sum<<endl;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
