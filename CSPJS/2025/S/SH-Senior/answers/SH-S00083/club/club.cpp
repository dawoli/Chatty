#include<bits/stdc++.h>
using namespace std;
const int N=100009;
typedef long long ll;
struct student{
	ll num,nex_num,cnt,id;
	bool operator <(const student&other) const{
		return cnt<other.cnt||cnt==other.cnt&&(num-nex_num)>(other.num-other.nex_num);
	}
} stu[N];
ll pn[4],t,nN,a[N][3],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ll T=t;
	for(ll k=1;k<=T;k++){
		cin>>nN;
		ll n=nN;
		for(ll i=1;i<=n;i++){
			stu[i].cnt=0;
			pn[i]=0;
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll max_ai=max(a[i][1],max(a[i][2],a[i][3]));
			stu[i].num=max_ai;
			stu[i].nex_num=min(max(a[i][1],a[i][2]),min(max(a[i][2],a[i][3]),max(a[i][3],a[i][1])));
			if(a[i][1]==max_ai){
				stu[i].cnt++;
				stu[i].id=1;
			}
			if(a[i][2]==max_ai){
				stu[i].cnt++;
				if(stu[i].cnt==1) stu[i].id=2;
			}
			if(a[i][3]==max_ai){
				stu[i].cnt++;
				if(stu[i].cnt==1) stu[i].id=3;
			}
		}
		sort(stu+1,stu+1+n);
		for(ll i=1;i<=n;i++){
			if(stu[i].cnt==1){
				if(pn[stu[i].id]==n/2) ans+=stu[i].nex_num;
				else{
					ans+=stu[i].num;
					pn[stu[i].id]++;
				}
			}
			else{
				ans+=stu[i].num;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
