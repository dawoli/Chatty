#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[]={6,2,5,5,4,5,6,3,7,6};
ll n,T,minn=0x3f3f3f3f;
bool flag=false;
void dfs(ll w,ll sn,ll numb){
	if(sn<0)return;
	if(sn==0){
		minn=min(minn,numb);
		flag=true;
		return;
	}
	for(ll i=(w==0?1:0);i<=9;i++)
	  dfs(w+1,sn-num[i],numb*10+i);
}
int main(){
	freopen("sticks.in","w",stdin);
	freopen("sticks.out","r",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		flag=false;
		dfs(0,n,0);
		if(flag)printf("%d\n",minn);
		else printf("-1\n");
		minn=0x3f3f3f3f;
	}
	return 0;
}
