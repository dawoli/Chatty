#include<bits/stdc++.h>
using namespace std;
int T,m,n,k,x0,y0,d0;
int debug_mod=0;
string input;
char mapp[1010][1010]={};
void test()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<mapp[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
void work()
{
	int x=x0,y=y0,d=d0,ans=1;
	for(int i=0;i<k;i++)
	{
		if(d==0)
		{
			if(mapp[x][y+1]=='x'||y+1>m)
			{
				if(debug_mod==1)   cout<<"turn right    d="<<d<<endl;
				d++;
			}
			else
			{
				y++;
				if(mapp[x][y]=='.')
				{
					mapp[x][y]='#';
					if(debug_mod==1)   cout<<"move_to:"<<x<<" "<<y<<endl;
					ans++;
				}
			 } 
		}
		else if(d==1)
		{
			if(mapp[x+1][y]=='x'||x+1>n)
			{
				if(debug_mod==1)   cout<<"turn right    d="<<d<<endl;
				d++;
				
			}    
			else
			{
				x++;
				if(mapp[x][y]=='.')
				{
					mapp[x][y]='#';
					if(debug_mod==1)   cout<<"move_to:"<<x<<" "<<y<<endl;
					ans++;
				}
			 }
			
		}
		else if(d==2)
		{
			if(mapp[x][y-1]=='x'||y-1<1)
			{
				if(debug_mod==1)   cout<<"turn right    d="<<d<<endl;
				d++;
				}    
			else
			{
				y--;
				if(mapp[x][y]=='.')
				{
					mapp[x][y]='#';
					if(debug_mod==1)   cout<<"move_to:"<<x<<" "<<y<<endl;
					ans++;
				}
			 }
			
		}
		else if(d==3)
		{
			if(mapp[x-1][y]=='x'||x-1<1)
			{
				if(debug_mod==1)   cout<<"turn right    d="<<d<<endl;
				d=0;
				}    
			else
			{
				x--;
				if(mapp[x][y]=='.')
				{
					mapp[x][y]='#';
					if(debug_mod==1)   cout<<"move_to:"<<x<<" "<<y<<endl;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return;
}
void Domain()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
		{
			cin>>input;
			input="0"+input;
			for(int j=1;j<=m;j++)
			{
				mapp[i][j]=input[j];
			}
		}
		mapp[x0][y0]='#';
		work();
		//test();
	}
	fclose(stdin);
	fclose(stdout);
	return;
}
int main()
{
	Domain();
	return 0;
}
