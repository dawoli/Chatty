#include<iostream>
#include<algorithm>
int a[1000001];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	std::cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')a[j++]=s[i]-'0';
	std::sort(a,a+j,cmp);
	for(int i=0;i<j;i++)std::cout<<a[i];
	return 0;
}
