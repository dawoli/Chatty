#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,cnt=0;
long long a[100005][4],b[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>b[m])continue;
			if((a[i][2]*a[i][2]+2*a[i][3]*(b[m]-a[i][1]))>v*v) cnt++;
		}
		cout<<cnt<<" "<<m-1<<endl;
		cnt=0;
	}
	return 0;
}
