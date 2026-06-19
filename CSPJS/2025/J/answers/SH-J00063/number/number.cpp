#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> s;
int ans,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		s.push(a[i]);
	}
	while(1)
	{
		ans++;
		if(a[1]==s.top())
		{
			break;
		}
		s.pop();
	}
	if((ans/n+1)%2==1)
	{
		cout<<ans%n<<" "<<ans/n+1;
	}
	else if((ans/n+1)%2==0)
	{
		cout<<n-ans%n+1<<" "<<ans/n+1;
	}
	return 0;
}
