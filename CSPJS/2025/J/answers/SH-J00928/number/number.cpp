#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;

char c[N];

int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int len=strlen(c);
	int k=1;
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[k]=c[i]-'0';
			k++;
		}
	}
	k--;
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
}
