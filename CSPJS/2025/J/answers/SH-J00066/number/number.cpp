#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>;
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long num[100000];
	int k=0,c=0;
	string s;
	cin>>s;
	int l=s.length();
	for (int i=0;i<l;i++){
		if(s[i]=='0'){
			c++;
		}else if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6'|| s[i]=='7'|| s[i]=='8'|| s[i]=='9'){
			num[k]=s[i]-'0';
			k++;
		}else{
			num[k]=0;
			k++;
		}
	}
	sort(num,num+l);
	for (int i=0;i<=l;i++){
		if(num[l-i]==0)continue;
		cout<<num[l-i];
	}
	while(c--)cout<<0;
	return 0;
}
