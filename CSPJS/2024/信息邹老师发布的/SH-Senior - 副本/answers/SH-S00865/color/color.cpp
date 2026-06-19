#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010];
bool s[100010];
int ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(a[j]==a[i] && s[i]==0){
					s[i]=1;
					ans+=a[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//0
