#include<bits/stdc++.h>
using namespace std;
int n,a[100005],tj[100005],x,b[100005],yd,sd,rz,s[100005],ans;
bool r1;
int main()
{
	freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
    	if(rz!=a[i])
    	{
    		x++;
		}
		b[x]++;
		rz=a[i];
	} //b[i]与r值无关，只表示大小 
	for(int i=1;i<=x;i++)
	{
		//s[i]=s[i-1]+b[i]; 
		//cout<<b[i]<<" "; 
	}
	int i=2;
	int j=1;
	yd=b[2];
	sd=b[1];
    while(i<=x&&j<=x-1)
    {
    	if(yd>=sd)
    	{
    		ans+=sd;
    		yd-=sd;
    		sd=0;
    		if(j+1==i)
    		{
    			i++;
    			j++;
    			yd=b[i];
    			sd+=b[j];
			}
			else
			{
				j++;
				sd+=b[j];
			}
		}
	    else
	    {
	    	ans+=yd;
	    	sd-=yd;
		    i++;
		    yd=0;
		    yd+=b[i];
	    }
	}
	cout<<n-ans;
	return 0;
 } 
