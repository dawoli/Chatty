#include<bits/stdc++.h>
using namespace std;

const unsigned long long MAXN = LONG_LONG_MAX;
int T,n2;
unsigned long long rst = MAXN;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
unsigned long long answers[55];

void dfs(int depth,int n,int sum){
	if (n<2) return;
	cout<<depth<<endl;
	for(int i = 0;i<10;i++)
	{
		if (i == 0 && depth == 1) continue;
		if(n>a[i])
		{
			dfs(depth+1,n-a[i],sum*10+i);
		} 
		else if(n==a[i])
		{
			rst = min(rst,(unsigned long long)(sum*10+i));
			return;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int t = 0;t<T;t++)
	{
		rst = MAXN;
		cin>>n2;
		dfs(1,n2,0);
		if(rst == MAXN) answers[t] = -1;
		else answers[t] = rst;
	}
	for(int i = 0;i<T;i++)
	{
		cout<<answers[i]<<endl;
	}
	return 0;
}
