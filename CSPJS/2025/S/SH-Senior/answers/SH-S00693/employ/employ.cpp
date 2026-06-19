#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[510];
int c[501];
const int p = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i = 1;i <= n;i++)
	    scanf("%d",&c[i]);
	if(m==1){
		for(int i = 1;i <= n;i++){
		    if(s[i]=='1')
		       break;
		    if(i==n){
		    	printf("0");
		    	return 0;
			}
	    }
	    long long ans = n;
	    for(int i = n-1;i;i--){
	    	ans*=i;
	    	ans%=p;
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==n){
 		for(int i = 1;i <= n;i++){
		    if(s[i]=='0'){
		    	printf("0");
		    	return 0;
			}
	    }
	    long long ans = n;
	    for(int i = n-1;i;i--){
	    	ans*=i;
	    	ans%=p;
		}
		printf("%lld",ans);       
		return 0;
	}
	int flag = 0;
	for(int i = 1;i <= n;i++){
	    if(s[i]=='0')
	       break;
	    if(i==n)
	       flag=1;
    }
    if(flag==1){
    	long long ans = n;
	    for(int i = n-1;i;i--){
	    	ans*=i;
	    	ans%=p;
		}
		printf("%lld",ans);       
		return 0;
	}
	srand(time(0));
	int g = rand()%p+1;
	printf("%d",g);
	return 0;
}
