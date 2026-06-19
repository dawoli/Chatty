#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
multiset<int> s;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		s.insert(arr[i]);
	}
	sort(arr+1,arr+1+n);
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		auto it=s.upper_bound(arr[i]);
		if(it==s.end()) break;
		cnt--;
		s.erase(it);
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
