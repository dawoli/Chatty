#include<cstdio>
#include<vector>
using namespace std;
const int N = 200200;
vector<int> s[N],start[N];
int t,n,k,q,len[N],x,r,c,ok;
void dfs(int index,int j,int roll);
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		for(int i=1;i<=200000;i++){
			s[i].clear();
			start[i].clear();
		}
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&len[i]);
			for(int j=0;j<len[i];j++){
				scanf("%d",&x);
				s[i].push_back(x);
				if(x==1){
					start[i].push_back(j);
				}
			}
		}
		while(q>0){
			q--;ok=0;
			scanf("%d%d",&r,&c);
			for(int i=1;i<=n;i++){
				if(ok==1){
					break;
				}
				for(int j=0;j<start[i].size();j++){
					if(ok==1){
						break;
					}
					dfs(i,start[i][j],1);
				}
			}
			printf("%d\n",ok);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
void dfs(int index,int j,int roll){
	if(roll>=r){
		int tt=0;
		for(int i=j+1;i<len[index] && i-j+1<=k;i++){
			if(s[index][i]==c){
				tt=1;
				break;
			}
		}
		if(tt==1)ok=1;
		return ;
	}
	if(ok==1){
		return ;
	}
	for(int i=j+1;i<len[index] && i-j+1<=k;i++){
		for(int jj=1;jj<=n;jj++){
			if(jj==index)continue;
			for(int kk=0;kk<len[jj];kk++){
				if(ok==1){
					return ;
				}
				if(s[jj][kk]==s[index][i]){
					dfs(jj,kk,roll+1);
				}
			}
		}
	}
}
