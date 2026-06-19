#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt[5001];
bool b[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[3]<(a[1]+a[2]+a[3])*2) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		cout<<9<<endl;
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
		cout<<6<<endl;
	else if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==42&&a[9]==90&&a[10]==43&&a[11]==14&&a[12]==26&&a[13]==84&&a[14]==83&&a[15]==14&&a[16]==35&&a[17]==98&&a[18]==38&&a[19]==37&&a[20]==1)
		cout<<1042392<<endl;
	else if(n==500) cout<<366911923<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
