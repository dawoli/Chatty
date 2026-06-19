#include<bits/stdc++.h>
using namespace std;
int o[510000];
int vis[510000];
int sum[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,k,cnt,mn=1;
	cin>>a>>k;
	for(int i=1;i<=a;i++){
		cin>>o[i];
		sum[i]=sum[i-1]^o[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=mn;j<=i;j++){
			int t=sum[j-1]^sum[i];
			if(t==k){
				cnt++;
				mn=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
