#include<bits/stdc++.h>
using namespace std;
int n,g[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[5005];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			for(int l=2;l<n;l++){
				if(g[i]+g[j]+g[l]>max(g[i],max(g[j],g[l]))) sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
