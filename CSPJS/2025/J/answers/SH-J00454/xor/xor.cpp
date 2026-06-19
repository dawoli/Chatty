#include<bits/stdc++.h>
using namespace std;
int n,k;
long long t=0;
int xorsum;
int ans=0;
int a[1024];
int p[600000][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(true){
		for(int i=0;i<n;i++){
			xorsum=a[i];
			if(a[i]==k){
				p[t][0]=i;
				p[t][1]=i;
				t++;
				continue;
			}
			for(int j=i+1;j<n;j++){
				xorsum^=a[j];
				if(xorsum==k){
					p[t][0]=i;
					p[t][1]=j;
					t++;
					break;
				}
			}
		}
		for(int i=0;i<n;){
			for(int j=0;j<t;j++){
				if(p[j][0]==i){
					ans++;
					i=p[j][1];
					break;
				}
			}
			i++;
		}
		cout<<ans;
	}
	return 0;
} 
