#include <bits/stdc++.h>
using namespace std;
int n1,q;
struct rp
{
	string s1,s2;
};
struct sol
{
	string t1,t2;
};
rp m[200005];
sol n[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin >> n1 >> q;
    for(int i=1;i<=n1;i++)
        cin >> m[i].s1 >> m[i].s2;
    for(int i=1;i<=q;i++)
        cin >> n[i].t1 >> n[i].t2;
    for(int Q=1;Q<=q;Q++)
    {
    	int cnt=0;
    	for(int N=1;N<=n1;N++)
    	{
    		if((n[Q].t1.length()-n[Q].t2.length())!=(m[N].s1.length()-m[N].s2.length()))
    		    continue;
    		for(int i=0;i<=n[Q].t1.length()-1;i++)
    		{
    			if(n[Q].t1[i]==m[N].s1[0])
    			{
    				bool f=true;
    				for(int j=1;j<=m[N].s1.length()-1;j++)
    				{
    					if(n[Q].t1[i+j]!=m[N].s1[j])
    					{
    					    f=false;
    						break;
						}
					}
					if(f)
					{
						bool f2=true;
						for(int j=0;j<=n[Q].t2.length()-1;j++)
						{
							if(j<i)
							{
								if(n[Q].t1[j]!=n[Q].t2[j])
								{
									f2=false;
									break;
								}
							}
							if(j>=i&&j<(i+m[N].s2.length()))
							{
								if(m[N].s2[j-i]!=n[Q].t2[j])
								{
									f2=false;
									break;
								}
							}
							if(j>=(i+m[N].s2.length()))
							{
								if(n[Q].t1[j+m[N].s1.length()-m[N].s2.length()]!=n[Q].t2[j])
								{
									f2=false;
									break;
								}
							}
						}
						if(f2) cnt++;
					 } 
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
