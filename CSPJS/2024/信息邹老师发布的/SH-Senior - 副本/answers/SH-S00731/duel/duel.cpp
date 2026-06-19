#include<bits/stdc++.h>
using namespace std;
int n,a,c[100003]={0},k=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		c[a]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(k<c[i])
		{
			k=c[i];
		}
	}
	cout<<k<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
