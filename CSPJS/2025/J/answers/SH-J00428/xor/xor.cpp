#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int a[1005];
int pos=1;
int ans=0;
struct node
{
	int start,end;
};node N[1000005];
bool cmp(node X,node Y)
{
	if(X.end!=Y.end)
		return X.end<Y.end;
		return X.start<Y.start;
}
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	int cnt;
	for(int i=1;i<=n;i++)
	{
		cnt=a[i];
		
				if(a[i]==k)
				{
					N[pos].start=i;
					N[pos].end=i;
					pos++;
					
				}
				continue;
			
		for(int j=i;j<=n;j++)
		{
			
			cnt^=a[k+1];	
			cout<<i<<' '<<j<<' '<<cnt<<endl;
			if(cnt==k)
			{
				N[pos].start=i;
				N[pos].end=j;
				cout<<N[pos].start<<' '<<N[pos].end<<endl;
				pos++;
			}
		}
	}
	
	sort(N+1,N+pos,cmp);
	int now=0;
	for(int i=1;i<=pos;i++)
	{
		if(N[i].start<now)continue;
		else 
		{
			ans++;
			now=N[i].end+1;	
			cout<<N[i].start<<' '<<N[i].end<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
