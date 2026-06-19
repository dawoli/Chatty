#include<bits/stdc++.h>
using namespace std;
struct monster
{
    int r;
    int f;
    int l;
};
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n,left,len=0;
    int rr,atk;
    int count[100002];
    monster a[100002];
	memset(count,0,sizeof(count));

    int i,j;

    cin>>n;
    left=n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&rr);
        count[rr]++;
    }
    for(i=1;i<=100000;i++)
    {
    	if(count[i]!=0)
    	{
    		a[len].r=i;
    		a[len].f=count[i];
    		a[len].l=count[i];
    		len++;
		}
	}
    for(i=0;i<len;i++)
    {
        j=i+1;
        while(a[i].l!=0)
        {
        	while(a[j].f==0 && j<len) j++;
        	if(j==len) break;
        	atk=min(a[i].l,a[j].f);
        	a[i].l-=atk;
        	a[j].f-=atk;
        	left-=atk;
		}
        if(j==len) break;
    }
    cout<<left;

    return 0;
}
