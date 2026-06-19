#include<bits/stdc++.h>
#define Code using
#define By namespace
#define CChara std
Code By CChara;
#define int long long
struct people
{
	int a,b,c;
	int maxm,sub;//maxm为最大，sub为最大-最小 
}arr[214514];//推测是反悔贪心 
map<int,multiset<int> > m;//记录选择项中，最大和次大差最小的那个 
bool cmp(people A,people B)
{
	return A.maxm-A.sub>B.maxm-B.sub;
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//Please Check Before Handing In!!
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			arr[i].maxm=max(arr[i].a,max(arr[i].b,arr[i].c));
			if(arr[i].maxm==arr[i].a)
			{
				arr[i].sub=arr[i].maxm-max(arr[i].b,arr[i].c);
			}
			else if(arr[i].maxm==arr[i].b)
			{
				arr[i].sub=arr[i].maxm-max(arr[i].a,arr[i].c);
			}
			else
			{
				arr[i].sub=arr[i].maxm-max(arr[i].a,arr[i].b);
			}
			//处理最大与最大和次大差 
//			cout<<arr[i].maxm<<' '<<arr[i].sub<<endl;
		}
		random_shuffle(arr,arr+n);
		int ans=0;
		int a=0,b=0,c=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i].maxm==arr[i].a)
			{
				if(a<n/2)
				{
					ans+=arr[i].maxm;
					a++;
					m[0].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[0].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[0].erase(m[0].begin());
						ans=ans-tmp+arr[i].maxm;
						m[0].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else if(arr[i].maxm==arr[i].b)
			{
				if(b<n/2)
				{
					ans+=arr[i].maxm;
					b++;
					m[1].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[1].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[1].erase(m[1].begin());
						ans=ans-tmp+arr[i].maxm;
						m[1].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else
			{
				if(c<n/2)
				{
					ans+=arr[i].maxm;
					c++;
					m[2].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[2].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[2].erase(m[2].begin());
						ans=ans-tmp+arr[i].maxm;
						m[2].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
		}
		random_shuffle(arr,arr+n);
		int tmp=ans;
		m.clear();
		ans=0;
		a=0;b=0;c=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i].maxm==arr[i].a)
			{
				if(a<n/2)
				{
					ans+=arr[i].maxm;
					a++;
					m[0].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[0].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[0].erase(m[0].begin());
						ans=ans-tmp+arr[i].maxm;
						m[0].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else if(arr[i].maxm==arr[i].b)
			{
				if(b<n/2)
				{
					ans+=arr[i].maxm;
					b++;
					m[1].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[1].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[1].erase(m[1].begin());
						ans=ans-tmp+arr[i].maxm;
						m[1].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else
			{
				if(c<n/2)
				{
					ans+=arr[i].maxm;
					c++;
					m[2].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[2].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[2].erase(m[2].begin());
						ans=ans-tmp+arr[i].maxm;
						m[2].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
		}
		random_shuffle(arr,arr+n);
		m.clear();
		tmp=max(tmp,ans);
		ans=0;
		a=0;b=0;c=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i].maxm==arr[i].a)
			{
				if(a<n/2)
				{
					ans+=arr[i].maxm;
					a++;
					m[0].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[0].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[0].erase(m[0].begin());
						ans=ans-tmp+arr[i].maxm;
						m[0].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else if(arr[i].maxm==arr[i].b)
			{
				if(b<n/2)
				{
					ans+=arr[i].maxm;
					b++;
					m[1].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[1].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[1].erase(m[1].begin());
						ans=ans-tmp+arr[i].maxm;
						m[1].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
			else
			{
				if(c<n/2)
				{
					ans+=arr[i].maxm;
					c++;
					m[2].insert(arr[i].sub);
				}
				else
				{
					int tmp=*(m[2].begin());
					if(ans-tmp+arr[i].maxm>=ans)//值得反悔 
					{
						m[2].erase(m[2].begin());
						ans=ans-tmp+arr[i].maxm;
						m[2].insert(arr[i].sub);
					}
					else//不值得反悔 
					{
						ans+=(arr[i].maxm-arr[i].sub);
					}
				}
			}
		}
		cout<<max(tmp,ans)<<endl;
		m.clear();
	}
	return 0;
}

