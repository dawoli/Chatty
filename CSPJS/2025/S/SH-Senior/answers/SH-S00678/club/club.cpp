#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
struct node
{
	int x,k;
};
bool cmp(node x,node y)
{
	return x.k>y.k;
}
node a[100010][5];//志愿 
int m[5][100010];//调剂处罚 
void solve()
{
	m[1][0]=0;
	m[2][0]=0;
	m[3][0]=0;
	int n;
	cin>>n;
	int  ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i][1].x=1;
		a[i][2].x=2;
		a[i][3].x=3;
		cin>>a[i][1].k>>a[i][2].k>>a[i][3].k;
		sort(a[i]+1,a[i]+4,cmp);
		m[a[i][1].x][++m[a[i][1].x][0]]=a[i][1].k-a[i][2].k;//记录调剂惩罚
		ans+=a[i][1].k;
	}
	node temp[5];
	for(int i=1;i<=3;i++)
	{
		temp[i].x=i;
		temp[i].k=m[i][0];
	}
	sort(temp+1,temp+4,cmp);//选定热门部门
	int num=temp[1].k,id=temp[1].x;
	if(num<=n/2)
	{
		cout<<ans<<endl;
	 }
	 else
	 {
	 	sort(m[id]+1,m[id]+num+1);
	 	for(int i=1;i<=num-n/2;i++)
	 	{
	 		ans-=m[id][i];
		 }
		 cout<<ans<<endl;
	 }
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
 } 
