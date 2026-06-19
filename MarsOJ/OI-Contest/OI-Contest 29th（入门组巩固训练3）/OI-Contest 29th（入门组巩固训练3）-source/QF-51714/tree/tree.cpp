#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("tree.in",r,stdin);
	//freopen("tree.out",w,stdout);
	int n,cnt=0;
	cin>>n;
	string a,b;
	cin>>a>>b;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i]==b[j]&&a[i+1]==b[j-1])
			{
				cnt++;
			}
		}
	}
	int n_cnt=(1<<cnt),ans=0;
	while(n_cnt!=1){
		ans++;
		n_cnt/=2;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		cout<<rand()%n+1<<" ";
	}
	return 0;
}
