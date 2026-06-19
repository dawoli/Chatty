#include<bits/stdc++.h>
using namespace std;
string s;
int t,a=1;
char ans[1000005];
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	
	cin>>s;
	t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]>='0' and '9'>=s[i])
		{
			ans[a++]=s[i];
		}
	}

	sort(ans+1,ans+a);
	for(int i=a-1;i>0;i--)
	{
		printf("%c",ans[i]);
	}
	return 0;
}
