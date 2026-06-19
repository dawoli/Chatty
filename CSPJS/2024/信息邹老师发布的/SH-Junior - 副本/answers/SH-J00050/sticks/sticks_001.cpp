#include<bits/stdc++.h>
using namespace std;
const int N=100020;
class xunhuan
{
public:
	string sto[100];
	string& operator[](int in){return sto[in%100];}
}dp;
bool ved[N];
int cost[10]={6,2,5,5,4,5,6,3,7,6};
string hmin(const string& a,const string& b)
{
	int alen=a.length();
	int blen=b.length();
	if(alen!=blen)return alen<blen?a:b;
	else return a<b?a:b;
}
pair<int,int>sto[N];
string ans[N];
int main()
{
	freopen("sticks.in","r",stdin); 
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int n;
		scanf("%d",&n);
		sto[i]=make_pair(n,i);		
	} 
	sort(sto+1,sto+T+1);
	int nt=1;
	dp[0]="";
	ved[0]=1;
	for(int i=0;i<=N-10;i++)
	{
		if(nt<=T && sto[nt].first==i)
		{
			ans[sto[nt].second]=(ved[i]==0?"-1":dp[i]);
			nt++;
		}
		if(ved[i]==0)continue;
		for(int j=0;j<=9;j++)
		{
			if(i==0 && j==0)continue;
			if(ved[i+cost[j]]==0)
			{
				dp[i+cost[j]]=dp[i]+char('0'+j);
				ved[i+cost[j]]=1;
			}
			else dp[i+cost[j]]=hmin(dp[i]+char('0'+j),dp[i+cost[j]]);
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
} 
