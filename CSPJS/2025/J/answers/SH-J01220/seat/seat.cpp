#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
struct stu
{
	int num;
	int score;
};
stu s[105];
bool cmp(stu x,stu y)
{
	return x.score<y.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].score;
		s[i].score=-s[i].score;
		s[i].num=i;
	}
	sort(s+1,s+m*n+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(s[i].num==1)
		{
			c=i;
			break;
		}
	}
	a=c/(2*n);
	a*=2;
	b=c%(2*n);
	if(b>n)
	{
		a+=2;
		b=2*n+1-b;
	}
	else if(b!=0) a++;
	else if(b==0) b=1;
	cout<<a<<" "<<b<<endl;
	return 0; 
}
