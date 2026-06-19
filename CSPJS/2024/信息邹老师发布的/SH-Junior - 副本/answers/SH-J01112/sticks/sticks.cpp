#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	int n;
	int h[8];
	h[2]=1;
	h[3]=7;
	h[4]=4;
	h[5]=2;
	h[6]=6;
	h[7]=8;
	int s[10009];
	int f[10009];
	int a=0;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n==0 ||n==1){
			s[i]=-1;
		}
		else if(n==2){
			s[i]=1;
		}
		else if(n==3){
			s[i]=7;
		}
		else if(n==4){
			s[i]=4;
		}
		else if(n==5){
			s[i]=2;
		}
		else if(n==6){
			s[i]=6;
		}
		else if(n==7){
			s[i]=8;
		}
		else if(n<=14){
			for(int j=2;j<=7;j++){
				for(int k=2;j<=7;j++){
					for(int l=0;l<36;l++){
						if((j+k)>7){
							f[l]=10*h[j]+h[k];
						}
					}
				}
			}
			a=f[0];
			for(int j=1;j<36;j++){
				if(f[j]<a){
					swap(f[0],f[j]);
				}
			}
			s[i]=f[0];
		}
		else if(n<=21){
			for(int j=2;j<=7;j++){
				for(int k=2;j<=7;j++){
					for(int o=2;o<=7;o++){
						for(int l=0;l<216;l++){
							if((j+k)>7){
								f[l]=100*s[j]+10*s[k]+s[o];
							}
						}
					}
				}
			}
			a=f[0];
			for(int j=1;j<216;j++){
				if(f[j]<a){
					swap(f[0],f[j]);
				}
			}
			s[i]=f[0];
		}
	}
	for(int i=0;i<T;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
