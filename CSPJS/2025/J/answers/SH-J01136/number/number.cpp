#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[9];
long long ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){

		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		//if(a[i]==0)continue;
		while(a[i]!=0)
		{
			//ans=ans*10+i;
			a[i]--;
			cout<<i;
		}
	}
	//cout<<ans<<endl;
	return 0;
}
