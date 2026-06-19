#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,b,c,cnt,d,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1,b=0;i<=n;i++){
		b++;
		cin>>a[b];
		if(a[b]!=0&&a[b]!=1){
			c=1;
		}
	}
	if(!c){
		if(k!=1&&k!=0){
			cout<<0;
			return 0;
		}
		else{
			if(k){
				for(i=1;i<=n;i++){
					cnt+=a[i];
				}
				cout<<cnt; 
				return 0;
			}
			else{
				for(i=1,d=0;i<=n;i++){
					d=(a[i]+d)%2;
					if(!d){
						cnt++;
					}
				}
				cout<<cnt;
				return 0;
			}
		}
	}
	else{
		for(i=1,d=0;i<=n;i++){
				d=(a[i]^d);
				if(d==k){
					cnt++;
					d=0;
				}
			}
		cout<<cnt;
		return 0;
	}
	return 0;
}
