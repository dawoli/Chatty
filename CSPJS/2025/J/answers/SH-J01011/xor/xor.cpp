#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N],ans,pre[N],low;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;low=i;
		}else{
			for(int j=low;j<=i-1;j++){
				if((pre[i]^pre[j])==k){
					ans++;low=i;break;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
