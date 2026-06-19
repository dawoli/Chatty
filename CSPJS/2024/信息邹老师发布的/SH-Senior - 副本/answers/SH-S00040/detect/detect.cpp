#include<bits/stdc++.h>
using std::fstream;
using std::endl;
using std::cerr;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::floor;

typedef long long ll;

// #define int ll

fstream fin("detect.in",std::ios::in);
#define cin fin
fstream fout("detect.out",std::ios::out);
//#define fout std::cout

const int N=1e5+100,M=N;

typedef std::pair<int,int> Interval;

int n,m,l,vv;
int p[M];
struct Car {
	int d,v,a;
	
	void sped(Interval& x)const {
		int pl,pr;
		if(a>0) {
			pr=1e9;
			if(v>vv) pl=-1;
			else {
				pl=(vv*vv-v*v)/(2*a);
			}
			pl+=d;
		}else if(a==0) {
			if(v>vv) {
				pl=d-1;
				pr=1e9;
			}else pl=pr=-1e9;
		}
		else {
			pl=d-1;
			if(v<vv) pr=-1e9;
			else {
				pr=((v*v-vv*vv-1+2*-a*d)/(2*-a));
			}
		}
		//printf("che zai weizhi %.9lf dao %.9lf chaosu\n",double(pl),double(pr));
		int lt=upper_bound(p,p+m,int(pl))-p;
		int r=upper_bound(p,p+m,int(pr))-p;
		x.second=lt;x.first=r;
	}
}c[N];
Interval iv[N];int cnt;

void test() {
	cnt=0;
	
	fin>>n>>m>>l>>vv;
	
	for(int i=0;i<n;i++) {
		fin>>c[i].d>>c[i].v>>c[i].a;
	}
	for(int j=0;j<m;j++) fin>>p[j];
	sort(p,p+m);
	for(int i=0;i<n;i++) {
		c[i].sped(iv[cnt]);
		if(iv[cnt].second<iv[cnt].first) {
			//printf("di %d che sped deng %d-deng %d. \n",i+1,p[iv[cnt].second],p[iv[cnt].first-1]);
			cnt++;
		}
	}
	fout<<cnt<<' ';
	sort(iv,iv+cnt);
	int last=-1;int ans=m;
	for(int i=0;i<cnt;i++) {
		if(iv[i].second>last) {
			//printf("dakai deng %d\n",p[i.r-1]);
			ans--;
			last=iv[i].first-1;
		}
	}
	fout<<ans<<'\n';
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/

signed main() {
	int t;
	fin>>t;
	assert(t);
	while(t--) 
		if(true)test();
		else {
			printf("consume\n");
			int x;
			cin>>n>>m>>x>>x;
			while(m--) cin>>x;
			while(n--) cin>>x>>x>>x;
		}
	
	return 0;
}
