#include<bits/stdc++.h>
using namespace std;

int n, m;
int score[205];
int thisScore;
int t;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>score[i];
	thisScore = score[0];
	sort(score,score+n*m,greater<int>());
	for(int i=0;i<n*m;i++)
	{
		if(score[i]==thisScore)
		{
			t=i+1;
			if(t%n==0)
			{
				cout<<t/n<<" ";
				if(t/n%2==1) cout<<n;
				else cout<<1;
			}
			else
			{
				cout<<t/n+1<<" ";
				if((t/n+1)%2==1) cout<<(t-(t/n)*n);
				else cout<<(n-(t-(t/n)*n)+1);
			}
			return 0;
		}
	}
	return 0;
}
