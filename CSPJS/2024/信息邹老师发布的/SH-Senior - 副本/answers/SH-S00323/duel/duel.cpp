#include<bits/stdc++.h>
using namespace std;
int r[100010],c[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,f=0,s=0,mins=100001;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		c[i]=r[i];
		mins=min(mins,r[i]);
		if(r[i]>2){
			f=1;
		}
	}
	if(!f){
		for(int i=1;i<=n;i++){
			if(r[i]==2){
				s++;
			}
		}
		if(s>=n/2){
			cout<<s;
		}
		else{
			cout<<n-s;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n && j!=i;j++){
				if(r[i]>c[j] && c[i] && c[j]){
					r[i]=0;
					c[j]=0;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]!=0){
				s++;
			}
		}
		cout<<s;
	}
	return 0;
}
