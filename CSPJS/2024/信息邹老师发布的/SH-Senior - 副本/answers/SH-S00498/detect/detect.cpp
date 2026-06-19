#include<bits/stdc++.h>
using namespace std;
struct node
{
	int d,v,a;
} c[3005];
struct twice
{
	int l,r;
};
bool cmp(twice x,twice y)
{
	if(x.l!=y.l)
	    return x.l>y.l;
	return x.r>y.r;
}
bool cmp2(twice x,twice y)
{
	if(x.l!=y.l)
	    return x.l<y.l;
	return x.r<y.r;
}
int T,n,m,L,V,ans1,ans2,ans3,p[3005];
bool vis[3005][3005],mid[3005][3005],b[3005];
vector<twice> q,q1,q2;
const double eps=0.00001;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>T;
    while(T--)
    {
    	memset(vis,false,sizeof(vis));
    	memset(mid,false,sizeof(vis));
    	memset(b,false,sizeof(b));
    	ans1=0;
    	ans2=0;
    	ans3=0;
    	q.clear();
    	q1.clear();
    	q2.clear();
    	cin>>n>>m>>L>>V;
    	if(n>3000||m>3000)
    	    return 0;
    	for(int i=1;i<=n;i++)
    	    cin>>c[i].d>>c[i].v>>c[i].a;
    	for(int i=1;i<=m;i++)
    	    cin>>p[i];
    	for(int i=1;i<=n;i++)
    	{
    		int l=0,r=0;
    		bool flag=false;
    		for(int j=1;j<=m;j++)
    		{
    			int dis,sq;
    			double v1;
    			dis=p[j]-c[i].d;
    			sq=c[i].v*c[i].v+2*c[i].a*dis;
    			if(dis<0||sq<0)
    			    continue;
    			v1=sqrt(sq);
    			if(v1-V>eps)
    			{
    				vis[i][j]=true;
					flag=true;
					if(!l)
					    l=j;
					r=j;
				}
			}
			if(flag)
			{
				ans1++;
				b[i]=true;
				q1.push_back((twice){l,r});
			}
		}
		cout<<ans1<<" ";
		/*
		for(int i=1;i<=n;i++)
		{
		    for(int j=1;j<=m;j++)
		        cout<<vis[i][j]<<" ";
		    cout<<endl;
		}
		*/
		for(int i=0;i<ans1;i++)
		{
			for(int j=0;j<ans1;j++)
			{
				if(i==j)
				    continue;
				if(q1[i].l<=q1[j].l&&q1[i].r>=q1[j].r)
				{
					q1[i].l=-1;
					q1[i].r=-1;
				}
			}
		}
		for(int i=0;i<ans1;i++)
		    if(q1[i].l!=-1)
		    	q.push_back(q1[i]);
		sort(q.begin(),q.end(),cmp);
		ans1=q.size();
		for(int i=0;i<ans1;i++)
			for(int j=q[i].l;j<=q[i].r;j++)
				mid[i][j]=true;
		/*
		for(int i=0;i<ans1;i++)
		{
		    for(int j=1;j<=m;j++)
		        cout<<mid[i][j]<<" ";
		    cout<<endl;
		}
		*/
		for(int i=1;i<=m;i++)
		{
			int l=-1,r=-1;
			for(int j=ans1-1;j>=0;j--)
			{
				if(mid[j][i])
				{
					if(l==-1)
					    l=ans1-j-1;
					r=ans1-j-1;
				}
			}
			if(l!=-1&&r!=-1)
			{
				ans2++;
				q2.push_back((twice){l,r});
			}
		}
		sort(q2.begin(),q2.end(),cmp2);
		int top=0;
		for(int i=0;i<ans2;i++)
		{
			if(q2[i].l>top)
			{
				top=q2[i-1].r+1;
				ans3++;
			}
			if(q2[i].r==ans1-1)
			{
				top=ans1-1;
				ans3++;
				break;
			}
		}
		cout<<m-ans3<<endl;
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
vis
0 0 0 0 0
0 0 0 0 1
0 1 1 1 1
0 1 1 0 0
0 0 0 0 0
*/

