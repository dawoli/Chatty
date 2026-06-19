#include<bits/stdc++.h>
using namespace std;
int CCF,n;
int ans[10005],ans_l,m[10005];
int st_nums[]={6,2,5,5,4,5,6,3,7,6};
bool check(int m_l)
{
	if(m_l<ans_l)return 1;
	else if(m_l>ans_l)return 0;
	else
	{
		for(int i=0;i<m_l;++i){
			if(m[i]>ans[i])
				return 0;
			else if(m[i]<ans[i])
				return 1;
		}
	}
}
void dfs(int layer,int k,int flag_0){
	if(layer>ans_l||k==1)
		return;
	if(k==0){
		if(check(layer)){
			copy(m,m+layer,ans);
			ans_l=layer;
		}
		return;
	}
	for(int i=(flag_0==1?0:1);i<=9;++i)
	{
		if(k<st_nums[i])
			continue;
		m[layer]=i;
		dfs(layer+1,k-st_nums[i],1);
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&CCF);
	while(CCF--){
		scanf("%d",&n);
		memset(ans,0x3f,sizeof(ans));
		ans_l=INT_MAX;
		dfs(0,n,0);
		if(ans_l==INT_MAX)
			printf("%d\n",-1);
		else{
			for(int i=0;i<ans_l;++i)
				printf("%d",ans[i]);
			printf("\n");
		}	
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
