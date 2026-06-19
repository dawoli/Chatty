#include<bits/stdc++.h> 
using namespace std;

int main(void)
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,aa;
	scanf("%d",&t);
	int ans[t][2]={0};
	for(int i=0;i<t;i++)
	{
	    int n,m,l,vx,lt=0;
	    scanf("%d %d %d %d",&n,&m,&l,&vx);
	    int d[n],v[n],a[n];//d:0;v:1;a;2
	    int p[m],det[n]={0};
	    for(int j=0;j<n;j++)
	    {
	    	scanf("%d %d %d",&d[j],&v[j],&a[j]);
		    if(a[0]==0)
		    {
		    	if(v[j]>vx)
		    	{
		    		det[j]++;
		    	    ans[i][0]++;
		    	    //lt=max(lt,d[j]);
				}
	    	}
		}
		if(a[0]==0) aa=0;
		int aaaa=0;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&p[j]);
			aaaa=max(aaaa,p[j]);
		}
	    for(int j=0;j<n;j++)
	    {
	    	if(d[j]>aaaa && det[j]!=0)
	    	{
	    		ans[i][0]--;
			}
		}
		ans[i][1]=m-1;
		if (ans[i][0]==0)
		    ans[i][1]++;
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
