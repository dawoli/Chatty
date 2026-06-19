//½á¹û³ıÒÔ2js!!!!! 
#include<iostream>
#include<algorithm>
using namespace std;
int v,l;
struct Car{
	int etr;
	int ys,js;
	long long s,e;
	Car(int etrr,int yss,int jss)
	{
		etr=etrr; ys=yss; js=jss;
		long long t=(v-ys);
		if (js==0)
		{
			if (ys>v)
			{
				s=etr;
				e=l;
			}
			else
			{
				s=l;
				e=l;
			}
		}
		else if (ys>v)
		{
			
			s=etr*2*js;
			if (js>=0) e=l*2*js;
			else e=v*v-ys*ys+s;
		}
		else
		{
			e=l*2*js;
			if (js<=0) s=l*2*js;
			else s=v*v-ys*ys+etr;
		}
	}
};
long long jsd[10002];
long long st[10002];
long long ed[10002];
long long cs[10002];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	int t; cin>>t;
	while (t--)
	{
		int n,m; cin>>n>>m>>l>>v;
		for (int i=0;i<n;i++)
		{
			int d,v,a; cin>>d>>v>>a;
			Car b=Car(d,v,a);
			st[i]=b.s;
			ed[i]=b.e;
			jsd[i]=a;
			//cout<<st[i]<<" "<<ed[i]<<" "<<jsd[i]<<endl; 
		}
		for (int i=0;i<m;i++)
		{
			cin>>cs[i];
		}
		int ad=0,sb=0;
		for (int i=0;i<n;i++)
		{
			if (st[i]!=l)
			{
				if (jsd[i]!=0)
				{
					bool flag=0;
					for (int j=0;j<m;j++)
					{
						if (jsd[i]>0)
						{
							if (cs[j]*jsd[i]*2>=st[i] && cs[j]*jsd[i]*2<=ed[i])
							{
								flag=1;
								break;
							}
						}
						else
						{
							if (-cs[j]*jsd[i]*2>=-st[i] && -cs[j]*jsd[i]*2<=-ed[i])
							{
								flag=1;
								break;
							}
						}
					}
					if (flag)
					{
						ad++;
					}
				}
				else ad++;
			}
		 }
		 bool visc[1000002]={0,};
		 bool vis[1000002]={0,};
//		 sort(st,st+n);
//		 sort(ed,ed+n);
//		 sort(jsd,jsd+n);
		for (int i=n-1;i>0;i--)
		{
			if (!vis[i] && st[i]!=l)
			{
				for (int j=m-1;j>0;j--)
				{
				
					if (!visc[j]&&cs[j]*jsd[i]*2>=st[i] && cs[j]*jsd[i]*2<=ed[i])
					{
						visc[j]=1;
						sb++;
						cout<<cs[j]<<endl;
						for (int x=i;x<n;x++)
						{
							if (cs[j]*jsd[x]*2>=st[x] && cs[j]*jsd[x]*2<=ed[x])
							{
								vis[x]=1;
							}
							else break;
						}
					}
				}
			}
		}
		cout<<ad<<" "<<sb<<endl;
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ©\2
6 4 ©\4
2 5 8 9 15
*/
