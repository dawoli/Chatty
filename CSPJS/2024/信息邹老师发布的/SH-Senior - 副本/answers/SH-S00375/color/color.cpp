#include<bits/stdc++.h>
using namespace std;
#define MAXN 200007
#define ll long long
int T;
int n;
int a[MAXN];
ll score(bool color[]){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(color[j]!=color[i]) continue;
			if(a[j]==a[i]) ans+=a[i];
			break;
		}
	}
	return ans;
}
ll maxScore=0;
void dfs(int pos,bool color[]){
	if(pos==n){
		ll currentScore=score(color);
		maxScore=currentScore>maxScore?currentScore:maxScore;
//		printf("::%d\n",currentScore);
//			for(int i=1;i<=n;i++){
//				printf("%d",color[i]);
//			}cout<<endl;
		return;
	}
	pos++;
	color[pos]=0;
	dfs(pos,color);
	color[pos]=1;
	dfs(pos,color);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		bool c[MAXN]={};
		dfs(0,c);
		printf("%d\n",maxScore);
		maxScore=0;
	}
	return 0;
}
