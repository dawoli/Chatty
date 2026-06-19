#include <bits/stdc++.h>
using namespace std;

int n,m,r,cnt=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++)
	{
		int t;
		cin>>t;
		if(t>r)
		{
			cnt++;
		}
	}
	int ans=m-1;
	if((cnt+ans)/m%2==1) cout<<(cnt+ans)/m<<' '<<cnt-(cnt+ans)/m*m+m;
	else cout<<(cnt+ans)/m<<' '<<m+1-(cnt-(cnt+ans)/m*m+m);
	return 0;
} 
