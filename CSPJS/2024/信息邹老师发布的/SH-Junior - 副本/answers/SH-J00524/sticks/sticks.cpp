#include<bits/stdc++.h>
using namespace std;
int T,n,v[20],dp[100010],s,anss;
char a[100010],ans[100010];
void solve(int x,char awa){
	s=1;
	a[1]=awa;
	if(x<0)
		return ;
	while(x){
		if(!dp[x])
			return ;
		if(x-7>=0&&dp[x-7])
			s++,a[s]='8',x-=7;
		else if(x-6>=0&&dp[x-6])
			s++,a[s]='0',x-=6;
		else if(x-5>=0&&dp[x-5])
			s++,a[s]='2',x-=5;
		else if(x-3>=0&&dp[x-3])
			s++,a[s]='7',x-=3;
		else if(x-2>=0&&dp[x-2])
			s++,a[s]='1',x-=2;
	}
	if(anss==0){
		anss=s;
		for(int i=1;i<=s;i++)
			ans[i]=a[i];
	}
	else{
		if(anss<s)
			return ;
		else if(anss==s){
			for(int i=1;i<=s;i++){
				if(ans[i]>a[i]){
					for(int j=1;j<=s;j++)
						ans[j]=a[j];
					return ;
				}
				if(ans[i]<a[i])
					return ;
			}
		}
		else{
			anss=s;
			for(int i=1;i<=s;i++)
				ans[i]=a[i];
		}
	}
}
void work(){
	anss=0;
	cin>>n;
	for(int i=1;i<=9;i++)
		solve(n-v[i],char(i+'0'));
	if(anss==0)
		cout<<-1<<"\n";
	else{
		sort(ans+2,ans+anss+1);
		for(int i=1;i<=anss;i++)
			cout<<ans[i];
		cout<<"\n";
	}
		
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	v[0]=6,v[1]=2,v[2]=5,v[3]=5,v[4]=4,v[5]=5,v[6]=6,v[7]=3,v[8]=7,v[9]=6;
	dp[0]=1;
	for(int i=1;i<=100000;i++){
		for(int j=0;j<=9;j++){
			if(i-v[j]<0)
				continue;
			if(i-v[j]>=0)
				dp[i]=max(dp[i],dp[i-v[j]]);
		}
	}
	cin>>T;
	while(T--)
		work();
}
