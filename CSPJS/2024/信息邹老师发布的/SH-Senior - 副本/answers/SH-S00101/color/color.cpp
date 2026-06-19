#include <bits/stdc++.h>
using namespace std;
int T,n,a[100009],ans,pre[100009];
int work(int c){
	int ret=0;
	for (int i=1;i<=n;++i) pre[i]=((c|(1<<(i-1)))==c);
	for (int i=1;i<=n;++i){
		for (int j=i-1;j>0;--j){
			if (pre[i]==pre[j]&&a[i]==a[j]){
				ret+=a[i];
				break; 
			}
		}
	}
	return ret;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for (int q=1;q<=T;++q){
		cin>>n;ans=0;for (int i=1;i<=n;++i) cin>>a[i];
		for (int i=0;i<(1<<n)-1;++i) ans=max(ans,work(i));
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
