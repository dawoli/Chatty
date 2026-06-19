#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;

const int N=1e5+10,MINN=-1e9;
int t,n,a[N][4];
int choice[N];
int have[4];
int ans;
int b[N];
bool a20,a30;

int findmax(int a,int b,int c)
{
	if(a>=b && a>=c)	return 1;
	if(b>=c)	return 2;
	return 3;
}

void A()
{
	for(int i=1;i<=n;i++)	b[i]=a[i][1];
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--)	ans+=b[i];
	cout << ans << endl;
	return;
}

signed main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);

	cin >> t;
	while(t--)
	{
		ans=0,a20=a30=true;
		have[1]=have[2]=have[3]=0;
		memset(choice,0,sizeof(choice));
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0)	a20=false;
			if(a[i][3] != 0)	a30=false;
		}
		if(a30 && a20)
		{
			A();
			continue;
		}
		
		for(int i=1;i<=n;i++)
		{
			int best=findmax(a[i][1],a[i][2],a[i][3]);
			if(have[best] < n/2)	have[best]++,choice[i]=best,ans+=a[i][best];
			else
			{
				int loc,tar,mg=MINN,delta;
				
				for(int c=1;c<=3;c++)//退而求其次 选择c
				{
					if(c == best)	continue;
					for(int j=1;j<=i;j++)//与谁交换 
					{
						if(choice[j] != best)	continue;
						delta=a[i][best]+a[j][c]-a[j][best];
						if(delta > mg)	loc=j,tar=c,mg=delta;
					}
				}
//				cout << "# " << loc << ' ' << tar << ' ' << mg << ' ' << endl;
				choice[i]=best,choice[loc]=tar;
				have[tar]++,ans+=mg;
			}
			
		}	
		cout << ans << endl;
	}
	return 0;
}

