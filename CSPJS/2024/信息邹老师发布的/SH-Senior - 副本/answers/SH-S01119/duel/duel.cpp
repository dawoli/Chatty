#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
int n,r[100005],x,cnt[100005],ans;
bool used[100005];
priority_queue<int,vector<int>,greater<int> > ba;
int main(){
	freopen("duel.in","r",stdin);freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		cnt[r[i]]++;
		if(used[r[i]])continue;
		used[r[i]]=1;
		ba.push(r[i]);
	}
	x=ba.top();
	ans=cnt[x];
	while(ba.size()){
		x=ba.top();
		ba.pop();
		if(cnt[x]>ans)ans=cnt[x];
		//printf("%d ",ans);
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
