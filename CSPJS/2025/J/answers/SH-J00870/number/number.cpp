#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010];
	int a[1000010];
	cin>>s;
	int ls=strlen(s);
	int j=0;
	for(int i=0;i<ls;i++)
		if('0'<=s[i]&&s[i]<='9')
			a[j++]=s[i]-'0';
	sort(a,a+j);
	bool flag=0;
	for(int i=j-1;i>=0;i--){
		if(flag==0&&a[i]!=0)
			flag=1;	
		if(flag)
			cout<<a[i];
	}
	if(!flag)
		cout<<0;
	return 0;
}

