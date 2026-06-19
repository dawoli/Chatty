#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
int n_c[100001][3];
int p[100001];
double x_c,d_c[10001][2];
int d_cz[10001];
int c_k[10001],s;
int sum;
bool bj[10001];
int dis_s[100001];
void sub(int n,int m,int l,int v_l)
{
	for(int i=1;i<=n;i++)
	{
		double d,v_0,a;
		d=n_c[i][0];
		v_0=n_c[i][1];
		a=n_c[i][2];
		if(v_0>v_l&&a>=0)
		{
			d_c[i][0]=d;
			d_c[i][1]=l;
			d_cz[i]=2;
			continue;
		}
		if(v_0<=v_l&&a<=0)
		{
			d_c[i][0]=-1;
			d_c[i][1]=-1;
			d_cz[i]=3; 
			continue;
		}
		x_c=(v_l*v_l-v_0*v_0)/(2*a);
		d_c[i][0]=d;
		if(x_c+d>l)
		{
			if(a<0)
			{
				d_c[i][1]=l;
				d_cz[i]=2;
			}
			else
			{
				if(a>0)
				{
					d_c[i][0]=-1;
					d_c[i][1]=-1;
					d_cz[i]=3;
				}
			
			}
		}
		else
		{
			d_c[i][1]=d+x_c;
			if(a>0)
				d_cz[i]=0;
			else
				d_cz[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		{
			int pos_d=p[j];
			if(d_c[i][0]<=pos_d&&d_c[i][1]>pos_d&&d_cz[i]!=0&&d_cz[i]!=3&&bj[i]==false)
			{
				sum++;bj[i]=true;continue;
			}
			if(d_c[i][0]<pos_d&&d_c[i][1]>=pos_d&&d_cz[i]!=1&&d_cz[i]!=3&&bj[i]==false)
			{
				sum++;bj[i]=true;continue;
			}
				
		}
	}
	long long s_1=0;
	for(int i=1;i<=n;i++)
	{
		bool bl=true;
		for(int j=1;j<=m;j++)
		{
			
			int pos_d=p[j];
			if(d_c[i][0]<=pos_d&&d_c[i][1]>pos_d&&d_cz[i]!=0&&d_cz[i]!=3)
			{
				for(int t=1;t<=s_1-1;t++)
				{
					if(c_k[t]==j)
					{
						
					}
				}
			}
			
			else
			{
				if(d_c[i][0]<pos_d&&d_c[i][1]>=pos_d&&d_cz[i]!=1&&d_cz[i]!=3)
				{
					
					for(int t=1;t<=s_1-1;t++)
					{
						if(c_k[t]==j)
						{
							bl=false;
						}
							
					}
				}
			}
			if(bl)
				c_k[s_1]=j	;
		}
	}
	cout<<sum<<" "<<s_1<<endl;
	
		
}
void clear()
{
	sum=0;
	for(int i=1;i<=n;i++)
	{
		bj[i]=false;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);	
	cin>>t;
	bool b_k=true;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>n_c[i][0]>>n_c[i][1]>>n_c[i][2];
			if(n_c[i][2]!=0)
				b_k=false;
		}
		int min_p=100001;
		int min_p2;
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			if(p[i]<min_p)
			{
				min_p=p[i];
			}
		}
		if(b_k==true)
		{
			bool b_s=false;
			int maxn_1=-999999,maxn_2=0;
			for(int i=1;i<=n;i++)
			{
				if(n_c[i][1]>v)
				{
					sum++;
					if(n_c[i][0]>maxn_1&&n_c[i][0]>=min_p)
					{
						maxn_1=n_c[i][0];
						maxn_2=i;
						
						b_s=true;
					}
				}
			}
			if(b_s==true)
				s=1;
			else
			 s=0;
			cout<<sum<<" "<<s<<endl;
			sum=0;
			
		}
		else
		{
			sub(n,m,l,v);
		}
		clear();
	}
	return 0;
}

