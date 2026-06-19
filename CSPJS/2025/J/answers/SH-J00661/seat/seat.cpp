#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,ri;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==r)
		{
			ri=n*m-i+1;
			break;
		}
	}
	int l=(ri-1)/n+1;
	if(l%2==0)
	{
		cout<<l<<" "<<n-ri%n+1;
	}
	else
	{
		if(ri%n!=0)
		cout<<l<<" "<<ri%n;
		else cout<<l<<" "<<n;
	}
	return 0;
}
/*猴哥，我这次救了不少人呢。
	刚才的几分钟里，我已经实现了我所有的愿望。
	小南，替我，回家。我不想一个人回家。
	我不想在我最后的时间里，看着我的爱人毫无意义的拼凑着我的尸体。
	就让这世界最后一次记住我们的名字吧，在这夜幕之下。
	此剑，别人间。
	--《我在精神病院学斩神》*/ 
