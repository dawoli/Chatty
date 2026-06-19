#include<bits/stdc++.h>
using namespace std;
int w[1001][2001];
int n,k,q;
int r,c;
bool f;
void dfs(int step,int l,int p){
	if(f) return ;
	if(step>r){
		if(l==1) f=true;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i==p) continue;
		for(int j=1;j<=w[i][0];j++)
			if(w[i][j]==l)
				for(int ln=j-1;ln>=max(j-k+1,1);ln--)
					dfs(step+1,w[i][ln],i);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d %d %d\n",&n,&k,&q);
		for(int i=1;i<=n;i++){
			string s;getline(cin,s);s=s+" ";
			int l,r,cnt;l=r=cnt=0;
			for(r;r<=s.size()-1;r++){
				if(s[r]==' '){
					int x=0;
					for(int k=l;k<=r-1;k++)
						x=x*10+(s[k]-'0');
					w[i][++cnt]=x;
					l=++r;
				}
			}
			w[i][0]=cnt;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=w[i][0];j++)
				printf("%d ",w[i][j]);
			printf("\n");
		}
		while(q--){
			scanf("%d %d",&r,&c);
			f=false;
			dfs(1,c,0);
			printf("%d\n",f);
		}
	}
	return 0;
}


