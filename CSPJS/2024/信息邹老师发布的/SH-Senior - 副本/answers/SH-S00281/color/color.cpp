#include<bits/stdc++.h>
using namespace std;
int T,a[100001],n;
int b[100001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	int ans;
	int maxn;
	while(T--){
		ans=0;
		maxn=INT_MIN;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<pow(2,n);i++){
			if(i){
				b[0]++;
				for(int j=0;j<n;j++){
					if(b[j]==2){
						b[j+1]++;
					}
				}
			}
			ans=0;
			for(int j=0;j<n;j++){
				for(int k=j-1;k>=0;k--){
					if(b[j]==b[k]&&a[j]==a[k]){
						ans+=a[j];
					}
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
