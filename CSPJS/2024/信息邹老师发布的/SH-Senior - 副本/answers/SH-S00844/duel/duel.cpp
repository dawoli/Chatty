#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int n,r[N],eat,cnt;
bool vis[N];
int lower(int x,int y ,int t)
{
	int left = x;
	int right=  y;
	int ans = 0;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(r[mid] < t)
		{
			left = mid+1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	
	return ans;
}

int main()
{
	freopen("duel.in" , "r" ,stdin);
	freopen("duel.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> r[i];
	
	sort(r+1 , r+1+n);
	eat = 1;
	while(eat <= n)
	{
		int pos = upper_bound(r+1 , r+1+n , r[eat]) - r;
		while(vis[pos]!=0 && pos <= n) pos++;
		
		if(pos > n) break;
		cnt++;
		eat++;
		vis[pos] = 1;
		
	}
	
	cout << n - cnt << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
