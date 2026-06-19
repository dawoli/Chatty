#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005];
struct node
{
	int s;int num;
};
vector<node> r;

bool cmp(node a,node b)
{
	return a.s <= b.s;		
}

int pro(int m,int n) {
	//if(m + n == )
	if(m == 1) return a[n];
	int res = a[n];
	for(int i = n+1; i <= n + m-1; i++) {
		res = (int)(res^a[i]);
	}
	return res;

}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i =1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i + j >= n+1) 
			{
				continue;
			}
			else {
				if(pro(i,j) == k)
				{
					r.push_back({i,j});
					//cout << i << " " << j << endl;
				} 
			}
		}
	}
//	for(int i =1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	//find
	
	sort(r.begin(),r.end(),cmp);
	
	dp[0] = 1;//cout << r.size();
	for(int i = 1;i < r.size();i++)
	{
		dp[i] = 1;
		for(int j = 1;j <= i;j++)
		{
			int aim = r[i-1].s + r[i-1].num-1;
			if(aim < r[i].s)
			{
				dp[i] = max(dp[i-1] + 1,dp[i]);
			}
			//cout << aim << " " << dp[i] << " " << i << endl;
			
			
		}	
		//cout  << endl;	
	}	
	cout << dp[r.size()-1] << endl;
	fclose(stdin);
	fclose(stdout);

	return 0;

}
