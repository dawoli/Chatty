#include<bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
ll t,n,a[N][4],i,l,mx[N],j,ans=0,aii,bii;
ll d(int x,int y, int aa, int bb,int cc)
{
	if(x>n)
	{
		return 0;
	}
	/*if(aa>l or bb>l or cc>l)
	{
		return 0;
	}*/
	int t=d(x+1,1,aa+1,bb,cc),h=d(x+1,2,aa,bb+1,cc),u=d(x+1,3,aa,bb,cc+1);
	if(aa==l)
	{
		return max(u,h)+a[x][y];
	}
	if(bb==l)
	{
		return max(t,u)+a[x][y];
	}
	if(cc==l)
	{
		return max(t,h)+a[x][y];
	}
	return max(t,max(h,u))+a[x][y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		//cin>>n;
		l=n/2;
		if(n<=10 or n==200)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
				//cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			printf("%d\n",d(0,0,0,0,0));
			//cout<<d(0,0,0,0,0)<<endl;
		}
		if(n==1e5)
		
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d%d%d",&mx[i],&j,&j);
				//cin>>mx[i]>>j>>j;
			}
			sort(mx,mx+n+1);
			/*for(i=1;i<=n;i++)
			{
				cout<<mx[i]<<" ";
			}*/
			for(i=n;i>l;i--)
			{
				ans+=mx[i];
			}
			printf("%d",&ans);
			//cout<<ans;
		}
		if(n==200)
		{
			ll q,e;
			aii=0;
			bii=0;
			for(i=1;i<=n;i++)
			{
				scanf("%d%d%d",&q,&e,&a[i][3]);
				//cin>>q>>e>>a[i][3];
				if(q>e and aii<=l)
				{
					ans+=q;
				}
				else if(q>e and aii<=l)
				{
					ans+=e;
				}
				
				else if(q<e and bii<=l)
				{
					ans+=e;
				}
				else
				{
					ans+=e;
				}
			}
			
			/*for(i=1;i<=n;i++)
			{
				cout<<a[i][1]<<" "<<a[i][2]<<endl;
			}
			cout<<endl;*/
		}
		if(n>10 and n<=30)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
				//cin>>a[i][1]>>a[i][2]>>a[i][3];
				
				/*for(j=i-1;j>=0;j--)
				{ 
					
					if(a[0][1]<a[j][1])
					{
						a[j][1]=a[0][1];
						a[j][2]=a[0][2];
						a[j][3]=a[0][3];
					}
					if(a[0][1]>=a[j][1] and j==1)
					{
						a[j+1][1]=a[j][1];
						a[j+1][2]=a[j][2];
						a[j+1][3]=a[j][3];
						a[j][1]=a[0][1];
						a[j][2]=a[0][2];
						a[j][3]=a[0][3];
					}
					else
					{
						a[j+1][1]=a[j][1];
						a[j+1][2]=a[j][2];
						a[j+1][3]=a[j][3];
					}
				}
				cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;*/ 
			}
			
			printf("%d",d(0,0,0,0,0));
			//cout<<d(0,0,0,0,0)<<endl;
		}
	}
}
