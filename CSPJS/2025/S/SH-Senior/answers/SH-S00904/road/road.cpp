#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define FOR(n) for(int i=1;i<=n;i++)
#define FORj(n) for(int j=1;j<=n;j++)
#define For(n) for(int i=0;i<n;i++)
#define Forj(n) for(int j=0;j<n;j++)
#define ci(x) cin>>x;
#define ci2(x,y) cin>>x>>y;
#define ci3(x,y,z) cin>>x>>y>>z;
#define cr(x) cout<<x<<endl;
#define cr2(x,y) cout<<x<<' '<<y<<endl;
#define cr3(x,y,z) cout<<x<<' '<<y<<' '<<z<<endl;
#define INF (100000000000000009ll)
const int N=1e6+1e5+109;
int n,m,k;
int fa[N],siz[N];
struct ed {
	int u,v,w;
	bool operator > (ed edd1) const {
		return w>edd1.w;
	}
};
ed e[N];
bool cmp(ed a,ed b) {
	return a.w>b.w;
}
int find(int a) {
	if(fa[a]==a) {
		return a;
	} else {
		return fa[a]=find(fa[a]);
	}
}
void merge(int a,int b) {
	int ga=find(a),gb=find(b);
	if(siz[ga]<=siz[gb]) {
		fa[ga]=gb;
		siz[gb]+=siz[ga];
	} else {
		fa[gb]=ga;
		siz[ga]+=siz[gb];
	}
}
void csh(int sz) {
	For(sz+m+1) {
		fa[i]=i;
		siz[i]=i;
	}
}
priority_queue<ed,vector<ed>,greater<ed> > pq;
priority_queue<ed,vector<ed>,greater<ed> > pq1;
int pusnum;
int kruskal() {
	csh(N);
	int bs=1;
	int ans1=0;
	int u,v,w;

	while(!pq1.empty()) {
		ed tt=pq1.top();
		pq1.pop();
		u=tt.u;
		v=tt.v;
		w=tt.w;
//		cr3(u,v,w)
		if(find(u)!=find(v)) {
//			cr3("add",u,v)
			ans1+=w;
			bs++;
			if(bs>=pusnum)return ans1;
			merge(u,v);
		}
	}
	return INF;
}
int mm[11][N];
int c[11];
int ans=INF,anss;
struct tx {
	int c;
	int mp[1005];
};
bool cmpp(tx a,tx b) {
	return a.c>=b.c;
}
tx aki[11];
mt19937 rnd(time(0));
void h0peakioi() {
	ci3(n,m,k)
	if(k>5&&m>=2e5) {
		bool flg=1;
		ed hope;
		FOR(m) {
			ci3(hope.u,hope.v,hope.w)
			pq.push(hope);
		}
		FORj(k) {
			ci(c[j])
			if(c[j]!=0)flg=0;
			FOR(n) {
				ci(mm[j][i])
			}
		}


		if(flg) {

			pq1=pq;
			pusnum=n;
			anss=0;
			FORj(k) {
				anss+=c[j];
				pusnum++;
				ed aki;
				for(int l=1; l<=n; l++) {
					aki.u=(n+j);
					aki.v=l;
					aki.w=mm[j][l];
					pq1.push(aki);
				}

				int dict=kruskal();
//			cr2("krus",dict+anss)
				ans=min(ans,dict+anss);
			}

			cr(ans)
			return;

		}


		for(int kl=1; kl<=7; kl++) {
			int i=rnd()%(1<<k);
			pq1=pq;
			pusnum=n;
			anss=0;
			FORj(k) {
				if(i>>(j-1)&1) {
					anss+=c[j];
					pusnum++;
					ed aki;
					for(int l=1; l<=n; l++) {
						aki.u=(n+j);
						aki.v=l;
						aki.w=mm[j][l];
						pq1.push(aki);
					}
				}
				int dict=kruskal();
//			cr2("krus",dict+anss)
				ans=min(ans,dict+anss);
			}
		}
		cr(ans)
		return;
	}
	ed hope;
	FOR(m) {
		ci3(hope.u,hope.v,hope.w)
		pq.push(hope);
	}
	FORj(k) {
		ci(c[j])
		FOR(n) {
			ci(mm[j][i])
		}
	}
	For(1<<k) {
		pq1=pq;
		pusnum=n;
		anss=0;
		FORj(k) {
			if(i>>(j-1)&1) {
				anss+=c[j];
				pusnum++;
				ed aki;
				for(int l=1; l<=n; l++) {
					aki.u=(n+j);
					aki.v=l;
					aki.w=mm[j][l];
					pq1.push(aki);
				}
			}
			int dict=kruskal();
//			cr2("krus",dict+anss)
			ans=min(ans,dict+anss);
		}
	}
	cr(ans)
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int TOT=1;
//	ci(TOT)
// 多册吗 清空了吗
// 文件开了吗
	while(TOT--)h0peakioi();
}

