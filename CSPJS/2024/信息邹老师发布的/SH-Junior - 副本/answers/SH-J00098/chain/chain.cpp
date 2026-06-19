#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,q,k,l[100005],x,r,c,last1;
vector<int>s[100005];
bool flag,ans;
void dfs(int step,int last,int prev){
	if(step>r){
		if(flag&&prev==c){
			ans=true;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=last){
			for(int j=1;j<=l[i]-k+1;j++){
				for(int m=j+1;m<=min(j+k-1,l[i]);m++){
					if(s[i][j]==prev){
						flag=true;
						dfs(step+1,i,s[i][m]);
					}
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			s[i].push_back(0);
			for(int j=1;j<=l[i];j++){
				scanf("%d",&x);
				s[i].push_back(x);
				if(x==1){
					last1=i;
				}
			}
	    }
		while(q--){
			scanf("%d%d",&r,&c);
			flag=false;
			ans=false;
			dfs(1,last1,1);
			if(ans){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

