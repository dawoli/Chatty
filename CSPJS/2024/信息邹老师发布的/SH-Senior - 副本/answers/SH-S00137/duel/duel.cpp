#include<bits/stdc++.h> 
using namespace std;

int cmp(int a,int b)
{
	if (a>b) return true;
	return false;
}
int main(void)
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,tmp;
	scanf("%d",&n);
	int r[100005]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		r[tmp]++;
	}
	sort(r,r+100005,cmp);
	printf("%d",r[0]);
	return 0;
}
