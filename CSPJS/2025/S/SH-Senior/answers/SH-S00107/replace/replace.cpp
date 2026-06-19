#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,sho[80011][2];
	cin>>n>>q;
	string rep[80011][2];
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		int j=0,k=a.size()-1;
		while(a[j]==b[j])
			j++;
		while(a[k]==b[k])
			k--;
		sho[i][0]=j;
		sho[i][1]=a.size()-k-1;
		for(j;j<=k;j++)
		{
			rep[i][0]=rep[i][0]+a[j];
			rep[i][1]=rep[i][1]+b[j];
		}
	}
	for(int l=0;l<q;l++)
	{
		string s1,s2,v1,v2;
		cin>>s1;
		cin>>s2;
		int len=s1.size(),ans=0;
		int i=0,j=len-1;
		while(s1[i]==s2[i]) i++;
		while(s1[j]==s2[j]) j--;
		for(int k=i;k<=j;k++)
		{
			v1=v1+s1[k];
			v2=v2+s2[k];
		}
		for(int k=0;k<n;k++)
		{
			if(rep[k][0]==v1 && rep[k][1]==v2 && sho[k][0]<=i && sho[k][1]<=len-j-1)
				ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
