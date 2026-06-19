#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int n,f;
bool cmp(int x,int y)
{
	return x<y; 
}

int main()	
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

    cin>>n;
    f=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	
	}
	sort(a+1,a+1+n,cmp);
	for(int j=1;j<=n;j++)
	{
		for(int k=j;k<=n;k++)
		{if(b[k]!=1)
		 {if(a[j]<a[k])
			{b[j]=-1;
			 b[k]=1;
			 f--;
			 break;				
			}
		 }
		 
		 
		
		}
	}
	cout<<f;
	return 0;
	
}
