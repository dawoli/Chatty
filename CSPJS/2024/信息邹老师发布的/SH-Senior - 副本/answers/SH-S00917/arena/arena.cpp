#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
long long T,n,m,aa[100005],c[100005],k,biog[45][45],xx[4],a[100005];
bool flag[100005];
long long answ[100005];
long long merg(long long l,long long r,long long rnd,long long nm){
	long long rv1=l,rv2=r,lz=0;
	if(r-l>1){
		rv1=merg(l,(l+r)/2,rnd+1,2*nm-1);
		rv2=merg((l+r+1)/2,r,rnd+1,2*nm);
	}
	if(biog[rnd][nm]==1){
		lz=rv2;
	}else{
		lz=rv1;
	}
	if(a[lz]>=rnd) return lz;
	return rv1+rv2-lz;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(long long i=1;i<=m;i++){
		cin>>c[i];
	}
	for(long long i=0;i<=32;i++){
		if(pow(2,i)>=n){
			k=i;
			break;
		}
	}
	string str;
	for(long long i=1;i<=k;i++){
		cin>>str;
		for(long long j=1;j<=pow(2,k-i);j++){
			biog[i][j]=str[j-1]-'0';
		}
	}
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		memset(answ,0,sizeof(answ));
		long long kk=0;
		cin>>xx[0]>>xx[1]>>xx[2]>>xx[3];
		for(long long i=1;i<=n;i++){
			a[i]=aa[i]^xx[i%4];
		}
		for(long long i=1;i<=m;i++){
			for(long long i=0;i<=32;i++){
				if(pow(2,i)>=c[i]){
					kk=i;
					break;
				}
			}
			answ[i]=i*merg(1,pow(2,kk),1,1);
		}
		long long fnans=answ[1];
		for(long long i=2;i<=m;i++){
			fnans=fnans^answ[i];
		}
		cout<<fnans<<'\n';
	}
	return 0;
}

