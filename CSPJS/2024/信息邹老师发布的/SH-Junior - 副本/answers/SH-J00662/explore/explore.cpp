#include <bits/stdc++.h>

using namespace std;
struct node
{
	int xx;
	int yy;	
};
char a[1010][1010];
bool flag[1010][1010];
int n,m,k,x,y,d;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		memset(a,0,sizeof(a));
		int cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
	
		for(int i=1;i<=n;i++)
		{

			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				
			}
			
		}	
	
		if(n==1)
		{
			int j=1;
			int ans=0;
			if(d==0)
			{
				while(a[1][j]!=0)
				{
					ans++; 
					j++;
				}
				if(k<=ans)
				{
					cout<<k+1<<endl;
				}
				else
				{
					cout<<ans+1<<endl;
				}
				continue;
			}
			if(d==1)
			{
				while(a[1][j]!=0)
				{
					ans++; 
					j++;
				}
				if(k<=ans)
				{
					cout<<k-2<<endl;
				}
				else
				{
					cout<<ans-2<<endl;
				}
				continue;
			}
			if(d==2)
			{
				while(a[1][j]!=0)
				{
					ans++; 
					j++;
				}
				if(k<=ans)
				{
					cout<<k-1<<endl;
				}
				else
				{
					cout<<ans-1<<endl;
				}
				continue;
			}
			if(d==3)
			{
				while(a[1][j]!=0)
				{
					ans++; 
					j++;
				}
				if(k<=ans)
				{
					cout<<k<<endl;
				}
				else
				{
					cout<<ans<<endl;
				}
				continue;
			}
		}
		node q;
		q.xx=x;
		q.yy=y;
		
		while(k>=-2)
		{
		//	cout<<cnt<<" ";
			if(d==0&&a[q.xx][q.yy+1]=='.'&&(q.yy+1)<=m&&flag[q.xx][q.yy+1]==0)
			{
				//cout<<"wefhwo";
				q.yy+=1;
				cnt++;
				flag[q.xx][q.yy+1]=1;
				continue;
			}
			if(d==1&&a[q.xx+1][q.yy]=='.'&&(q.xx+1)<=n&&flag[q.xx+1][q.yy]==0)
			{
				q.xx+=1;
				cnt++;
				flag[q.xx+1][q.yy]=1;
				continue;
			}
			if(d==2&&a[q.xx][q.yy-1]=='.'&&(q.yy-1)>0&&flag[q.xx][q.yy-1]==0)
			{
				q.yy-=1;
				cnt++;
				flag[q.xx][q.yy-1]=1;
				continue;
			}
			if(d==3&&a[q.xx-1][q.yy]=='.'&&(q.xx-1)>0&&flag[q.xx-1][q.yy]==0)
			{
				q.xx-=1;
				cnt++;
				flag[q.xx-1][q.yy]=1;
				continue;
			}
			d=(d+1)%4;
			
			k--;
		}
		
		cout<<cnt<<endl;
			
		
		
	}
	
	
	
	
	
	
	return 0;
}
/*
1
1 5 4
1 1 2
....x

5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/
