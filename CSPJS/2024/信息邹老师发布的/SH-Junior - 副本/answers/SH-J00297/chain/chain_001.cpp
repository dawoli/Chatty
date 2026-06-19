#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
const int R=1e2+9;
const int L=2e4+9;
const int Q=2e3+9;
int n,k,nq,l[N],r[N],c[N],ans[Q],mxnum=0,mxr=0;
vector<int> x[N];
bool f[2][L][N];//f[round][lastendnum][lastperson]
struct query{
	int id,val;
};
struct info{
	int person,pos;
};
vector<query> q[Q];
vector<info> d[L];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		for(int i=1;i<=mxnum;i++) d[i].clear();
		for(int i=1;i<=n;i++) x[i].clear();
		for(int i=1;i<=mxr;i++) q[i].clear();
		scanf("%d%d%d",&n,&k,&nq);
		mxnum=0;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int temp; scanf("%d",&temp); mxnum=max(mxnum,temp);
				d[temp].push_back((info){i,j-1});
				x[i].push_back(temp);
			}
		}
		mxr=0;
		for(int i=1;i<=nq;i++){
			int r,c; scanf("%d%d",&r,&c); mxr=max(mxr,r);
			q[r].push_back((query){i,c});
		}
		f[0][1][0]=1;
		for(int round=0;round<=mxr-1;round++){
			int now,nxt;
			if(round%2==1) now=1,nxt=0;
			else now=0,nxt=1;
			for(int i=0;i<q[round].size();i++){
				for(int lastperson=1;lastperson<=n;lastperson++){
					ans[q[round][i].id]|=f[now][q[round][i].val][lastperson];
				}
			}
			for(int lastendnum=1;lastendnum<=mxnum;lastendnum++){
				for(int lastperson=0;lastperson<=n;lastperson++){
					if(f[now][lastendnum][lastperson]==0) continue;
					for(int i=0;i<d[lastendnum].size();i++){
						int person=d[lastendnum][i].person;
						int pos=d[lastendnum][i].pos;
						if(person==lastperson) continue;
						for(int j=1;j<=k-1&&pos+j<l[person];j++){
							f[nxt][x[person][pos+j]][person]=1;
						}
					}
				}
			}
		}
		for(int i=1;i<=nq;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
