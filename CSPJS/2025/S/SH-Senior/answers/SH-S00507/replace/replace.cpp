#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[200005][2][2000],t[200005][2][2000];
int dis[200005][2],dit[200005][2],ans=0;
bool bo[200005];
void compare(int que,int rep){
	if(dit[que][1]-dit[que][0]!=dis[rep][1]-dis[rep][0]){
		return;
	}
	for(int i=0;i<=dit[que][1]-dit[que][0];i++){
		if(dit[que][0]<dis[rep][0]){
			//cout<<11<<" ";
			return;
		}
		if(strlen(t[que][0])-dit[que][1]<strlen(s[rep][0])-dis[rep][1]){
			//cout<<22<<" ";
			return;
		}
		if(t[que][0][dit[que][0]+i]!=s[rep][0][dis[rep][0]+i]){
			//cout<<33<<" ";
			return;
		}
		if(t[que][1][dit[que][0]+i]!=s[rep][1][dis[rep][0]+i]){
			//cout<<44<<" ";
			return;
		}
		for(int j=1;j<=dis[rep][0];j++){
			if(t[que][0][dit[que][0]-j]!=s[rep][0][dis[rep][0]-j]){
				//cout<<55<<" ";
				return;
			}
		}
		for(int j=1;j<=strlen(s[rep][0])-dis[rep][1]-1;j++){
			if(t[que][0][dit[que][1]+j]!=s[rep][0][dis[rep][1]+j]){
				//cout<<66<<" "<<endl;
				return;
			}
		}
	}
	ans++;
	//cout<<que<<" "<<rep<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[i][0],s[i][1]);
		for(int j=0;j<=strlen(s[i][0]);j++){
			if(s[i][0][j]!=s[i][1][j]){
				dis[i][0]=j;
				break;
			}
		}
		for(int j=0;j<=strlen(s[i][0]);j++){
			if(s[i][0][j]!=s[i][1][j]){
				dis[i][1]=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",t[i][0],t[i][1]);
		if(strlen(t[i][0])!=strlen(t[i][1])){
			bo[i]=1;
			continue;
		}
		for(int j=0;j<=strlen(t[i][0]);j++){
			if(t[i][0][j]!=t[i][1][j]){
				dit[i][0]=j;
				break;
			}
		}
		for(int j=0;j<=strlen(t[i][0]);j++){
			if(t[i][0][j]!=t[i][1][j]){
				dit[i][1]=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(bo[i]==1){
			printf("0\n");
			continue;
		}
		ans=0;
		for(int j=1;j<=n;j++){
			compare(i,j);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
