#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
ll a[N][3];
bool cmp(ll a,ll b){
	return a<=b;
}
void solve(){
	int n;
	vector<ll> a1,a2,a3;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int a0_1=abs(a[i][0]-a[i][1]);
		int a0_2=abs(a[i][0]-a[i][2]);
		int a1_2=abs(a[i][1]-a[i][2]);
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
			ans+=a[i][0];
			a1.push_back(min(a0_1,a0_2));
		}
		else if(a[i][1]>a[i][2]&&a[i][1]>a[i][0]){
			ans+=a[i][1];
			a2.push_back(min(a0_1,a1_2));
		}
		else{
			ans+=a[i][2];
			a3.push_back(min(a0_2,a1_2));
		}
	}
	int avg=n/2,la1=a1.size(),la2=a2.size(),la3=a3.size();
	if(la1>avg){
		sort(a1.begin(),a1.end(),cmp);
		for(int i=0;i<la1-avg;i++){
			ans-=a1[i];
		}
	}else if(la2>avg){
		sort(a2.begin(),a2.end(),cmp);
		for(int i=0;i<la2-avg;i++){
			ans-=a2[i];
		}
	}else if(la3>avg){
		sort(a3.begin(),a3.end(),cmp);
		for(int i=0;i<la3-avg;i++){
			ans-=a3[i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


