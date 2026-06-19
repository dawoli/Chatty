#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n,a[N][3];
struct member{
	int fst,scd,id;
	int val;
	bool operator < (const member&x) const{
		return val>x.val;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		member d[N]={};
		int cnt[3]={0,0,0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2]; d[i].id=i;
			if(a[i][0]>=a[i][1]){
				if(a[i][1]>=a[i][2]){d[i].fst=0; d[i].scd=1; d[i].val=a[i][0]-a[i][1];}
				else if(a[i][0]>=a[i][2]){d[i].fst=0; d[i].scd=2; d[i].val=a[i][0]-a[i][2];}
				else{d[i].fst=2; d[i].scd=0; d[i].val=a[i][2]-a[i][0];}
			}
			else if(a[i][0]>=a[i][2]){
				d[i].fst=1; d[i].scd=0; d[i].val=a[i][1]-a[i][0];
			}
			else if(a[i][1]>=a[i][2]){
				d[i].fst=1; d[i].scd=2; d[i].val=a[i][1]-a[i][2];
			}
			else{
				d[i].fst=2; d[i].scd=1; d[i].val=a[i][2]-a[i][1];
			}
		}
		sort(d+1,d+1+n);
		for(int i=1;i<=n;i++){
			if(cnt[d[i].fst]<n/2){
				cnt[d[i].fst]++;
				ans+=a[d[i].id][d[i].fst];
			}
			else{
				cnt[d[i].scd]++;
				ans+=a[d[i].id][d[i].scd];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
