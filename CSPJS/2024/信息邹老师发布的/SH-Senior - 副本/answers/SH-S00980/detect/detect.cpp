#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii qujian[1100000];
double zushu,n,m,L,V,di[110000],d[110000],v[110000],a[110000],qj;//di探头 
//struct vehicle{
//	int d,v,a;//d入口 v初速度 a加速度 
//}car[110000];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>zushu;
	for(int zu=1;zu<=zushu;zu++)
	{
		cin>>n>>m>>L>>V;
		
		//n车辆数 m测速仪数 L主干道长度 V道路限速 
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>di[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			double st=0,ss=-1,se=-1;//st开始超速(或停止超速)时间 ss开始超速位置，se为结束超速位置 
			st=((double)v[i]-V)/a[i];
			if(a[i]>0)
			{
				ss=d[i]+(V*V-v[i]*v[i])/(a[i]*2);
				ss=(int)(ss+1);
				se=L;
			}
			if(a[i]<0)
			{
				se=(int)(d[i]+(V*V-v[i]*v[i])/(a[i]*2));
//				if(se>L) se=L;
//				double o=0,p=0;//o为速度归零时间，p为离开位置
//				p=(V*V)
				ss=d[i];
				if(v[i]<=V&&ss==se) ss=-1,se=-1;
				if(ss>se) ss=-1,se=-1;
				
			}
			if(a[i]==0) 
			{
				if(v[i]>V)
				{
					ss=d[i];
					se=L;
				}
				else ss=-1,se=-1;
			}
			bool flag1=false,flag2=false;int aa,bb;bool flag=false;
			for(int j=1;j<=m;j++)//处理探测头 
			{
				if(di[j]>=ss&&di[j]<=se)
				{
					if(flag1==false)
					{
						aa=j;
					 } 
					bb=j;
					flag1=true;
					flag=true;
				}
			}
			if(flag==false)
			{
				cnt++;continue;
			 } 
			else
			{
				bool flag3=false;
				for(int j=1;j<=qj;j++)
				{
					if (!(aa<qujian[j].first&&bb<qujian[j].first||aa>qujian[j].second&&bb>qujian[j].second))
					{
						if(bb<qujian[j].second) qujian[j].second=bb;
						if(aa>qujian[j].first) qujian[j].first=aa;
						flag3=true;
					}//
				}
				if(flag3==false)
				{
					qj++;
					qujian[(int)qj].first=aa;
					qujian[(int)qj].second=bb;
				}
			}
			
		}
		cout<<(int)n-cnt<<' '<<m-(int)qj<<endl;
		n=0,m=0,L=0,V=0,qj=0;
		 qujian[1].first=0,qujian[1].second=0;
		memset(di,0,sizeof(di));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
	}
	return 0;
}
