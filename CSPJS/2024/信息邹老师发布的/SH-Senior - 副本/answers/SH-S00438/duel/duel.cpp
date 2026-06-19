#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,r[N],q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>r[i];
	sort(r+1,r+1+n);
	for(int i=1,j=1;i<=n;++i)
		if(r[i]>r[j]) ++q,++j;
	cout<<n-q;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
