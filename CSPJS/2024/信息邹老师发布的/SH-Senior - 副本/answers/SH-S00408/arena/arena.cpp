#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=998244353;
const int MN=100005;
const int INF=0x3f3f3f3f;



int n,m,a[MN],c[MN],gs,k,t,x[5];
int g[20][MN];
int fpow[MN];
int beat(int djl,int dsc,int xh,int dh) {
//    cout<<djl<<" "<<dsc<<" "<<xh<<" "<<dh<<endl;
	if(dsc==1) {
		int lz;
		if(g[dsc][xh/2+1]==1) {
//			cout<<"dh is lz"<<endl;
		    lz=dh;
			if(a[lz]>djl) return dh;
			else return xh;	
		} else {
//			cout<<"xh is lz"<<endl;
			lz=xh;
			if(a[lz]>djl) return xh;
			else return dh;
		}
	} else {
		int xxh=beat(djl+1,dsc/2,xh,(dh+xh)/2);
		int ddh=beat(djl+1,dsc/2,(dh+xh)/2+1,dh);
//		cout<<"beat!   "<<xxh<<" "<<ddh<<endl;
		int lz;
		if(g[dsc][xh/2+1]==1) {
			lz=ddh;
			if(a[lz]>djl) return ddh;
			else return xxh;
		} else {
			lz=xxh;
			if(a[lz]>djl) return xxh;
			else return ddh;
		}
	}
	return 0;
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
    
    int tmp=1,ooq=2;
    for(int i=1;i<MN;++i) {
        fpow[i]=tmp;
    	if(i==ooq) {
    		ooq*=2;
		    tmp++;
		}
	}
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) {
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i) {
		scanf("%d",&c[i]);
	}
	gs=1,k=0;
	while(1) {
	    gs*=2; k++;
		if(gs>=n) break;	
	}
	gs/=2;
	string s;
    for(int i=k;i>=1;--i) {
    	cin>>s;
    	s=' '+s;
    	for(int j=1;j<s.size();++j) {
    		g[i][j]=s[j]-'0';
		}
	}
//	for(int i=k;i>=1;--i) {
//		cout<<i<<": ";
//		for(int j=1;j<=pow(2,i-1);++j) {
//			cout<<g[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	scanf("%d",&t);
	for(int i=0;i<4;++i) {
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;++i) {
		a[i]=a[i] xor x[i%4];
	}
//	for(int i=1;i<=n;++i) {
//	    cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int ans=-1;
    for(int i=1;i<=m;++i) {
    	if(pow(2,fpow[c[i]])!=c[i]&&c[i]!=1) continue;
//    	cout<<c[i]<<" : ";
    	int ls=fpow[c[i]];
    	int winner=beat(1,ls,1,c[i]);
//    	cout<<"winner is "<<winner<<" !!!" <<endl;
    	if(ans==-1) ans=i*winner;
    	else ans=ans xor (i*winner);
//    	printf("%d %d\n",i*winner,ans);
//	    cout<<endl;
	}
	printf("%d\n",ans);
	return 0; 
} 
