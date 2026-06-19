#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e5+1;
int n,r,cnt[maxn],maxr;
struct monster {
	int val,cnt;
};
vector<monster> vct;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>r;
		cnt[r]++;
		maxr=max(r,maxr);
	}
	for(int i=1;i<=maxr;i++) {
		if(cnt[i]) {
			vct.push_back((monster){i,cnt[i]});
		}
	}
	for(int i=1;i<vct.size();i++) {
		if(vct[i].cnt<vct[i-1].cnt) {
			vct[i].cnt=vct[i-1].cnt;
		}
	}
	cout<<vct[vct.size()-1].cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
