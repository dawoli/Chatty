#include<bits/stdc++.h>
using namespace std;

int N;
long long k;
long long a[1005];
int rec[1005][1005];
long long res[1005][1005];
int r;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>N>>k;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++)
	{
		rec[i][i]=int(a[i]==k);
		res[i][i]=a[i];
	}
	for(int len=2;len<=N;len++)
	{
		for(int l=0;l<=N-len;l++)
		{
			r=l+len-1;
			res[l][r]=res[l][r-1]^a[r];
			rec[l][r]=int(res[l][r]==k);
			for(int k=0;k<r;k++) rec[l][r]=max(rec[l][r], rec[l][k]+rec[k+1][r]);
		}
	}
	cout<<rec[0][N-1];
	return 0;
}
