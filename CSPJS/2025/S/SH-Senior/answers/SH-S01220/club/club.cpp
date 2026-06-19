#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
ll t,n,a[N][4],ans,s[N],d[N],tot,cnt[4];
bool is230=1,is30=1;
ll solve2(){
	ll x=max(a[1][1]+a[2][2],a[1][1]+a[2][3]),
	y=max(a[1][2]+a[2][1],a[1][2]+a[2][3]),
	z=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
	ans=max(x,max(y,z));
	return ans;
}
ll solve230(){
	for(ll i=1;i<=n;i++) s[i]=a[i][1];
	sort(s+1,s+1+n);
	for(ll i=n;i>n/2;i--) ans+=s[i];
	return ans;
}
ll solve30(){
	ll cnt1=0,cnt2=0,equal=0;
	for(ll i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){cnt1++;ans+=a[i][1];}
		else if(a[i][1]<a[i][2]){cnt2++;ans+=a[i][2];}
		else{ans+=a[i][1];equal++;}
	}
	if(cnt1<=n/2 and cnt2<=n/2) return ans;
	tot=0;
	if(cnt1<cnt2){
		cnt1+=equal;
		for(ll i=1;i<=n;i++)
			if(a[i][2]>a[i][1])
				d[++tot]=a[i][2]-a[i][1];
		sort(d+1,d+1+tot);
		for(ll i=1;i<=cnt2-n/2;i++) ans-=d[i];
	}
	else{
		cnt2+=equal;
		for(ll i=1;i<=n;i++)
			if(a[i][1]>a[i][2])
				d[++tot]=a[i][1]-a[i][2];
		sort(d+1,d+1+tot);
		for(ll i=1;i<=cnt1-n/2;i++) ans-=d[i];
	}
	return ans;
}
ll solve(){
	//最多只有一组>n/2
	//先对于每个i取最大值
	//再对于超过的一组做调整
	//将所有损失记入数组，并从小到大排序
	//从小到大选取最小损失
	cnt[1]=0,cnt[2]=0,cnt[3]=0,tot=0;
	for(ll i=1;i<=n;i++){
		ll tem=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=tem;
		if(tem==a[i][1] and tem!=a[i][2] and tem!=a[i][3]) cnt[1]++;
		else if(tem==a[i][2] and tem!=a[i][1] and tem!=a[i][3]) cnt[2]++;
		else if(tem==a[i][3] and tem!=a[i][1] and tem!=a[i][2]) cnt[3]++;
	}
	ll EXP;
	if(cnt[1]>=cnt[2] and cnt[1]>=cnt[3]) EXP=1;
	else if(cnt[2]>=cnt[1] and cnt[2]>=cnt[3]) EXP=2;
	else EXP=3;
	if(cnt[EXP]<=n/2) return ans;
	if(EXP==1){
		for(ll i=1;i<=n;i++){
			if(a[i][1]>a[i][2] and a[i][2]>a[i][3]) d[++tot]=a[i][1]-a[i][2];
			else if(a[i][1]>a[i][3] and a[i][3]>a[i][2]) d[++tot]=a[i][1]-a[i][3];
		}
		sort(d+1,d+1+tot);
		for(ll i=1;i<=cnt[EXP]-n/2;i++) ans-=d[i];
	}
	else if(EXP==2){
		for(ll i=1;i<=n;i++){
			if(a[i][2]>a[i][1] and a[i][1]>a[i][3]) d[++tot]=a[i][2]-a[i][1];
			else if(a[i][2]>a[i][3] and a[i][3]>a[i][1]) d[++tot]=a[i][2]-a[i][3];
		}
		sort(d+1,d+1+tot);
		for(ll i=1;i<=cnt[EXP]-n/2;i++) ans-=d[i];
	}
	else if(EXP==3){
		for(ll i=1;i<=n;i++){
			if(a[i][3]>a[i][2] and a[i][2]>a[i][1]) d[++tot]=a[i][3]-a[i][2];
			else if(a[i][3]>a[i][1] and a[i][1]>a[i][2]) d[++tot]=a[i][3]-a[i][1];
		}
		sort(d+1,d+1+tot);
		for(ll i=1;i<=cnt[EXP]-n/2;i++) ans-=d[i];
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,is230=1,is30=1;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 or a[i][3]!=0) is230=0;
			if(a[i][3]!=0) is30=0;
		}
		if(n==2) cout<<solve2();
		else if(is230) cout<<solve230();
		else if(is30) cout<<solve30();
		else cout<<solve();
		cout<<endl;
	}
	return 0;
}
