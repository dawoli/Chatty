#include<bits/stdc++.h>
using namespace std;

int T, n, a[16];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int c=0, mx=0;
		for(int i=n-1;i>=0;i--)cin>>a[i];
		for(int s=0;s<(1<<n);s++){
			c=0;	
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if((s&(1<<j))&&(s&(1<<i))){
						if(a[i]==a[j]){
							c+=a[i];
						}
					}
					if((!s&(1<<j))&&(!s&(1<<i))){
						if(a[i]==a[j]){
							c+=a[i];
						}
						break;
					}
				}
			}
			mx=max(mx, c);
		}
		cout<<mx<<endl;
	}
	return 0;
}
