#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct info{
	long long damage;//blood = damage
	bool killed;
}a[100010];
bool cmp(info a1,info a2){
	return a1.damage<a2.damage;
}
int main()
{
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i].damage;
	a[i].killed=false; 
}//read
sort(a+1,a+n+1,cmp);
int temp=1;//the smallest of damage 
for(int i=2;i<=n;i++)
{
	if(i!=temp)//can not attack itself
	if(a[i].damage>a[temp].damage)
	{
		a[i].killed=true;
		temp+=1;
	}
}//choose
for(int i=1;i<=n;i++)
{
	if(a[i].killed==false)
	{
		ans+=1;
	}
}//write
cout<<ans;


return 0;
}



