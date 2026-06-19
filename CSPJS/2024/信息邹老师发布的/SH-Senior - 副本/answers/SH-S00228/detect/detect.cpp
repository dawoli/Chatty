#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
int p[maxn];
int T, n, m, L, V;
vector<int> chafenp[maxn], chafenn[maxn];//对于[i, j]只留一个就行 , i =区间编号, j--
int ans1, ans2;

struct car{
	int d, v0, a;
	long long v0sq;
	int smax;
}A[maxn];

bool cmp(car a, car b){
	return a.d < b.d;
}


int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out","w",stdout);
	
	scanf("%d", &T);
	while(T--){
		ans1=0; ans2=0;
		memset(p, 0, sizeof(p));
		scanf("%d%d%d%d", &n, &m, &L, &V);
		long long Vsq=V*V;
		for(int i=0;i<n;i++){
			chafenp[i].clear();chafenn[i].clear();
		} 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &A[i].d, &A[i].v0, &A[i].a);
			A[i].v0sq=(long long)A[i].v0*A[i].v0;
			if(A[i].a<0) A[i].smax=A[i].v0sq/(2*A[i].a);
		}
		sort(A+1, A+n+1, cmp);
		for(int i=1;i<=m;i++){
			scanf("%d", &p[i]);
		} 
		p[m+1]=2*maxn;
		
		int cur=1;
		for(int i=1;i<=n;i++){
			if(A[i].a<=0 && A[i].v0<=V) continue;
			if(A[i].a>=0){
				int dmax=p[m]-A[i].d;
				if(dmax < 0) break;
				long long vmaxfang=2ll*A[i].a*dmax + A[i].v0*A[i].v0;
				if(vmaxfang > Vsq){
					ans1++;
				}
				while(p[cur] < A[i].d) cur++;
				for(int j=cur;j<=m;j++){
					if(2*A[i].a*(p[j]-A[i].d)+A[i].v0sq > Vsq){
						chafenp[j].push_back(i);
						chafenn[m].push_back(-i);
						break;
					}
				}
			}
			if(A[i].a < 0)	{
				double schao=(A[i].v0sq - V*V)/(abs(2*A[i].a));
				while(p[cur] < A[i].d) cur++;
				if(schao+A[i].d <= p[cur]) continue;
				ans1++;
				chafenp[cur].push_back(i);
				for(int j=cur;j<=m+1;j++){
					if(schao+A[i].d <= p[j]){
						chafenn[j-1].push_back(-i);
						break;
					}
				}
			}
		}
		set<int> s;
		for(int i=1;i<=m;i++){
			bool flag=true;
			for(int j=0;j<chafenp[i].size();j++){
				s.insert(chafenp[i][j]);
			}
			for(int j=0;j<chafenn[i].size();j++){
				if(s.count(-chafenn[i][j])){
					ans2++;
					s.clear();
					break;
				}
			}
		} 
		
		printf("%d %d\n", ans1, m-ans2);
	}
	
	return 0;
} 
