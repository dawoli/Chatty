#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define up(i,a,b) for (ll i=(a);i<=(b);++i)
#define down(i,a,b) for (ll i=(a);i>=(b);--i)
const ll N=1e5+10;
const ll INF=1e16;
ll T,n;
struct Member{
	ll lova,lovb,lovc;
	ll id;
	ll bstID[3]; //喜欢的社团的编号顺序 
	ll minCost[3]; //从i号社团离开需要的最小代价
	ll minCostID[3]; //从i号社团离开需要的最小代价是去哪一个社团 
} a[N];
struct GTBSTID{
	ll id;
	ll lov;
	bool operator <(const GTBSTID &b) const{
		return lov>b.lov;
	}
} bst[3];
void GetBstID(ll i) {
	bst[0].id=0;
	bst[0].lov=a[i].lova;
	bst[1].id=1;
	bst[1].lov=a[i].lovb;
	bst[2].id=2;
	bst[2].lov=a[i].lovc;
	sort(bst,bst+3);
	up(j,0,2) {
		a[i].bstID[j]=bst[j].id;
	}
}
void GetMinCost(ll i) {
	a[i].minCost[0]=INF;
	ll lova=a[i].lova,lovb=a[i].lovb,lovc=a[i].lovc;
	if (lova>=lovb) {
		if (lova-lovb<=a[i].minCost[0]) {
			a[i].minCost[0]=lova-lovb;
			a[i].minCostID[0]=1;
		}
	}
	if (lova>=lovc) {
		if (lova-lovc<=a[i].minCost[0]) {
			a[i].minCost[0]=lova-lovc;
			a[i].minCostID[0]=2;
		}
	}
	a[i].minCost[1]=INF;
	if (lovb>=lova) {
		if (lovb-lova<=a[i].minCost[1]) {
			a[i].minCost[1]=lovb-lova;
			a[i].minCostID[1]=0;
		}
	}
	if (lovb>=lovc) {
		if (lovb-lovc<=a[i].minCost[1]) {
			a[i].minCost[1]=lovb-lovc;
			a[i].minCostID[1]=2;
		}
	}
	a[i].minCost[2]=INF;
	if (lovc>=lova) {
		if (lovc-lova<=a[i].minCost[2]) {
			a[i].minCost[2]=lovc-lova;
			a[i].minCostID[2]=0;
		}
	}
	if (lovc>=lovb) {
		if (lovc-lovb<=a[i].minCost[2]) {
			a[i].minCost[2]=lovc-lovb;
			a[i].minCostID[2]=1;
		}
	}
}
struct MemberQueue{
	ll id;
	ll cost;
	bool operator <(const MemberQueue &b) const{
		return cost>b.cost;
	}
};
priority_queue<MemberQueue> q[3];
ll ans[N];
bool AssignClub(ll memberID,ll clbID) { //让memberID去clbID社团 
	if (q[clbID].size()<n/2) {
		q[clbID].push((MemberQueue){memberID,a[memberID].minCost[clbID]});
		ans[memberID]=clbID;
		return true;
	}
	//人满了 
	ll curCost=a[memberID].minCost[clbID];
	ll hdCost=q[clbID].top().cost;
	ll hdID=q[clbID].top().id;
	if (curCost>hdCost) { //把代价最低的人挤掉 
		q[clbID].pop();
		ll leaveTo=a[hdID].minCostID[clbID];
		AssignClub(hdID,leaveTo); //一定可以分配成功 
		q[clbID].push((MemberQueue){memberID,a[memberID].minCost[clbID]});
		ans[memberID]=clbID;
		return true;
	}
	//他应该去别的社团 
	return false;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--) {
		up(ch,0,2) {
			while (!q[ch].empty()) {
				q[ch].pop();
			}
		}
		cin>>n;
		up(i,1,n) {
			cin>>a[i].lova>>a[i].lovb>>a[i].lovc; 
			a[i].id=i;
			GetBstID(i);
			GetMinCost(i);
		}
		up(i,1,n) {
			up(ch,0,2) {
				bool f=AssignClub(i,a[i].bstID[ch]);
				if (f) break;
			}
		}
		ll otpt=0;
		up(i,1,n) {
			if (ans[i]==0) otpt+=a[i].lova;
			else if (ans[i]==1) otpt+=a[i].lovb;
			else otpt+=a[i].lovc;
		}
		cout<<otpt<<'\n';
	}
	return 0;
}

