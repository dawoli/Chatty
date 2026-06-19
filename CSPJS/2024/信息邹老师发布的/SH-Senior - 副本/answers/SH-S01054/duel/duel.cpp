#include<bits/stdc++.h>
using namespace std;
int n=0;
int a[100100];
int b[1000][2];
int main()
{
	//freopen("duel1.in","r",stdin);
	//freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(n<=30)
	{
	    int x=0;
	    int y=0;
	    int k=1;
	    int tmp=0;
		for(int i=1;i<=n;i++)
		{
		    x=a[i];
		    y=i; 
		    for(int j=i;j<=n;j++)
		    {
		    	if(x<a[j])
				{
					x=a[j];
					y=j;
				}
			}
		    tmp=a[i];
			a[i]=x;
			a[y]=tmp;	
		}    
		for(int i=1;i<=n;i++)
		{
		    if(a[i]!=a[i-1])
			{
				b[k][1]=a[i];
				b[k][2]+=1;
				k=k+1;
			}	
			else b[k-1][2]+=1;
		}          
		for(int i=1;i<=n;i++)
		if(b[i][2]>=b[i+1][2])ans=ans-b[i+1][2];
		else ans=ans-b[i][2];
	}
	else 
	{
		int b2=0;
		for(int i=1;i<=n;i++)
		    if(a[i]==2)b2++;
		if(b2*2>=n)ans=b2;
		else ans=n-b2;
	} 
	cout<<ans;
	return 0;
}

