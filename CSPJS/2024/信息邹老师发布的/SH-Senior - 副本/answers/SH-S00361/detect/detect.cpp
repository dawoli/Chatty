#include<bits/stdc++.h>
using namespace std;
struct node
{
	int d,a,v;
	bool ab;
	float l,r;
	vector <int> e;
}s[100005];
int de[100005];
struct node1
{
	int number;
	vector <int> y;	
}r[100005];
void clean()
{
	for(int i=0;i<100005;i++)
	{
		de[i]=0;
		s[i].a=0;
		s[i].d=0;
		s[i].l=0;
		s[i].r=0;
		s[i].v=0;
		s[i].e.clear();
		r[i].y.clear();
		r[i].number=0;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		clean();
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=0;i<n;i++)
		{
			cin>>s[i].d>>s[i].v>>s[i].a;
			if(s[i].a!=0)
			{
				if(s[i].a>0)
				{
					float dis=1.0*(v*v-s[i].v*s[i].v)/2/s[i].a;
					s[i].l=dis+s[i].d;
					s[i].r=l;
					s[i].ab=true;
				}
				if(s[i].a<0)
				{
					if(s[i].v>v)
						s[i].ab=true;
					else
						s[i].ab=false;
					float dis=1.0*(v*v-s[i].v*s[i].v)/2/s[i].a;
					s[i].l=s[i].d;
					s[i].r=s[i].d+dis;
				}
			}
			else
			{
				s[i].l=s[i].d;
				s[i].r=l;
				s[i].ab=false;
			}
			
			if(s[i].v>v)
				s[i].ab=true;
			
		}
		for(int i=0;i<m;i++)
			cin>>de[i];
		int u=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(de[j]>=s[i].l && de[j]<=s[i].r && s[i].ab==true)
				{
					u++;
					break;
				}	
			}	
		}	
		cout<<u<<" ";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(de[j]>=s[i].l && de[j]<=s[i].r && s[i].ab==true)
				{
					r[j].number++;
					r[j].y.push_back(i);
					s[i].e.push_back(j);
				}	
			}	
		}
		int ans=0;
		for(int w=0;w<m;w++)
		{
			if(r[w].number==1 && s[r[w].y[0]].e.size()==1)
				ans++;
				
			else if(w!=m-1)
			{
				int k=0;
				for(int i=0;i<r[w].y.size();i++)
				{
					for(int j=0;j<r[w+1].y.size();j++)
					{
						if(s[r[w].y[i]].ab==false)
							continue;
						if(r[w].y[i]==r[w+1].y[j])
						{
							k++;
							break;	
						}		
					}
				}
				if(k!=r[w].y.size())
				{
					for(int i=0;i<r[w].y.size();i++)
						s[r[w].y[i]].ab=false;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}

