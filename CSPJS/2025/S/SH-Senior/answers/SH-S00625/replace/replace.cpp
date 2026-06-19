#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M1=1101161037;
int n,q;
string S1[210000],S2[210000];
string T1,T2;
bool u[210000];
const pii P=make_pair(131,131);
pii I(int x) {
	return make_pair(x%M1,x);
}
pii A(pii x,pii y) {
	return make_pair((x.first+y.first)%M1,x.second+y.second);
}
pii M(pii x,pii y) {
	return make_pair((x.first*y.first)%M1,x.second*y.second);
}
struct rpl{
	pii fr,to;
	pii st,ed;
	int stl,edl;
};
rpl R[210000]; 
pii tst[5100000],ted[5100000];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) {
		cin >> S1[i] >> S2[i];
		int Sn=S1[i].size();
		int Sl=Sn-1,Sr=0;
		for(int j=0;j<Sn;j++) {
			if(S1[i][j]!=S2[i][j]) {
				Sl=min(Sl,j);
				Sr=max(Sr,j);
			}
		}
		if(Sl>Sr) u[i]=0;
		else u[i]=1;
		if(u[i]==1) {	
			pii res=make_pair(0,0);
			for(int j=Sl-1;j>=0;j--) {
				res=A(M(res,P),I((int)S1[i][j]));
			}
			R[i].st=res;
			res=make_pair(0,0);
			for(int j=Sr+1;j<Sn;j++) {
				res=A(M(res,P),I((int)S1[i][j]));
			}
			R[i].ed=res;
			res=make_pair(0,0);
			for(int j=Sl;j<=Sr;j++) {
				res=A(M(res,P),I((int)S1[i][j]));
			}
			R[i].fr=res;
			res=make_pair(0,0);
			for(int j=Sl;j<=Sr;j++) {
				res=A(M(res,P),I((int)S2[i][j]));
			}
			R[i].to=res;
			R[i].stl=Sl;
			R[i].edl=Sn-1-Sr;
		}
	}
	while(q--) {
		cin >> T1 >> T2;
		if(T1.size()!=T2.size()) {
			cout << 0 << '\n';
		} 
		else {
			int Sn=T1.size();
			int Sl=n-1,Sr=0;
			for(int j=0;j<Sn;j++) {
				if(T1[j]!=T2[j]) {
					Sl=min(Sl,j);
					Sr=max(Sr,j);
				}
			}
			if(Sl>Sr) cout << 0 << '\n';
			else {	
				rpl Rt;
				tst[0]=make_pair(0,0);
				for(int j=Sl-1;j>=0;j--) {
					tst[Sl-j]=A(M(tst[Sl-j-1],P),I((int)T1[j]));
				}
				ted[0]=make_pair(0,0);
				for(int j=Sr+1;j<Sn;j++) {
					ted[j-Sr]=A(M(ted[j-Sr-1],P),I((int)T1[j]));
				}
				pii res=make_pair(0,0);
				for(int j=Sl;j<=Sr;j++) {
					res=A(M(res,P),I((int)T1[j]));
				}
				Rt.fr=res;
				res=make_pair(0,0);
				for(int j=Sl;j<=Sr;j++) {
					res=A(M(res,P),I((int)T2[j]));
				}
				Rt.to=res;
				Rt.stl=Sl;
				Rt.edl=Sn-1-Sr;
				int ans=0;
				for(int i=1;i<=n;i++) {
					if(R[i].fr==Rt.fr&&R[i].to==Rt.to&&R[i].stl<=Rt.stl&&R[i].edl<=Rt.edl) {
						if(R[i].st==tst[R[i].stl]&&R[i].ed==ted[R[i].edl]) {
							ans++;
						}
					}
				}
				cout << ans << '\n';
			}
		}
	}
	return 0;
}
