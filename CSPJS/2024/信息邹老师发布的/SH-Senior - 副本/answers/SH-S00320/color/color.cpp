#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],ans,c[N],cnt[N],num[100005],f[100005],m;//f[100005]
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		m=1;
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++){
			cin>>a[j];
			cnt[a[j]]++;
		}
		ans=0;
		for(int j=1;j<=n;j++){
			if(cnt[a[j]]>1){
				f[m]=a[j];
				num[m]=cnt[a[j]];
				m++;
			}
		}
		for(int j=1;j<=n;j++){
			if(num[m]%2==0){
				ans+=f[m]*num[m]/2;
			}
			else{
				ans+=f[m]*(num[m]-1)/2;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
