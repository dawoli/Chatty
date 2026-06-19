#include<bits/stdc++.h>
using namespace std;
int n;
const int N=55;
string s[N];
int cnt;
char a[5]={'D','C','H','S'};
char b[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	if(n==1){
		string str;cin>>str;
		bool flag1=0,flag2=0;
		for(int i=0;i<4;i++)if(str[0]==a[i])flag1=1;
		for(int i=0;i<13;i++)if(str[1]==b[i])flag2=1;
		if(flag1&&flag2)cnt++;
		cout<<52-cnt;
		return 0;
	} 
	string str;cin>>str;
	bool flag1=0,flag2=0;
	for(int j=0;j<4;j++)if(str[0]==a[j])flag1=1;
	for(int j=0;j<13;j++)if(str[1]==b[j])flag2=1;
	if(flag1&&flag2)cnt++,s[cnt]=str;
	for(int i=2;i<=n;i++){
		string str;cin>>str;
		bool flag1=0,flag2=0;
		for(int j=0;j<4;j++)if(str[0]==a[j])flag1=1;
		for(int j=0;j<13;j++)if(str[1]==b[j])flag2=1;
		if(!flag1||!flag2)continue;
		bool flag=0;
		for(int j=1;j<=cnt;j++){
			if(str==s[j]){flag=1;continue;}
		}
		if(!flag){
			cnt++;
			s[cnt]=str;
		}
	}
	int ans=52-cnt;
	cout<<ans;
	return 0;
}

