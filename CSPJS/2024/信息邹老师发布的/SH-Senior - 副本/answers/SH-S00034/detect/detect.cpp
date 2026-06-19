#include<bits/stdc++.h>
using namespace std;
int t,n,m,length,v_lim,pcnt[100005],catch_cnt,monitor_cnt;
struct car{
	int startlocation,startv,a;
	double reach_v_lim;
	bool caught;
}carinformation[100005];
bool bmp(car x,car y)
{
	return x.reach_v_lim<y.reach_v_lim;
}
void runp()
{
	cin>>n>>m>>length>>v_lim;
	memset(pcnt,0,sizeof(pcnt));
//	cout<<1;
	catch_cnt=0,monitor_cnt=0;
	for(int i=1;i<=n;i++)
		carinformation[i].caught=false;
	vector<int> caught_by[3005];
	for(int i=1;i<=n;i++)
	{
		cin>>carinformation[i].startlocation>>carinformation[i].startv>>carinformation[i].a;
		if(carinformation[i].startv>v_lim)
			if(carinformation[i].a>=0)
				carinformation[i].reach_v_lim=carinformation[i].startlocation;
			else
			{
				double t=(v_lim-carinformation[i].startv)*1.0/carinformation[i].a;
				carinformation[i].reach_v_lim=carinformation[i].startlocation+carinformation[i].startv*t+0.5*carinformation[i].a*t*t;
//				cout<<i<<" "<<t<<" "<<carinformation[i].startv*t<<" "<<0.5*carinformation[i].a*t*t<<endl;
			}
		else
			if(carinformation[i].a>0)
			{
				double t=(v_lim-carinformation[i].startv)*1.0/carinformation[i].a;
				carinformation[i].reach_v_lim=carinformation[i].startlocation+carinformation[i].startv*t+0.5*carinformation[i].a*t*t;
//				cout<<i<<" "<<t<<" "<<carinformation[i].startv*t<<" "<<0.5*carinformation[i].a*t*t<<endl;
			}
			else
				carinformation[i].reach_v_lim=length+1;
	}
//	sort(carinformation+1,carinformation+1+n,bmp);
	for(int i=1;i<=m;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=n;j++)
		{
			if(p>=carinformation[j].startlocation&&carinformation[j].reach_v_lim!=length+1&&(carinformation[j].a>=0&&p>carinformation[j].reach_v_lim||carinformation[j].a<0&&p<=carinformation[j].reach_v_lim))
			{
				if(!carinformation[j].caught)
					carinformation[j].caught=true,pcnt[i]++;
				else
				{
					for(int k=0;k<caught_by[j].size();k++)
						pcnt[caught_by[j][k]]=max(0,pcnt[caught_by[j][k]]-1);
				}
				caught_by[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(carinformation[i].caught)
			catch_cnt++;
	for(int i=1;i<=m;i++)
		if(!pcnt[i])
			monitor_cnt++;
	cout<<catch_cnt<<" "<<monitor_cnt-1<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		runp();
	return 0;
}
/*
现在的问题：去重判定
*/ 
