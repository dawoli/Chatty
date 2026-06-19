#include<bits/stdc++.h>
#define max my_max
#define min my_min
using namespace std;
int t,x;
template<typename T> T my_max(const T &A,const T&B)
{
	return B<A?A:B;
}
template<typename T> T my_min(const T &A,const T&B)
{
	return A<B?A:B;
}
struct node
{
	int x[4];
	int mx;//max
	int nx;//secondmax
	int mn;//min
}a[100005];
bool bigger(const node &a,const node &b)
{
	if(a.x[a.mx]==b.x[b.mx])
	{
		if(a.x[a.nx]==b.x[b.nx])return a.x[a.mn]>b.x[b.mn];
		return a.x[a.nx]>b.x[b.nx];
	}
	return a.x[a.mx]>b.x[b.mx];	

}
bool smaller(const node &a,const node &b)
{
	if(a.x[a.mx]==b.x[b.mx])
	{
		if(a.x[a.nx]==b.x[b.nx])return a.x[a.mn]<b.x[b.mn];
		return a.x[a.nx]<b.x[b.nx];
	}
	return a.x[a.mx]<b.x[b.mx];	

}
void solve()
{
	int ans1=0,ans2=0,hn=x/2;
	int cnt1[4]={0},cnt2[4]={0};
	for(int j=1;j<=x;j++)
	{
		node &i=a[j];
		int f,y;
		cin>>i.x[1]>>i.x[2]>>i.x[3];
		i.mx=max(max(i.x[1],i.x[2]),i.x[3]);
		if(i.x[1]==i.mx)i.mx=1;
		else if(i.x[2]==i.mx)i.mx=2;
		else i.mx=3;
		if(i.mx==1)f=2,y=3;
		else if(i.mx==2)f=1,y=3;
		else f=1,y=2;
		i.nx=max(i.x[f],i.x[y]);
		i.mn=min(i.x[f],i.x[y]);
		if(i.nx==i.x[f])i.nx=f,i.mn=y;
		else i.nx=y,i.mn=x;
	}
	sort(a+1,a+x+1,bigger);
	for(int j=1;j<=x;j++)
	{
		node &i=a[j];
		if(cnt1[i.mx]>=hn)
		{
			ans1+=i.x[i.nx];
			cnt1[i.nx]++;
		}
		else
		{
			ans1+=i.x[i.mx];
			cnt1[i.mx]++;
		}
	}
	sort(a+1,a+x+1,smaller);
	for(int j=1;j<=x;j++)
	{
		node &i=a[j];
		if(cnt2[i.mx]>=hn)
		{
			ans2+=i.x[i.nx];
			cnt2[i.nx]++;
		}
		else
		{
			ans2+=i.x[i.mx];
			cnt2[i.mx]++;
		}
	}		
	cout<<max(ans1,ans2)<<'\n';
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--)
	{
		cin>>x;
		solve();
	}
	cout<<endl;
	return 0;
}
