#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

const int N=1e5+5;
int n, m, t, ln, vm, p[N], ans1, ans2;

int schl(double pt, int lr){
	int l=-1, r=m+1;
	while(l+1<r){
		int md=(l+r)/2;
		if(p[md]>pt) r=md;
		else l=md;
	}
	if(lr==0) return l;
	if(p[l]==pt) return l;
	return r;
}

struct car{
	int d, v, a, lc, rc;
	double ot;
	void in(){
		cin >> d >> v >> a;
	}
	bool operator <(const car &s){
		return rc<s.rc;
	}
	void calc(){
		rc=m+1; lc=m+2;
		if(a<0 && v>vm){
			lc=schl(d, 1);
			double tm=1.0*(v-vm)/(-1.0*a);
			rc=schl(1.0*d+tm*(v+v+tm*a)/2, 0);
			cout << lc << endl;
		}
		if(a>0){
			double tm;
			if(v>vm){
				rc=m, lc=schl(d, 1);
			}
			if(v==vm){
				rc=m, lc=schl(d+1, 1);
			}
			if(v<vm){
				double tm=1.0*(vm-v)/a;
				rc=m, lc=schl(1.0*d+tm*(v+v+tm*a)/2, 1);
			}
		}
		if(a==0){
			if(vm<v){
				rc=m, lc=schl(d, 1);
			}
		}
	}
}c[N], oc[N];

int main(){
	freopen("detect.in", "i", stdin);
	freopen("detect.out", "o", stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> ln >> vm;
		ans1=0, ans2=m;
		for(int i=0; i<n; i++){
			c[i].in();
		}
		for(int i=0; i<m; i++){
			cin >> p[i];
		}
		for(int i=0; i<n; i++){
			c[i].calc();
			if(c[i].lc<=c[i].rc){
				oc[ans1++]=c[i];
				cout << i << " ";
			}
		}
		cout << ans1 << " ";
		sort(oc, oc+ans1);
		int cur=-1;
		for(int i=0; i<ans1; i++){
			if(oc[i].lc>cur) ans2--, cur=oc[i].rc;
		}
		cout << ans2 << endl;
	}
	return 0;
} 
