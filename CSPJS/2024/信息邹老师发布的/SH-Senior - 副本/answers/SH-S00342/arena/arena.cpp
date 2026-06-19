#include<bits/stdc++.h>
using namespace std;
int T,n,a[105],ans;
int c[105];
int sum(int k)
{
	int x=0;
	for(int j=1;j<=k;j++)
		{
			int l=j-1;
			while(l>=1)
			{
				if(a[l]==a[j]&&c[l]==c[j])
				{
					//cout<<endl<<"R: "<<l<<" "<<j<<" "<<a[l]<<endl;
					x+=a[l];
					break;
				}
				l--;				
			}
		}
	return x;
}
int ap(int i,int k)
{
	if(i<k+1)
	{
		c[i]=1;
	    ap(i+1,k);
	    c[i]=0;
	    ap(i+1,k);
	}
	if(i==k+1)
	{
		//int x=0;
		for(int i=1;i<=k;i++)
		//{
		//	cout<<c[i]<<" ";
		//}
		//cout<<endl<<sum(k)<<" "<<endl<<endl;
		ans=max(ans,sum(k));
		//cout<<ans<<endl;
	}	
}


int main()
{
	freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
	cin>>T;
    for(int i=1;i<=T;i++)
    {
    	cin>>n;
    	ans=0;
    	for(int j=1;j<=n;j++) cin>>a[j];
    	ap(1,n);
    	cout<<ans<<endl;
	}
	//ap(1,8);
	return 0;
 } 
