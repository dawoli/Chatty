#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 100005
using namespace std;
int T;

int n,m,L,V,V2;

struct Node{
	int l{},r{};
};
vector<Node> s;
vector<Node> q;
int P[N];

Node calc(int d,int v,int a){
	Node ans={d,-1};
	if (a==0){
		if (v>V){
			ans.r=L;
		}
		return ans;
	}

	int dv= V2- v*v;
	//a process

	int fh = dv%(a*2)!=0?1:0;
	int vs = dv/(2*a);
	// printf("%d\n",vs);
	// ans.l = max(d,d+vs+fh);
	// if (a>0){
	// 	ans.r= L;
	// }else {
	// 	ans.r=d+vs;
	// }
	if (a>0){//jia su{
		if (vs+fh>0){
			ans.l=d+vs+fh;
			ans.r=L;
		}else {
			ans.l=d;
			ans.r=L;
		}
	}else{
		if (vs+fh-1>=0){
			ans.l=d;
			ans.r=d+vs+fh-1;
		}else {
			ans.l=d;
			ans.r=-5;
		}
	}
	return ans;
}



void solve(){
	s.clear();
	q.clear();
	scanf("%d%d%d%d",&n,&m,&L,&V);
	V2=V*V;
	for (int i = 1; i <= n; ++i)
	{
		int d,v,a;
		scanf("%d%d%d",&d,&v,&a);
		Node tmp=calc(d,v,a);
		if (tmp.l<=tmp.r){
			s.push_back(tmp);
			// add(tmp.l,1);
			// add(tmp.r+1,-1);
		}
	}
	sort(s.begin(),s.end(),[](const Node &a,const Node &b){
		if (a.l==b.l)return a.r<b.r;
		return a.l<b.l;
	});

	auto it = s.begin();
	int mr=0;
	int ans1=0,ans2=0;

	for (int i = 1; i <= m; ++i){
		int p;
		scanf("%d",&p);
		P[i]=p;

		while (it != s.end() and it->l<=p){
			if (p<=it->r){
				ans1++;
				q.push_back(*it);
			}
			// printf("%d %d\n",it->l,it->r);
			it++;
		}
	}
	sort(q.begin(),q.end(),[](const Node &a,const Node &b){
		if (a.r==b.r)return a.l<b.l;
		return a.r<b.r;
	});
	it = q.begin();

	for (int i = 1; i <= m; ++i){
		if (it != q.end() and it->r<P[i]){
			ans2++;
			while(it != q.end() and it->r<P[i])
				it++;
		}
	}
	if (it!=q.end()){
		ans2++;
	}

	printf("%d %d\n",ans1,m-ans2);

}


signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);

	int t;
	scanf("%d",&t);
	for (T = 1; T <= t; ++T){
		solve();
	}
}