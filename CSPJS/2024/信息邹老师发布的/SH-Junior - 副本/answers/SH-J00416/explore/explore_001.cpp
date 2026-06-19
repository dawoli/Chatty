#include<bits/stdc++.h>
using namespace std;
int TTT;
int n,m,k,x,y,d;
char mat[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
map<pair<int,int>,int> mp;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&TTT);
	while(TTT--){
		mp.clear();
		int i,j,ans=1,cnt=0;
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(i=1;i<=n;++i)
			scanf("%s",mat[i]+1);
		mp[make_pair(x,y)]=1;
		while(cnt<k){
			while((x+dx[d]<1||x+dx[d]>n||y+dy[d]<1||y+dy[d]>m||mat[x+dx[d]][y+dy[d]]=='x')&&cnt<k){
				cnt++;
				d=(d+1)%4;	
			}
			if(cnt>=k) break;
			int tx=x+dx[d],ty=y+dy[d];
			if(mp[make_pair(tx,ty)]!=1){
				ans++;	
				mp[make_pair(tx,ty)]=1;
			}	
			x=tx,y=ty;
			cnt++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
