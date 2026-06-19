#include<bits/stdc++.h>
using namespace std;
int n,ans,chong=0;
string p[10007];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int j=0;
	int k=n;
	for(int i=0;i<n;i++)
	{
		if(j<n){
			j++;
		}
		if(k>0){
			k--;
		}
		cin>>p[i]; 
		if(p[i]==p[j] or p[i]==p[k] or p[k]==p[j])
		{
			chong++;
		}
	}
	chong--;
	ans=52-(n-chong);
	cout<<ans;
	return 0;
}
