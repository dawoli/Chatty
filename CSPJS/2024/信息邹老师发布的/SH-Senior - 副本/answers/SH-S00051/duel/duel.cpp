#include<bits/stdc++.h>
using namespace std;
int a[10010];
int b[10010];
int tmp=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	int c[100100];
	cin>>n;
	for(int z=0;z<n;z++){
		cin>>a[z];
	}
	for(int l=0;l<n;l++){
		if(b[l]==0 and c[l]==0){
			for(int i=0;i<n;i++){
				if(c[i]==0){
					if(a[i]<a[l]){
					b[l]=1;
					b[i]=1;
					c[i]=1;
					break;
					}
				}
			}
		}
	}
	for(int k=0;k<n;k++){
		if(c[k]==0){
			tmp++;
		}
	}
	cout<<tmp;
	return 0;
}
