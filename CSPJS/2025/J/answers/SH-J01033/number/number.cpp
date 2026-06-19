#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	char tmp;
	while(scanf("%c",&a[++n])&&a[n]!='\n');
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
		{
			if(a[j]>'A'||a[j+1]<='9'&&a[j+1]>a[j]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	for(int i=1;i<=n;i++) if(a[i]<='9'&&a[i]>='0') cout<<a[i];
	return 0;
}
