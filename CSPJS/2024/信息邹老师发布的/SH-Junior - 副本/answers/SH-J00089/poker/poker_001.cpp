#include<bits/stdc++.h>
using namespace std;
int a[53],n,ans;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int cnt=0;
		if(s[0]=='D')cnt+=0;
		if(s[0]=='C')cnt+=13;
		if(s[0]=='H')cnt+=26;
		if(s[0]=='S')cnt+=39;
		
		if(s[1]>='2'&&s[1]<='9')cnt+=(s[1]-'0');
		if(s[1]=='A')cnt+=1;
		if(s[1]=='T')cnt+=10;
		if(s[1]=='J')cnt+=11;
		if(s[1]=='Q')cnt+=12;
		if(s[1]=='K')cnt+=13;
		
		a[cnt]=1;
	}for(int i=1;i<=52;i++){
		if(!a[i])ans++;
	}cout<<ans;
	return 0;
}
