#include<bits/stdc++.h>
using namespace std;
int n,now,tmp,ret,a[500010];
long long k,xs[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		xs[i]=(xs[i-1]^(1LL*a[i]));
	}for(int l=1,r=1;l<=r,r<=n;){
		int flag=0;
		if((xs[r]^xs[l-1])==k){
			ret++;
			l=r+1;
			r=l;
			flag=1;
		}else{
			tmp=l;
			while(l<=r){
				if((xs[r]^xs[l-1])==k){
					ret++;
					l=r+1;
					r=l;
					flag=1;
					break;
				}l++;
			}if(flag==0){
				l=tmp;
			}
		}if(flag==0){
			r++;
		}
	}printf("%d",ret); 
	return 0;
}
