#include<bits/stdc++.h>
using namespace std;
const int maxt = 50,maxn = 1e2 + 10;
int t,n;
int stick[10] = {6,2,5,5,4,5,6,3,7,6};
int k[maxt];
struct node{
	int num[maxn];
	int len;
	bool use;
	node(){
		len = 0;
		use = false;
		memset(num,0,sizeof(num));
	}
	node operator +(int a){
		node res = (*this);
		res.len ++;
		res.num[res.len] = a;
		return res;
	}
	friend bool operator <(node a,node b){
		if(!a.use)	return false;
		if(a.len < b.len)	return true;
		else if(a.len == b.len){
			for(int i = 1;i <= a.len;i ++){
				if(a.num[i] < b.num[i])	return true;
				else if(a.num[i] > b.num[i])	return false;
			}
			return false;
		}else	return false;
	}
	void print(){
		for(int i = 1;i <= len;i ++){
			printf("%d",num[i]);
		}
	}
}dp[maxn];

node m_min(node a,node b){
	return a < b ? a : b;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1;i <= t;i ++){
		scanf("%d",&k[i]);
		n = max(n,k[i]);
	}
	dp[0].use = true;
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j < 9;j ++){
			if(stick[j] > i)	continue;
			if(j == 0 && dp[i - stick[j]].num[1] == 0)	continue;
			if(dp[i - stick[j]].use){
				dp[i] = m_min(dp[i],dp[i - stick[j]] + j);
				dp[i].use = true;
			}
		}
	}
	for(int i = 1;i <= t;i ++){
		if(!dp[k[i]].use)	printf("-1");
		else	dp[k[i]].print();
		printf("\n");
	}
	return 0;
}
