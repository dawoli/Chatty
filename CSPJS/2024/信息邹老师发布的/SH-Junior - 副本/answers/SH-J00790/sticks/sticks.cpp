#include <iostream>
#include <fstream>
using namespace std;
const int sm[]={6,2,5,5,4,5,6,3,7,6};
int n,t;
//struct big_num
//{
//	short val[100005];
//	int length=0;
//	big_num(int iv)
//	{
//		if(iv==0){length=1;return;}
//		int pt=0;
//		while(iv)
//		{
//			val[pt++]=iv%10;
//			iv/=10;
//		}
//		length=pt;
//	}
//	void operator+=(it a)
//	{
//		big_num aa=a,ans=0;
//		ans.length=max(aa.length,length);
//		for(int i = 0;i < ans.length;i ++)
//		ans.val[i]=aa.val[i]+val[i];
//		for(int i = 0;i < ans.length-1;i ++)
//		if(ans.val[i]>9)
//		ans.val[i]-=10,ans.val[i+1]++;
//		if(ans.val[ans.length-1]>9)
//		ans.val[ans.length-1]-=10,
//		ans.val[ans.length]++,ans.length++;
//		return ans;
//	}
//	void operator+=(int a)
//	{
//		big_num ans=(big_num)this+(big_num)a;
//		length=ans.length;
//		for(int i = 0;i < length;i ++)
//		val[i]=ans.val[i];
//	}
//	void output()
//	{
//		for(int i = 0;i < length;i ++)
//		cout << val[i];
//	}
//};
long long get_num(int num)
{
	if(num==0) return 6;
	long long ans=0;
	while(num)
	{
		ans+=sm[num%10];
		num/=10;
	}
	return ans;
}
int solve(int n)
{
	if(n<2) return -1;
	for(int i = 1;i <= 100000;i ++)
	if(get_num(i)==n) return i;
	return -1;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
