#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k,cnt=0;
	cin>>n,k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		int res=a[i];
		if(res==k && vis[i]==0){
			cnt++;
			vis[i]=1;
		}
		for(int j=i+1;j<n;j++){
			if(vis[j]==0){
				res^=a[j];
				if(res==k){
					cnt++;
					for(int g=i;g<=j;g++)
						vis[g]=1;
				}
			}else
				break;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
