#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;
int n,a[N],b[N],c[N],sum1,sum2,ans,o[4],p[4];

void solve(){
	cin>>n;
	if(n==2){
		cin>>o[1]>>o[2]>>o[3]>>p[1]>>p[2]>>p[3];
		int ma1=max({o[1],o[2],o[3]});
		int ma2=max({p[1],p[2],p[3]});
		sort(o+1,o+1+n);
		sort(p+1,p+1+n);
		int mi1=o[2];
		int mi2=p[2];
		cout<<max(ma1+mi2,ma2+mi1);
	}
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
		sum1+=b[i],sum2+=c[i];
	}
	if(sum1==0&&sum2==0){
		sort(a+1,a+1+n,greater<>());
		for(int i=1;i<=n/2;++i){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
