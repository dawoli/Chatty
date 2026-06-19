#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("duel.in" , "r" , stdin);
freopen("duel.out" , "w" , stdout);
int i,j,n,a;
int r[100001];
cin>>n;
cin>>r[n];
for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
{
{
    if(i=j)
    a=a;
    else
	if (r[i]<=r[j])
	a=a+1;
	i++;
    if(r[i]>r[j])
	a=a+1;
	i++;
	j++;
}
}
	cout<<n-a-1<<endl;
	return 0; 
}
