#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,a[10]={6,2,5,5,4,5,6,3,7,6},n,x=0,k,p,l=0;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=1;j<=100001;j++){
			if(n==1)
			break;
			k=j;
			p=0;
			x=0;
			while(k>0){
			p=k%10;
			x+=a[p];
			k/=10;	
			}
			if(x==n){
				l=j;
				break;
			}
		}
		if(l==0)
		cout<<"-1"<<endl;
		else
		cout<<l<<endl;
	}
	return 0;
}
