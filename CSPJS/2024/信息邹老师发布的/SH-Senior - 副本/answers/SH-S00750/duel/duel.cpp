#include <bits/stdc++.h>
using namespace std;
int a;
int b[1000000];
int e[1000000];
int ans;
int mi;
int c;
int d;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>a;
	ans=a;
	c=a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=0;i<100000;i++){
		e[i]=1;
	}
	for(int i=0;i<a;i++){
		if(b[i]<b[i+1]){
			mi=b[i];
			d=i;
			
		}
	}
		for(int i=0;i<=a;i++){
			if(b[i]>mi){
				ans-=1;
				c-=1;
				mi=0;
				e[d]=0;
				for(int i=0;i<a;i++){
					if(b[i]<b[i+1]||e[i]==1){
						mi=b[i];
						d=i;	
				}
			}
			if(c==1){
				break;
			}
		}
}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
