#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int max_val,max_ind;
int min_val,min_ind;
int temp;
int a[100000][4];
int d[4][2];


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int cnt=0;cnt<t;cnt++)
	{
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			max_val=-1;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>max_val)
				{
					max_val=a[i][j];
					max_ind=j;
				}
			}
			a[i][0]=max_ind;
			d[max_ind][0]+=max_val;
			if(d[max_ind][1]<n/2)
			{
				d[max_ind][1]++;
			}
			else
			{
				min_val=max_val;
				min_ind=i;
				for(int j=0;j<=i;j++)
				{
					if(a[j][0]==max_ind)
					{
						switch(max_ind)
						{
							case 1:
								temp=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);
								break;
							case 2:
								temp=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
								break;
							case 3:
								temp=min(a[j][3]-a[j][1],a[j][3]-a[j][2]);
								break;
						}
						if(temp<min_val)
						{
							min_ind=j;
							min_val=temp;
						}
					}
				}
				d[max_ind][0]-=a[min_ind][max_ind];
				switch(max_ind)
				{
					case 1:
						if(a[min_ind][1]-a[min_ind][2]<=a[min_ind][1]-a[min_ind][3])
						{
							a[min_ind][0]=2;
							d[2][0]+=a[min_ind][2];
							d[2][1]++;
						}
						else
						{
							a[min_ind][0]=3;
							d[3][0]+=a[min_ind][3];
							d[3][1]++;
						}
						break;
					case 2:
						if(a[min_ind][2]-a[min_ind][1]<=a[min_ind][2]-a[min_ind][3])
						{
							a[min_ind][0]=1;
							d[1][0]+=a[min_ind][1];
							d[1][1]++;
						}
						else
						{
							a[min_ind][0]=3;
							d[3][0]+=a[min_ind][3];
							d[3][1]++;
						}
						break;
					case 3:
						if(a[min_ind][3]-a[min_ind][1]<=a[min_ind][3]-a[min_ind][2])
						{
							a[min_ind][0]=1;
							d[1][0]+=a[min_ind][1];
							d[1][1]++;
						}
						else
						{
							a[min_ind][0]=2;
							d[2][0]+=a[min_ind][2];
							d[2][1]++;
						}
						break;
				}
			}
		}
		ans=d[1][0]+d[2][0]+d[3][0];
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
