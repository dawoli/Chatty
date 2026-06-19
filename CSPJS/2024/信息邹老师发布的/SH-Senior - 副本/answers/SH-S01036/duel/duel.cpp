#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int r[100000],f[100000],e[100000];
	int sum=0;
	memset(f,sizeof(f),0);
	memset(e,sizeof(e),1);
	int m,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(r[i]>r[j])
				swap(r[i],r[j]);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			if(r[i]<r[j] && f[j]==0){
				sum++;
				e[i]=0;
				f[j]=1;
				break;
			}
	}
	cout<<n-sum<<endl;
	return 0;
}
