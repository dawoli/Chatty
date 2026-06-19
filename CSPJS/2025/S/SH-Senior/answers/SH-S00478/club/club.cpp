#include<bits/stdc++.h>
using namespace std;
const int BIG=100001;
int n;
int sata[BIG],satb[BIG],satc[BIG];
long long ans;
vector<int> cluba,clubb,clubc;
void input()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sata[i]>>satb[i]>>satc[i];
	}
	return;
}
void abc(int i)
{
	if(sata[i]>satb[i])
	{
		if(sata[i]>satc[i])
		{
			cluba.push_back(i);
		}
		else
		{
			clubc.push_back(i);
		}
	}
	else
	{
		if(satb[i]>satc[i])
		{
			clubb.push_back(i);
		}
		else
		{
			clubc.push_back(i);
		}
	}
	return;
}
bool check_half()
{
	if( ( (cluba.size()>n/2)||(clubb.size()>n/2) )||(clubc.size()>n/2) )
	{
		return true;
	}
	return false;
}

void add()
{
	for(int i=0;i<cluba.size();i++)
	{
		ans+=sata[cluba[i]];
	}
	for(int i=0;i<clubb.size();i++)
	{
		ans+=satb[clubb[i]];
	}
	for(int i=0;i<clubc.size();i++)
	{
		ans+=satc[clubc[i]];
	}
	return;
}
void reassign()
{
	if(cluba.size()>n/2)
	{ 
		while(cluba.size()>n/2)
		{
			int min=20001,min_num;
			int tmp;
			for(int i=1;i<=n;i++)
			{
				if(satb[i]>satc[i])
				{
					tmp=sata[i]-satb[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
				else
				{
					tmp=sata[i]-satc[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
			}
			ans-=min;
			cluba[min_num]=cluba[cluba.size()-1];
			cluba.pop_back();
		}
	}
	else if(clubb.size()>n/2)
	{
		while(clubb.size()>n/2)
		{
			int min=20001,min_num;
			int tmp;
			for(int i=1;i<=n;i++)
			{
				if(sata[i]>satc[i])
				{
					tmp=satb[i]-sata[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
				else
				{
					tmp=satb[i]-satc[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
			}
			ans-=min;
			clubb[min_num]=clubb[clubb.size()-1];
			clubb.pop_back();
		}
	}
	else
	{
		while(clubc.size()>n/2)
		{
			int min=20001,min_num;
			int tmp;
			for(int i=1;i<=n;i++)
			{
				if(satc[i]>sata[i])
				{
					tmp=satc[i]-sata[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
				else
				{
					tmp=satc[i]-satb[i];
					if(tmp<min)
					{
						min=tmp;
						min_num=i;
					}
					if(tmp==0)
					{
						break;
					}
				}
			}
			ans-=min;
			clubc[min_num]=clubc[clubc.size()-1];
			clubc.pop_back();
		}
	}
	return;
}
void clear_all()
{
	cluba.clear();
	clubb.clear();
	clubc.clear();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		clear_all();
		ans=0;
		input();
		for(int i=1;i<=n;i++)
		{
			abc(i);
		}
		add();
		if(check_half())
		{
			reassign();
		}
		cout<<ans<<endl;
	}
	return 0;
}
