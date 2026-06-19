#include<bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
struct edge{
	int w;
	int num;
};
bool cmp(edge first,edge next)
{
	if(first.w>next.w)
	{
		return true;
	}
	return false;
}
int t,n,a[100005][5],sum[5];
edge minnc[100005];
long long ans;
int main()
{
	fin>>t;
	while(t--)
	{
		fin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			fin>>a[i][1]>>a[i][2]>>a[i][3];
			int aa[4];
			aa[1]=a[i][1];
			aa[2]=a[i][2];
			aa[3]=a[i][3];
			sort(aa+1,aa+4);
			minnc[i].w=aa[3]-aa[2];
			minnc[i].num=i;
		}
		sort(minnc+1,minnc+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int j=minnc[i].num,maxx=0,maxi;
			for(int k=1;k<=3;k++)
			{
				if(maxx<=a[j][k] and sum[k]<n/2)
				{
					maxx=a[j][k];
					maxi=k;
				}
			}
			sum[maxi]++;
			ans+=a[j][maxi];
		}
		fout<<ans<<endl;
	}
}

//#include<bits/stdc++.h>
//using namespace std;
//ifstream fin("club.in");
//ofstream fout("club.out");
//int tt,n,a[100005][5],maxx[100005],summ[5],cha[100005][5],t1[50005],t2[50005],t3[50005],t4[50005],lian[50005][50005],num[50005],r[50005],minn1,minn2,minn3,minn4,numm[5][100005];
//long long ans;
//int main()
//{
//	cin>>tt;
//	while(tt>0)
//	{
//		tt--;
//		minn1=0;
//		minn2=0;
//		minn3=0;
//		minn4=0;
//		ans=0;
//		summ[1]=0;
//		summ[2]=0;
//		summ[3]=0;
//		for(int i=0;i<=50000;i++)
//		{
//			t1[i]=0;
//			t2[i]=0;
//			t3[i]=0;
//			t4[i]=0;
//			num[i]=0;
//		}
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			int maxxx=0,maxi;
//			for(int j=1;j<=3;j++)
//			{
//				cin>>a[i][j];
//				if(maxxx<a[i][j])
//				{
//					maxxx=a[i][j];
//					maxi=j;
//				}
//			}
//			maxx[i]=maxi;
//			summ[maxi]++;
//			numm[maxi][summ[maxi]]=i;
//			ans+=maxxx;
//		}
//		if(summ[1]<=n/2 and summ[2]<=n/2 and summ[3]<=n/2)
//		{
//			cout<<ans<<endl;
//		}
//		else if(summ[1]>n/2)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				cha[i][1]=a[i][2]-a[i][1];
//				cha[i][2]=a[i][3]-a[i][2];
//				cha[i][3]=a[i][1]-a[i][3];
//			}
//			for(int i=1;i<=summ[1];i++)
//			{
//				t1[-cha[numm[1][i]][1]]++; 
//				t2[cha[numm[1][i]][3]]++; 
//				num[-cha[numm[1][i]][1]]++;
//				lian[-cha[numm[1][i]][1]][num[-cha[numm[1][i]][1]]]=cha[numm[1][i]][3];
//				num[cha[numm[1][i]][3]]++;
//				lian[cha[numm[1][i]][3]][num[cha[numm[1][i]][3]]]=-cha[numm[1][i]][1];
//			}
//			for(int i=1;i<=summ[2];i++)
//			{
//				t3[-cha[numm[2][i]][2]]++;
//			}
//			for(int i=1;i<=summ[3];i++)
//			{
//				t4[cha[numm[3][i]][2]]++;
//			}
//			for(int i=0;i<=50000;i++)
//			{
//				sort(lian[i],lian[i]+num[i]);
//				r[i]=num[i];
//			}
//			while(summ[1]>n/2)
//			{
//				while(t1[minn1]<=0)
//				{
//					minn1++;
//				}
//				while(t2[minn2]<=0)
//				{
//					minn2++;
//				}
//				while(t3[minn3]<=0)
//				{
//					minn3++;
//				}
//				while(t4[minn4]<=0)
//				{
//					minn4++;
//				}
//				if(summ[2]<n/2 and summ[3]<n/2)
//				{
//					if(minn1>=minn2)
//					{
//						ans-=minn1;
//						summ[2]+=1;
//						summ[1]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=minn2;
//						summ[3]+=1;
//						summ[1]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//				}
//				else if(summ[2]==n/2)
//				{
//					if(minn2<=minn1+minn3)
//					{
//						ans-=minn2;
//						summ[3]+=1;
//						summ[1]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//					else
//					{
//						ans-=(minn1+minn3); 
//						summ[1]-=1;
//						summ[3]+=1;
//						t1[minn1]-=1;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//						t3[minn3]-=1;
//					}
//				}
//				else
//				{
//					if(minn1<=minn2+minn4)
//					{
//						ans-=minn1;
//						summ[2]+=1;
//						summ[1]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=(minn2+minn2); 
//						summ[1]-=1;
//						summ[2]+=1;
//						t2[minn2]-=1;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//						t4[minn4]-=1;
//					}
//				}
//			}
//			cout<<ans<<endl;
//		}
//		else if(summ[2]>n/2)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				cha[i][1]=a[i][3]-a[i][2];
//				cha[i][2]=a[i][1]-a[i][3];
//				cha[i][3]=a[i][2]-a[i][1];
//			}
//			for(int i=1;i<=summ[2];i++)
//			{
//				t1[-cha[numm[2][i]][1]]++; 
//				t2[cha[numm[2][i]][3]]++; 
//				num[-cha[numm[2][i]][1]]++;
//				lian[-cha[numm[2][i]][1]][num[-cha[numm[2][i]][1]]]=cha[numm[2][i]][3];
//				num[cha[numm[2][i]][3]]++;
//				lian[cha[numm[2][i]][3]][num[cha[numm[2][i]][3]]]=-cha[numm[2][i]][1];
//			}
//			for(int i=1;i<=summ[3];i++)
//			{
//				t3[-cha[i][2]]++;
//			}
//			for(int i=1;i<=summ[1];i++)
//			{
//				t4[cha[numm[1][i]][2]]++;
//			}
//			for(int i=0;i<=50000;i++)
//			{
//				sort(lian[i],lian[i]+num[i]);
//				r[i]=num[i];
//			}
//			while(summ[1]>n/2)
//			{
//				while(t1[minn1]<=0)
//				{
//					minn1++;
//				}
//				while(t2[minn2]<=0)
//				{
//					minn2++;
//				}
//				while(t3[minn3]<=0)
//				{
//					minn3++;
//				}
//				while(t4[minn4]<=0)
//				{
//					minn4++;
//				}
//				if(summ[3]<n/2 and summ[1]<n/2)
//				{
//					if(minn1>=minn2)
//					{
//						ans-=minn1;
//						summ[3]+=1;
//						summ[2]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=minn2;
//						summ[1]+=1;
//						summ[2]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//				}
//				else if(summ[2]==n/2)
//				{
//					if(minn2<=minn1+minn3)
//					{
//						ans-=minn2;
//						summ[2]+=1;
//						summ[3]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//					else
//					{
//						ans-=(minn1+minn3); 
//						summ[2]-=1;
//						summ[1]+=1;
//						t1[minn1]-=1;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//						t3[minn3]-=1;
//					}
//				}
//				else
//				{
//					if(minn1<=minn2+minn4)
//					{
//						ans-=minn1;
//						summ[3]+=1;
//						summ[2]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=(minn2+minn2); 
//						summ[2]-=1;
//						summ[3]+=1;
//						t2[minn2]-=1;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//						t4[minn4]-=1;
//					}
//				}
//			}
//			cout<<ans<<endl;
//		}
//		else
//		{
//			for(int i=1;i<=n;i++)
//			{
//				cha[i][2]=a[i][3]-a[i][2];
//				cha[i][3]=a[i][1]-a[i][3];
//				cha[i][1]=a[i][2]-a[i][1];
//			}
//			for(int i=1;i<=summ[3];i++)
//			{
//				t1[-cha[numm[3][i]][1]]++; 
//				t2[cha[numm[3][i]][3]]++; 
//				num[-cha[numm[3][i]][1]]++;
//				lian[-cha[numm[3][i]][1]][num[-cha[numm[3][i]][1]]]=cha[numm[3][i]][3];
//				num[cha[numm[3][i]][3]]++;
//				lian[cha[numm[3][i]][3]][num[cha[numm[3][i]][3]]]=-cha[numm[3][i]][1];
//			}
//			for(int i=1;i<=summ[1];i++)
//			{
//				t3[-cha[numm[1][i]][2]]++;
//			}
//			for(int i=1;i<=summ[2];i++)
//			{
//				t4[cha[numm[2][i]][2]]++;
//			}
//			for(int i=0;i<=50000;i++)
//			{
//				sort(lian[i],lian[i]+num[i]);
//				r[i]=num[i];
//			}
//			while(summ[3]>n/2)
//			{
//				while(t1[minn1]<=0)
//				{
//					minn1++;
//				}
//				while(t2[minn2]<=0)
//				{
//					minn2++;
//				}
//				while(t3[minn3]<=0)
//				{
//					minn3++;
//				}
//				while(t4[minn4]<=0)
//				{
//					minn4++;
//				}
//				if(summ[1]<n/2 and summ[2]<n/2)
//				{
//					if(minn1>=minn2)
//					{
//						ans-=minn1;
//						summ[1]+=1;
//						summ[3]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=minn2;
//						summ[2]+=1;
//						summ[3]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//				}
//				else if(summ[2]==n/2)
//				{
//					if(minn2<=minn1+minn3)
//					{
//						ans-=minn2;
//						summ[3]+=1;
//						summ[1]-=1;
//						t2[minn2]--;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//					}
//					else
//					{
//						ans-=(minn1+minn3); 
//						summ[3]-=1;
//						summ[2]+=1;
//						t1[minn1]-=1;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//						t3[minn3]-=1;
//					}
//				}
//				else
//				{
//					if(minn1<=minn2+minn4)
//					{
//						ans-=minn1;
//						summ[1]+=1;
//						summ[3]-=1;
//						t1[minn1]--;
//						t2[lian[minn1][r[minn1]]]--;
//						r[minn1]--;
//					}
//					else
//					{
//						ans-=(minn2+minn2); 
//						summ[3]-=1;
//						summ[1]+=1;
//						t2[minn2]-=1;
//						t1[lian[minn2][r[minn2]]]--;
//						r[minn2]--;
//						t4[minn4]-=1;
//					}
//				}
//			}
//			cout<<ans<<endl;
//		}
//	}
// } 
