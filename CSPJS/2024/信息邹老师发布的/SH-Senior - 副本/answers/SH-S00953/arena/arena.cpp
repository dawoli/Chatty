#include<bits/stdc++.h>
using namespace std;

int n,m,a[100000],c[100000],t,mode[5], comp[100000];
string d[100];
int noth[100]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072}, ppp;

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	ppp=lower_bound(noth,noth+17, n)-noth;
	for(int i=1;i<=ppp;i++) cin>>d[i];
	cin>>t;
	for(int i=1;i<=t;i++) {
		for(int i=1;i<=4;i++) cin>>mode[i];
		for(int i=1;i<=n;i++) a[i]=(a[i]^mode[i%4]);
		int mann=0;
		for(int i=1;i<=n;i++) mann=max(mann, a[i]);
		cout<<mann<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
