#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[100005];
long long ans;
bool t=false;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	
	for(long long i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		
		
	}
//	if(!t){
//		
//		cout << n;
//		if(num>n-num){
//			printf("%lld",n-num);
//		}else{
//			printf("%lld",num);
//		}
//		return 0;
//	}
	sort(a+1,a+1+n);
	
	long long l=1;
	ans=n;
	for(long long i=2;i<=n;++i){
		if(a[l]<a[i]){
			ans-=1;
			l+=1;
		}
		
	}
	
	printf("%d",ans);
}
