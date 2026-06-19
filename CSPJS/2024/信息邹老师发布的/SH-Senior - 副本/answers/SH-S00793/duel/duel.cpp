#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	int d[100009]; 
	cin>>n;
	int ans=n;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	sort(d,d+n);
	int l=0,r=1;
	for( ;r<n;r++)
	{
		if(d[l]<d[r])
		{
			l++;
			ans--;
		}
	}
	cout<<ans; 
	return 0;
}
