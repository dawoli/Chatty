#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[105];
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,q,k=0,e;cin>>p>>q;
	for(int i=0;i<p*q;++i){
		cin>>b[i];
	}
	for(int i=0;i<p*q;++i){
		n=0;m=0;
		for(int j=0;j<p*q;++j){
			if(b[j]>n){
				n=b[j];
				m=j;
			}
		}
		c[i]=n;
		b[m]=0;
		if(m==0){
			e=i;
			break;
		}
	}
	int d=1,f=1;
	while(k!=e){
		a[d][f]=c[k];
		k+=1;
		if(d%2==1&&f!=q){
		    f+=1;
		    continue;
		}
		if(d%2==1&&f==q){
		    d+=1;
		    continue;
		}
		if(d%2==0&&f!=1){
		    f-=1;
		    continue;
		}
		if(d%2==0&&f==1){
		    d+=1;
		    continue;
		}
	}
	cout<<d<<" "<<f;
	fclose(stdin);fclose(stdout);
	return 0;
}
