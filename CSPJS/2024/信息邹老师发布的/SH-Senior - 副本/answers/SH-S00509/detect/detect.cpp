#include <iostream>
#include <cstdio>
#include <algorithm>

#define left first
#define right second


using namespace std;

const int N=1e5+1;

int n, m, l, v;
int cd[N],cv[N],ca[N],d[N];
pair<int,int> be[N];

int find(int dn, int l, int r,bool mode) {
	if(d[r] == dn) return r;
	if(d[l] == dn) return l;
	if(r == l) {
		return mode?l-1:l;
	}
	if(r-l == 1) {
		if(mode) return l;
		else return r;
	}
	int mid = l + ((r-l)>>1) - 1;
	//if(d[mid] == dn) return mid;
	
	if(dn > d[mid]) return find(dn,mid+1,r,mode);
	else return find(dn,l,mid,mode);
}

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.left < b.left;
}

void work() {
	int ans1 = 0, cnt = 1;
	scanf("%d%d%d%d",&n, &m ,&l ,&v);
	v *=v ;
	for (int i = 1; i <= n; i++) {
		cin >> cd[i] >> cv[i] >> ca[i];
		cv[i] *= cv[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> d[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if(ca[i] >= 0){
			int vv = cv[i] + 2*ca[i]*(d[m]-cd[i]);
			ans1 += (vv>v);
			
			if(vv <= v) continue;
			if(ca[i] == 0){
				be[i].left = find(cd[i], 1, m, 0);
				be[i].right = m;
				continue;
			}
			double lim = (v - cv[i])/(2 * ca[i]);
			lim = lim>=0?lim:0;
			int limm = lim + 0.9999999;
			be[i].left = find(cd[i] + limm, 1, m, 0);
			be[i].right = m;
		}
		else{
			int dn = find(cd[i], 1, m, 0);
			int vv = cv[i] + 2*ca[i]*(d[dn]-cd[i]);
			ans1 += (vv>v);
			
			if(vv <= v) continue;
			int lim = (v - cv[i])/(2 * ca[i]);
			be[i].left = dn;
			be[i].right = find(cd[i] + lim, 1, m, 1);
		}
	}
	sort(be+1,be+1+n,cmp);
	
	int l = 1, r = m;
	for(int i = 1; i <= n; i++) {
		if(be[i].left == 0 && be[i].right == 0) continue;
		if(be[i].left > r) {
			cnt++;
			l = be[i].left, r = be[i].right;
		}
		else{
			l = max(be[i].left, l);
			r = min(be[i].right, r);
		}
	}
	
	cout<<ans1<<' '<<m-cnt<<endl;
}

signed main () {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;cin >> T;
	for(int TT = 1; TT <= T; TT++) {
		work();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ©\2
6 4 ©\4
2 5 8 9 15
*/
