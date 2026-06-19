#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
const ll N=1e5+9;
ll n,a[N][4],s1[N],s2[N],s3[N],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ll cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])s1[++cnt1]=i,ans+=a[i][1];
			else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])s2[++cnt2]=i,ans+=a[i][2];
			else s3[++cnt3]=i,ans+=a[i][3];
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++){
				sort(a[s1[i]]+1,a[s1[i]]+4);
				b[i]=a[s1[i]][3]-a[s1[i]][2];
			}
			sort(b+1,b+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++)
				ans-=b[i];
		}
		if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++){
				sort(a[s2[i]]+1,a[s2[i]]+4);
				b[i]=a[s2[i]][3]-a[s2[i]][2];
			}
			sort(b+1,b+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++)
				ans-=b[i];
		}
		if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++){
				sort(a[s3[i]]+1,a[s3[i]]+4);
				b[i]=a[s3[i]][3]-a[s3[i]][2];
			}
			sort(b+1,b+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++)
				ans-=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
