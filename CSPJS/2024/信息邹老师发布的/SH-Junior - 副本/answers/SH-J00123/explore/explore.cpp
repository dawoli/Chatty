#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	 LL t=0;
	 cin>>t;
	 while(t--)
	 {
	 	LL ans=1;
	 	LL n,m,k,curx,cury,d;
	 	cin>>n>>m>>k>>curx>>cury>>d;;
	 	--curx;
	 	--cury;
	 	vector<vector<char> >mp(n,vector<char>(m));
	 	vector<vector<bool> >vis(n,vector<bool>(m,false));
	 	vis[curx][cury]=true;
	 	for(LL i=0;i<n;++i)
	 		for(LL j=0;j<m;++j)
	 			cin>>mp[i][j];
	 	while(k--)
	 	{
	 		LL tmpx=curx;
	 		LL tmpy=cury;
	 		if(d==0)
	 			++tmpy;
	 		else if(d==1)
	 			++tmpx;
	 		else if(d==2)
	 			--tmpy;
	 		else
	 			--tmpx;
	 		if(tmpx<0||tmpx>=n||tmpy<0||tmpy>=m||mp[tmpx][tmpy]=='x')
	 		{
	 			++d;
	 			d%=4;
			}
			else
			{
				curx=tmpx;
				cury=tmpy;
				
				if(!vis[curx][cury])
				{
					vis[curx][cury]=true;
					++ans;
				}
					
			}
		}
		cout<<ans<<endl;
	 }
	return 0;
}
