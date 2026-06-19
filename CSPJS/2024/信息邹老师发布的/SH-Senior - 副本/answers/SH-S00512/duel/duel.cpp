//Code locked at 15:01

#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

inline int read() {
	char c=getchar(); int v=0,f=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (;isdigit(c);c=getchar()) v=v*10+c-48;
	return v*f;
}

#define r(a) a=read()
int n,tot,x,nowfire,nxtfire,konum;
int cnt[100005];
bool vis[100005];
vector<int> fire;

signed main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	r(n); tot=n;
	for (int i=1;i<=n;i++) {
		r(x);
		if (!vis[x]) fire.push_back(x);
		vis[x]=1;
		cnt[x]++;
	}
	sort(fire.begin(),fire.end(),[](int a,int b){
		if (cnt[a]==cnt[b]) return a<b;
		return cnt[a]>cnt[b];
	});
	for (int i=0;i<fire.size();i++) {
		if (i==fire.size()-1) break;
		nowfire=fire[i];
		nxtfire=fire[i+1];
		konum=min(cnt[nowfire],cnt[nxtfire]);
		tot-=konum;
		cnt[nowfire]-=konum;
	}
	printf("%d\n",tot);
	return 0;
}

