#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int t,n;
ll a[123456][7],ans;
int cl1[123456],cl2[123456],cl3[123456],cnt1,cnt2,cnt3,cl[123456];
struct node{
	ll val;
	int idx;
}trs[123456];
bool operator<(const node&x,const node&y){
	return x.val<y.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;cnt1=0;cnt2=0;cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>a[i][3]){
				ans+=a[i][1];
				cl1[++cnt1]=i;
				cl[i]=1;
				trs[i].val=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				trs[i].idx=i;
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				ans+=a[i][2];
				cl2[++cnt2]=i;
				cl[i]=2;
				trs[i].val=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				trs[i].idx=i;
			}
			else{
				ans+=a[i][3];
				cl3[++cnt3]=i;
				cl[i]=3;
				trs[i].val=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				trs[i].idx=i;
			}
		}
		sort(trs+1,trs+n+1);
		if(cnt1>n/2){
			int x=cnt1-n/2;
			for(int i=1;i<=n;i++){
				if(x==0)break;
				if(cl[trs[i].idx]!=1)continue;
				ans-=trs[i].val;
				x--;
			}
		}
		else if(cnt2>n/2){
			int x=cnt2-n/2;
			for(int i=1;i<=n;i++){
				if(x==0)break;
				if(cl[trs[i].idx]!=2)continue;
				ans-=trs[i].val;
				x--;
			}
		}
		else if(cnt3>n/2){
			int x=cnt3-n/2;
			for(int i=1;i<=n;i++){
				if(x==0)break;
				if(cl[trs[i].idx]!=3)continue;
				ans-=trs[i].val;
				x--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
