#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","w",stdin);
	freopen("duel.out","r",stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int j=0;j<n;j++){
	for(int i=0;i<n-1;i++)    
	{
		if (a[i]>a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	}
	int ans = 0;
	for(int i = 0;i<n-1;i++){
	       for(int j=i+1;j<=n;j++)
		   {
		   	   if(a[i]<a[j]&&a[i]!=0)
		   	   {       
		   	     a[j] = 0;
		   	   	 continue;
			   }
		   }
	}
	
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			ans++;
		}
    }
	cout << ans;
	return 0;
}
