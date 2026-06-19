#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> s;
int ans,a[105],hang;
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
    int lie=ans/n+1;
    if(ans%n==0)
    {
    	lie--;
	}
	if(lie%2==1)
	{
		hang=ans%n;
		if(hang==0)
		{
			hang=n;
		}
		cout<<lie<<" "<<hang;
	}
	else if(lie%2==0)
	{
		cout<<lie<<" "<<(n-ans%n+1)%n;
	}
	return 0;
}
