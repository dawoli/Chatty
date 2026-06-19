#include<bits/stdC++.h>
using namespace std;
int main()
{
	long long t,o,p,q;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
        {
            int long long x,y,z;
            cin>>x>>y>>z;
			if(x>=y && x>=z && y>=z)
			{
				if(o>=m/2)
				{
                    if(p>=m/2)
					{
						q+=z;
					}
					else
					{
					    p+=y;	
					}
				}
				else
			    {
				    o+=x;	
			    }
			} 	
			if(x>=y && x>=z && z>=y)
			{
				if(o>=m/2)
				{
					if(q>=m/2)
					{
						p+=y;
					}
					else
					{
					    q+=z;	
					}
				}
				else
			    {
				    o+=x;	
			    }
			}
			if(y>=x && y>=z && x>=z)
			{
				if(p>=m/2)
				{
					if(o>=m/2)
					{
						q+=z;
					}
					else
					{
					    o+=x;	
					}
				}
				else
			    {
				    p+=y;	
			    }
			}
			if(y>=x && y>=z && z>=x)
			{
				if(p>=m/2)
				{
					if(q>=m/2)
					{
						o+=x;
					}
					else
					{
					    q+=z;	
					}
				}
				else
			    {
				    p+=y;	
			    }
			}
			if(z>=x && z>=y && x>=y)
			{
				if(q>=m/2)
				{
					if(o>=m/2)
					{
						p+=y;
					}
					else
					{
					    o+=x;	
					}
				}
				else
			    {
				    q+=z;	
			    }
			}
			if(z>=x && z>=y && y>=x)
			{
				if(q>=m/2)
				{
					if(p>=m/2)
					{
						o+=x;
					}
					else
					{
					    p+=y;	
					}
				}
				else
			    {
				    q+=z;	
			    }
			}
		}	
		cout<<o<<" "<<p<<" "<<q<<endl;
		cout<<o+p+q<<endl;
		o=0;
		p=0;
		q=0;
	}
		
	return 0;
}
