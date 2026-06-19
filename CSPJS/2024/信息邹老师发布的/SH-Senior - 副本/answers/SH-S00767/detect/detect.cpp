#include<bits/stdc++.h>
using namespace std;
long long t,n,m,L,V,p[100010],pr[1000010],ans1,ans22;
bool f[100010];
struct node{
	long long s,v,a,end;
}car[100010];
void dfs(long long x)
{
	if(x==m+1)
	{
		memset(pr,0,sizeof(pr));
		long long ans2=0,cnt=0;
		for(long long i=1;i<=m;i++)
		{
			if(f[i])
			{
				pr[p[i]]++;
			}
			else cnt++;
		}
		if(cnt<=ans22) return ;
		for(long long i=1;i<=L+1;i++)
		{
			pr[i]+=pr[i-1];
		}	
		for(long long i=1;i<=n;i++)
		{
			if(pr[car[i].end-1]-pr[car[i].s-1]>=1)
			{
				ans2++;
			}
		}
		if(ans2==ans1)
		{
			ans22=cnt;
		}
		return ;
	}
	for(int i=m+1;i>=x+1;i--)
	{
		f[i]=1;
		dfs(i);
		f[i]=0;
	}
	return ;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool pd=1,pd2=1,pd3=1;
		memset(car,0,sizeof(car));
		memset(p,0,sizeof(p));
		memset(pr,0,sizeof(pr));
		memset(f,0,sizeof(f));
		ans1=0;
		ans22=0;
		cin>>n>>m>>L>>V;
//		cout<<n<<" "<<m<<" "<<L<<" "<<V<<endl;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&car[i].s,&car[i].v,&car[i].a);
//			if(i==2631) cout<<i<<" "<<car[i].s<<" "<<car[i].v<<" "<<car[i].a<<endl;
			if(car[i].a==0)
			{
				pd2=0;
				pd3=0;
				if(car[i].v>V)
				{
					car[i].end=L+1;
				}
				else car[i].end=car[i].s;
			}
			if(car[i].a>0)
			{
				pd=0;
				pd3=0;
				if(car[i].v>V)
				{
					car[i].end=L+1;
				}
				else if(car[i].v==V)
				{
					car[i].s++;
					car[i].end=L+1;
				}
				else{
					double time=(double)(V-car[i].v)/(double)car[i].a;
					if(time>10000.0)
					{
						car[i].s=1;
						car[i].end=1;
					}
					else{
						double wy=(double)car[i].v*time+0.5*(double)car[i].a*time*time;
						car[i].s=car[i].s+(long long)(wy)+1;
						if(car[i].s>L)
						{
							car[i].s=1;
							car[i].end=1;
						}
						else{
							car[i].end=L+1;
						}
					}
//					cout<<i<<" "<<car[i].s<<" "<<car[i].end<<endl;
				}
			}
			if(car[i].a<0)
			{
				pd=0;
				pd2=0;
				if(car[i].v>V)
				{
//					double ent=(car[i].v)/car[i].a*(-1.0);
//					double wyen=car[i].v*ent+0.5*car[i].a*ent*ent;
					double time=(double)(car[i].v-V+0.0001)/(double)car[i].a*(-1.0);
					double wy=(double)car[i].v*time+0.5*(double)car[i].a*time*time;
					car[i].end=car[i].s+(long long)ceil(wy);
					car[i].end=min(car[i].end,L+1);
//					cout<<car[i].end<<endl;
				}
				if(car[i].v<=V)
				{
					car[i].end=car[i].s;
				}
			}
		}
		for(long long i=1;i<=m;i++)
		{
			cin>>p[i];
			pr[p[i]]++;
		}
		for(long long i=1;i<=L+1;i++)
		{
			pr[i]+=pr[i-1];
		}
		for(long long i=1;i<=n;i++)
		{
			if(pr[car[i].end-1]-pr[car[i].s-1]>=1)
			{
				ans1++;
//				cout<<i<<"	";
			}
		}
		cout<<ans1<<" ";
		if(pd==1)
		{
			if(ans1==0)
			{
				cout<<m<<endl;
			}
			else cout<<m-1<<endl;
		}
		else if(pd2==1)
		{
			if(ans1==0)
			{
				cout<<m<<endl;
			}
			else cout<<m-1<<endl;
		}
		else{
			dfs(0);
			cout<<ans22<<endl;
		}
	}
	return 0;
}
