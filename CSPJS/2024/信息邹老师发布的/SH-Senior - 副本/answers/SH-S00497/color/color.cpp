#include<bits/stdc++.h>
using namespace std;
long long a[200005],t,n,ans=0;
bool b[200005]={};
void abc(int red,int blue,int score,int round)
{
	if(round==n+1)
	{
		if(score>ans) ans=score;
		return;
	}
	if(a[round]==red||a[round]==blue) 
	{
		abc(red,blue,score+a[round],round+1);
		return;
	}
	else
	{
		abc(a[round],blue,score,round+1);
		abc(red,a[round],score,round+1);
		return;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	bool x=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(b[a[i]]) x=1;
			else b[a[i]]=1;
		}
		if(x)abc(a[1],0,0,2);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
