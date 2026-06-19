#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,c1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int s=i;s<n;s++){
			if(i-s==0){
				if(a[i]==k){
					cnt++;
					i=s;
				}
			}else{
				c1=a[i];
				for(int q=i+1;q<=s;q++){
					c1=c1 xor a[q];
				}
				if(c1==k){
					cnt++;
					i=s;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
