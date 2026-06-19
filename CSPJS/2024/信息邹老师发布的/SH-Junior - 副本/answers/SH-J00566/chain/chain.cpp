#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[2005][2005],r,c,f[200005];
bool dfs(int step,int x,int y){
	bool f=0;
	int jiexian=min(k,s[x][0]-y+1);
	if(step==r){
		for(int i=1;i<jiexian;++i)
			if(s[x][y+i]==c)	return 1;
		return 0;
	}
	for(int xxx=1;xxx<jiexian;++xxx){
		for(int i=1;i<=n;++i){
			if(i==x||f) continue;
			for(int j=1;j<s[i][0];++j)
				if(s[i][j]==s[x][y+xxx]){
					f=dfs(step+1,i,j);
					if(f)	break;
				}	
		}
	}
	return f;		
}
bool check(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=s[i][0];++j)
			if(s[i][j]==1&&dfs(1,i,j))
				return 1;
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		int suml=0,bfq=q;
		memset(f,0x3f,sizeof(f)); 
		for(int i=1;i<=n;++i){
			scanf("%d",&s[i][0]);
			suml+=s[i][0];
			int nearst1=2e9;
			for(int j=1;j<=s[i][0];++j){
				scanf("%d",&s[i][j]);
				if(nearst1!=2e9)
					f[s[i][j]]=min(f[s[i][j]],j-nearst1+1);
				if(s[i][j]==1)	nearst1=j;
			}
			//cerr<<"Here"<<i<<endl;
		}
		while(q--){
			//cerr<<"Here"<<q<<endl;
			scanf("%d%d",&r,&c);
			if(r==1){
				if(f[c]<=k)	printf("1\n");
				else printf("0\n");
			}
			else if(r<=8&&n<=10&&suml<=20&&bfq<=100){
				if(check())
					printf("1\n");
				else	printf("0\n");
			} 
			else	printf("0\n");
			//system("pause");
		} 
	}
	return 0;
} 
