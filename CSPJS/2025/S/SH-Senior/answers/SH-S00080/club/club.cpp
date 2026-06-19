#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int n;
struct Member {
	int ga,gb,gc,fst,snd,trd,fid,sid,tid;
} a[N];
struct Membera {
	int id,ga,gb,gc;
	bool operator<(const Membera &mem) const {
		return ga-max(gb,gc)>mem.ga-max(mem.gb,mem.gc);
	}
};
struct Memberb {
	int id,ga,gb,gc;
	bool operator<(const Memberb &mem) const {
		return gb-max(ga,gc)>mem.gb-max(mem.ga,mem.gc);
	}
};
struct Memberc {
	int id,ga,gb,gc;
	bool operator<(const Memberc &mem) const {
		return gc-max(gb,ga)>mem.gc-max(mem.gb,mem.ga);
	}
};
priority_queue<Membera> qa;
priority_queue<Memberb> qb;
priority_queue<Memberc> qc;
void solve() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].ga>>a[i].gb>>a[i].gc;
		if(a[i].ga>a[i].gb) {
			if(a[i].gb>a[i].gc) {
				a[i].fst=a[i].ga; a[i].fid=0;
				a[i].snd=a[i].gb; a[i].sid=1;
				a[i].trd=a[i].gc; a[i].tid=2;
			} else if(a[i].ga<a[i].gc) {
				a[i].fst=a[i].gc; a[i].fid=2;
				a[i].snd=a[i].ga; a[i].sid=0;
				a[i].trd=a[i].gb; a[i].tid=1;
			} else {
				a[i].fst=a[i].ga; a[i].fid=0;
				a[i].snd=a[i].gc; a[i].sid=2;
				a[i].trd=a[i].gb; a[i].tid=1;
			}
		} else {
			if(a[i].ga>a[i].gc) {
				a[i].fst=a[i].gb; a[i].fid=1;
				a[i].snd=a[i].ga; a[i].sid=0;
				a[i].trd=a[i].gc; a[i].tid=2;
			} else if(a[i].gb<a[i].gc) {
				a[i].fst=a[i].gc; a[i].fid=2;
				a[i].snd=a[i].gb; a[i].sid=1;
				a[i].trd=a[i].ga; a[i].tid=0;
			} else {
				a[i].fst=a[i].gb; a[i].fid=1;
				a[i].snd=a[i].gc; a[i].sid=2;
				a[i].trd=a[i].ga; a[i].tid=0;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		if(a[i].fid==0) {
			Membera x={i,a[i].ga,a[i].gb,a[i].gc};
			qa.push(x);
			if(qa.size()>n/2) {
				Membera y=qa.top(); qa.pop();
				int id=y.id;
				if(a[id].sid==1) {
					Memberb x={id,a[id].ga,a[id].gb,a[id].gc};
					qb.push(x);
				} else if(a[id].sid==2) {
					Memberc x={id,a[id].ga,a[id].gb,a[id].gc};
					qc.push(x);
				}
			}
		} else if(a[i].fid==1) {
			Memberb x={i,a[i].ga,a[i].gb,a[i].gc};
			qb.push(x);
			if(qb.size()>n/2) {
				Memberb y=qb.top(); qb.pop();
				int id=y.id;
				if(a[id].sid==0) {
					Membera x={id,a[id].ga,a[id].gb,a[id].gc};
					qa.push(x);
				} else if(a[id].sid==2) {
					Memberc x={id,a[id].ga,a[id].gb,a[id].gc};
					qc.push(x);
				}
			}
		} else if(a[i].fid==2) {
			Memberc x={i,a[i].ga,a[i].gb,a[i].gc};
			qc.push(x);
			if(qc.size()>n/2) {
				Memberc y=qc.top(); qc.pop();
				int id=y.id;
				if(a[id].sid==1) {
					Memberb x={id,a[id].ga,a[id].gb,a[id].gc};
					qb.push(x);
				} else if(a[id].sid==0) {
					Membera x={id,a[id].ga,a[id].gb,a[id].gc};
					qa.push(x);
				}
			}
		}
	}
	long long ans=0;
	while(!qa.empty()) {
		ans+=qa.top().ga;
		qa.pop();
	}
	while(!qb.empty()) {
		ans+=qb.top().gb;
		qb.pop();
	}
	while(!qc.empty()) {
		ans+=qc.top().gc;
		qc.pop();
	}
	cout<<ans<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t; while(t--) solve();
	return 0;
}
