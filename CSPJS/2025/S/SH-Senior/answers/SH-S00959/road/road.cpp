#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct _L {
	int u,v,w;
};
int S[int(5e6+7)];
int A[11][int(1e5+7)];
int C[11];
int find(int i) {
	return (S[i]!=i?S[i]=find(S[i]):i);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	vector<_L> Lines;
	Lines.reserve(n*n+m);
	for(int i=0; i<m; i++) {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		Lines.push_back(_L {u,v,w});
	}
	sort(Lines.begin(),Lines.end(),[](const _L& a, const _L& b) {
		return a.w<b.w;
	});
	for(int j=0; j<k; j++) {
		scanf("%d",&C[j]);
		for(int i=1; i<=n; i++) {
			scanf("%d",&A[j][i]);
		}
	}
	//O(n logn 2^k) = O(10^4*13*10^3)=O(3*10^7) OK
	int Limit = 1<<k;
	long long result=0xffffffffffULL;
	for(int selected=0; selected<Limit; selected++) {
		vector<_L> Line2;
		long long ans=0;
		long long idx=0;
		for(int j=0; j<k; j++) {
			if(selected&(1<<j)) {
				ans+=C[j];
				for(int i=1; i<=n; i++) {
					Line2.push_back(_L {n+1+idx,i,A[j][i]});
				}
				idx++;
			}
		}
		if(ans>result) continue;
		sort(Line2.begin(),Line2.end(),[](const _L& a, const _L& b) {
			return a.w<b.w;
		});
		long long cnt = n+idx;
		for(int i=1; i<=cnt; i++) S[i]=i; //re-initialize
		auto it1 = Lines.begin();
		auto it2 = Line2.begin();//double pointers
		for(int rr=0;rr<cnt-1;) {
			int a1 = it1!=Lines.end()?it1->w:int(1e9+7);
			int a2 = it2!=Line2.end()?it2->w:int(1e9+7);
			_L l;
			if(a1<a2) {
				l=*it1;
				it1++;
			} else {
				l=*it2;
				it2++;
			}
			int s = find(l.u);
			int e = find(l.v);
			if(s!=e) {
				S[s]=e;
				ans+=l.w;
				if(ans>result) break;
				rr++;
			}
		}
		result=min(result,ans);
	}
	printf("%lld\n",result);
	return 0;
}
