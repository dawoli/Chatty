#include<bits/stdc++.h>
using std::fstream;
using std::endl;
using std::max;
using std::min;
using std::cerr;

typedef long long ll;

// #define int ll

fstream fin("duel.in",std::ios::in);
#define cin fin
fstream fout("duel.out",std::ios::out);
//#define fout std::cout

const int R=1e5+100,N=1e5+100;

int n,cnt[R];
int maxx;

signed main() {
	fin>>n;
	assert(n);
	while(n--) {
		int x;
		fin>>x;
		//cerr<<x<<endl;
		cnt[x]++;
		maxx=max(maxx,x);
	}
	
	for(int i=1;i<maxx;i++) {
		int atk=min(cnt[i],cnt[i+1]);
		//if(atk) printf("let %d of level %d attack\n",atk,i+1);
		cnt[i]-=atk;
		cnt[i+1]+=cnt[i];
	}
	
	fout<<cnt[maxx]<<endl;
	
	return 0;
}
