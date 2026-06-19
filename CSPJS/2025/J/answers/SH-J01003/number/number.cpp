#include<bits/stdc++.h>
using namespace std;
char s[1000000];
char a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0,i;
	for(i=0;;i++)
	{
		cin>>s[i];
		if(('a'<=s[i]&&s[i]<='z')||('0'<=s[i]&&s[i]<='9'))
		{
			if('0'<=s[i]&&s[i]<='9')
			{
				a[j]=s[i];
				j++;
			}	
		}
		else break;
	}
    if(j==1) cout<<a[0]<<endl;
	else 
	{
		sort(a+0,a+j);
	    j--;
		for(i=j;i>=0;i--) cout<<a[i];
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
