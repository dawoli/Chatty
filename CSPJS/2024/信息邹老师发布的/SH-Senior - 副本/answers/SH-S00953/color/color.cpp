#include<bits/stdc++.h>
using namespace std;

struct Node {
	long long val;
	int father;
};
int t, n, rd[200010], bl[200010], rds, bls;
bool col[200010];//0->red, 1->blue
Node a[200010];
long long tmp=-1, sc=-1;

long long score(int s, int n) {
	memset(rd, 0, sizeof(rd));
	memset(bl, 0, sizeof(bl));
	rds=0;bls=0;
	tmp=0;
	for(int i=s;i<=n;i++) {
		if(col[i]==0) {
			rds++;
			rd[rds]=a[i].val;
		}
		else {
			bls++;
			bl[bls]=a[i].val;
		}
	}
	for(int i=2;i<=rds;i++) {
		if(rd[i]==rd[i-1]) tmp+=rd[i];
	}
	for(int i=2;i<=bls;i++) {
		if(bl[i]==bl[i-1]) tmp+=bl[i];
	}
	return tmp;
}

void f(int pl) {
	if(pl==0) {
		sc=max(sc, score(1, n));
		return;
	}
	f(pl-1);
	col[pl]=1;
	f(pl-1);
	col[pl]=0;
	return;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	memset(col,0,sizeof(col));
	cin>>t;
	for(int xunhuan=1;xunhuan<=t;xunhuan++) {
		sc=-1;
		cin>>n;
		for(int i=1;i<=n;i++) {
			scanf("%lld", &a[i].val);
			a[i].father=i;
		}
//		
//		for(int i=2;i<=n;i++) {
//			for(int j=i-1;j>=1;j--) {
//				if(a[i].val==a[j].val) a[i].father=a[j].father;
//			}
//		}
//		
//		
		f(n);
		cout<<sc<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
