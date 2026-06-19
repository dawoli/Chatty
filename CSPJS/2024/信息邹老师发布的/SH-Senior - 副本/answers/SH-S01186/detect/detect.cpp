#include<bits/stdc++.h>
using namespace std;
double t,n,m,l,v,p[100004],cnt;
bool f;
struct NODE{
	double d,v,a;//dva为汽车参数 
	double s,e;//[s,e]为汽车会被抓拍超速的范围
	bool flag,f1;//flag是否存在超速路段,f1一开始有没有拍到超速
	bool l,r;//判断区间开闭l=true为闭 
}car[100004];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		f=true;
		memset(car,0,sizeof(car));
		memset(p,0,sizeof(p));
		cnt=0;
		scanf("%lf %lf %lf %lf",&n,&m,&l,&v);
		//cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf %lf %lf",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].a!=0)f=false;
		}//判断车的情况 
		for(int i=1;i<=m;i++)cin>>p[i];
		if(f==true)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=m;j>=1;j--)
				{
					if(p[j]>=car[i].d&&car[i].v>v){cnt++;break;}
				}
			}
		}
		if(cnt==0)cout<<cnt<<" "<<m<<endl;
		else{cout<<cnt<<" "<<m-1<<endl;}
	}
	return 0;
}
