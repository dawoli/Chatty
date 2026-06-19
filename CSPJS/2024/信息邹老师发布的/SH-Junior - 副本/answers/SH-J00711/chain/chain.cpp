#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

vector<int>s[100005];

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x;
}

bool vis[105][200005];
int cnt[200005],las[200005],nlas[200005];

int q[200005],head=0;
#define push(x) (q[head++]=(x))
struct idx{int i,j;};
vector<idx>si[200005];

int r[200005],c[200005];

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int T=read();
//	T=2;
	while(T--){
		int n,k,Q;
		n=read(),k=read(),Q=read();
		for(int i=1;i<=n;i++){
			int l=read();
			s[i].resize(l);
			for(int j=0;j<l;j++){
				s[i][j]=read();
				si[s[i][j]].push_back({i,j});
			}
		}
//		for(int i=1;i<=1;i++){
//			printf("## %d\n",i);
//			for(idx id:si[i]){
//				printf("%d %d\n",id.i,id.j);
//			}
//		}
		int maxr=0;
		for(int i=1;i<=Q;i++){
			r[i]=read();
			c[i]=read();
			maxr=max(maxr,r[i]);
		}
		head=0;push(1);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=maxr;i++){
//			printf("%d\n",las[1]);
			for(int j=0;j<head;j++){
//				printf(" %d\n",q[j]);
				int x=q[j]%2000000;
				int la=-1;
				if(q[j]>=2000000)la=las[x];
				for(idx id:si[x]) // Ave. O(1)
					if(id.i!=la)
						for(int l=id.j+1,en=min(int(s[id.i].size()),id.j+k);l<en;l++)
							if(nlas[s[id.i][l]]!=id.i)cnt[s[id.i][l]]++,nlas[s[id.i][l]]=id.i;
			}
			head=0;
			for(int j=1;j<=200000;j++){
				if(cnt[j]==1)push(j+2000000),vis[i][j]=1;
				else if(cnt[j]>1)push(j),vis[i][j]=1;
			}
			memset(cnt,0,sizeof(cnt));
			memcpy(las,nlas,sizeof(las));
			memset(nlas,0,sizeof(nlas));
		}
		for(int i=1;i<=Q;i++){
			printf("%d\n",vis[r[i]][c[i]]);
		}
		for(int i=1;i<=200000;i++)si[i].clear();
		memset(las,0,sizeof(las));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
