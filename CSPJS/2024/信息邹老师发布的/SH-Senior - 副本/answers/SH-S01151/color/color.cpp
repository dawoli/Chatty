#include<bits/stdc++.h>
using namespace std;

int t,cnt[1000005];

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		long long n,ans=0,a[200005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt[a[i]]++;
		}
		for(int i=1;i<=n;i++)
			if(cnt[i]>1) ans+=(cnt[i]-1)*i;
		cout<<ans<<endl;
	}
}
