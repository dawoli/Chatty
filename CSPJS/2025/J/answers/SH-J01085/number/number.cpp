#include<bits/stdc++.h>
using namespace std;
string n;
long long cnt=0,a[1000010];
bool cmp(char a,char b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n.length();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[cnt]=n[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(long long i=0;i<cnt;i++) cout<<a[i];
	return 0;
 } 
