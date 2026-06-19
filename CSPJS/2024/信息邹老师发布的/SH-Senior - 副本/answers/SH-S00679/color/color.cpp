#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],vis[200010],ret;
map<int,map<int,int> >mp;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t --> 0){
		mp.clear();
		memset(vis,0,sizeof vis);
		int ret=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					mp[i][a[i]]=j;
					break;
				}
			}
		}int nxt=0,pre=0,prego=0;
		for(int i=1;i<=n;i++){
			if(i==nxt){
				nxt=0;
			}int j;
			if(mp[i][a[i]]!=0){
				if(nxt==0){
					prego=i,nxt=mp[i][a[i]],pre=a[i];
					ret+=a[i];
					vis[i]=1,vis[mp[i][a[i]]]=1;
				}else{
					if(a[i]>pre){
						vis[prego]=0,vis[nxt]=0;
						ret-=pre;
						prego=i,nxt=mp[i][a[i]],pre=a[i];
						vis[prego]=1,vis[nxt]=1;
						ret+=pre;
					}
				}
			}
		}for(int i=1;i<=n;i++){
			if(vis[i]==0){
				int j,f=0,f1=0;
				for(j=i+1;j<=n;j++){
					if(vis[j]==0){
						if(a[i]==a[j]){
							f=1;
							ret+=a[i];
						}break;
					}
				}if(f==1){
					i=j-1;
				}
			}
		}printf("%d\n",ret);
	}return 0;
}
