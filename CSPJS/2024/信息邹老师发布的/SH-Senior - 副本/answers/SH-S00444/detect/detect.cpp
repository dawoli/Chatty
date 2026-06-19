#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll; 
#define fr(aaa,bbb,i) for(int i=aaa,i##end=bbb;i<=i##end;++i)
#define rf(bbb,aaa,i) for(int i=bbb,i##end=aaa;i>=i##end;--i)
#define maxn 100007
int t,n,m,L,V;
struct p{
	int di,vi,ai,ij;
}a[maxn];int zt[27],ce[maxn],b[27][27],bol[27];
bool cmp(p x,p y){return x.ai<y.ai;}
bool cmp2(p x,p y){return x.di<y.di;}
int ctt=0,df,ret;
void dfs(int dep,int val){
	if(val==df){//df已处理 
		ret=(ret<ctt)?ret:ctt;
		return;
	}
	if(dep==m+1){//所有测试点选完啦 
		return;
	}ctt++;
	dfs(dep+1,zt[dep]|val);//选 
	ctt--;
	dfs(dep+1,val);//不选 
	return;
}inline int solve(){
	ctt=0;//ctt已处理 
	fr(1,m,i){//zt现场处理 
		zt[i]=0;
		fr(1,n,j){
			zt[i]=zt[i]*2+(b[i][j]==1);
		}
	}
	dfs(1,0);
	return ret;//ret已处理 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		fr(1,n,i){
			cin>>a[i].di>>a[i].vi>>a[i].ai;a[i].ij=i;
		}sort(a+1,a+n+1,cmp);
		fr(1,m,i){
			cin>>ce[i];
		}
		if(n<=20&&m<=20){
			sort(a+1,a+n+1,cmp2);
			int nxt=1;
			int res=m,car=0;
			fr(1,m,i){
				while(nxt!=n+1&&a[nxt].di<=ce[i]){//在测速点前已经入场 
					nxt++;
				}int fl=0;
				fr(1,nxt-1,j){
					ll k=1ll*a[j].vi*a[j].vi+1ll*2*a[j].ai*(ce[i]-a[j].di);
					if(k>V*V){
						bol[j]=1;
						b[i][j]=1;
					}
				}res-=fl;
			}df=0;
			fr(1,n,i){
				df*=2;
				if(bol[i]==1){
					car++;
					df+=1;
				}
			}
			ret=m;
			printf("%d %d\n",car,m-solve());
			fr(1,n,i) bol[i]=0;
			fr(1,m,i){
				fr(1,n,j){
					b[i][j]=0;
				}
			}
		}
		else if(a[1].ai==0&&a[n].ai==0){
			cout<<0;
		}
	}
	return 0;
} /*

1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/
