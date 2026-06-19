#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

