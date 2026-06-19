#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,A=1e6+10;
int t,n,a[N];
long long ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		ans=0;
		for(int i=0;i<1<<n;i++){
			long long temp=0;
			int r=A,b=A;
			for(int j=0;j<n;j++)
				if(i&(1<<j)){
					if(r==a[j])temp+=a[j];
					r=a[j];
				}else{
					if(b==a[j])temp+=a[j];
					b=a[j];
				}
			ans=max(ans,temp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
