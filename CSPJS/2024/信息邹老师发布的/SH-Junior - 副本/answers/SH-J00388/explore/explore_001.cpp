#include<bits/stdc++.h>
using namespace std;
int d1[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool a[1005][1005];
string s[1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;
	cin>>t;
	while (t--)
	{
		memset(a,0,sizeof(a));
		int sum=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		a[--x][--y]=1;
		for (int i=0;i<n;i++)
		    cin>>s[i];
	    while (k--)
	    {
	    	int tmp1=x+d1[d][0];
	    	int tmp2=y+d1[d][1];
	    	if (tmp1<n && tmp1>=0 && tmp2<m && tmp2>=0)
	    	{
	    		if (s[tmp1][tmp2]!='x')
	    		{
	    			x=tmp1;
	    			y=tmp2;
				}
				else
				    d=(d+1)%4;
			}
			else
			    d=(d+1)%4;
		    if (!a[x][y])
		    {
		    	a[x][y]++;
		        sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

