#include<bits/stdc++.h>
using namespace std;
int i,j,n;
char s[60][5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int nu=0;
	int b;
	cin>>n;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++)
	{
		b=0;
		for(j=i-1;j>=1;j--)
		{
			if(s[i][0]==s[j][0]&&s[i][1]==s[j][1]) b=1;
		}
		if(b==0) nu++;
	}
	nu=52-nu;
	cout<<nu<<endl;
	return 0;
}
