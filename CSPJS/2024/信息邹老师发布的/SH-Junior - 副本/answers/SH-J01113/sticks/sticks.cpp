#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int uses[10]={6,2,5,5,4,5,6,3,7,6};
int ans=INT_MAX;
bool ywc=0;
void dfs(int stick,int num,int step){
	if(stick<0) return;
	else if(stick==0){
		ans=min(ans,num);
		ywc=1;
	}
	for(int i=0;i<10;i++){
		if(step==0 && i==0) continue;
		if(stick-uses[i]>=0){
			dfs(stick-uses[i],num*10+i,step+1);
		}
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int times=0;times<t;times++){
		ans=INT_MAX;
		ywc=0;
		scanf("%d",&n);
		dfs(n,0,0);
		if(ywc==0) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
