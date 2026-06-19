#include<cstring>
#include<utility>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
const int N=2010,M=200010;
int _,n,k,q;
int len[N],s[N][N];
bool g[N][M];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&len[i]);
			for(int j=1;j<=len[i];j++){
				scanf("%d",&s[i][j]);
				g[i][s[i][j]]=true;
			}
		}
		while(q--){
			int r,c;
			scanf("%d%d",&r,&c);
			bool flag=false;
			static queue<PIII> q;
			q.emplace(PII(r,c),-1);
			while(q.size()){
				PIII t=q.front();
				q.pop();
				int r=t.first.first,c=t.first.second,last=t.second;
//				printf("(%d,%d,%d) ",r,c,last);
				if(!r){
					if(c==1){
						flag=true;
						break;
					}
					continue;
				}
				for(int i=1;i<=n;i++){
					if(!g[i][c])
						continue;
					if(i==last)
						continue;
					for(int j=1;j<=len[i];j++){
						if(s[i][j]!=c)
							continue;
						for(int delta=1;delta<k;delta++){
							int hd=j-delta;
							if(hd<=0)
								break;
							q.emplace(PII(r-1,s[i][hd]),i);
						}
					}
				}
			}
			while(q.size())
				q.pop();
			if(flag)
				puts("1");
			else puts("0");
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=len[i];j++)
				g[i][s[i][j]]=false;
	}
	return 0;
}
