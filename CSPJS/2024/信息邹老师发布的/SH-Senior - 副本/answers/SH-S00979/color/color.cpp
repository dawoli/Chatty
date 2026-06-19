#include<bits/stdc++.h>
using namespace std;

int T,a[11][20001],b[2000],c[2000];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdin);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	while(T>0){
		if(a[T][0]==2){
			if(a[T][1]!=a[T][2])cout<<0<<endl;
			else cout<<a[T][1]<<endl;
		}
		if(a[T][0]==3){
			if(a[T][1]==a[T][3])cout<<a[T][1]<<endl;
			else cout<<0<<endl;
		}
		for(int i=1;i<=a[T][0];i++){
			b[a[T][i]]++;
			}
			int j=1;
		for(int i=1;i<=2000;i++){
			if(b[i]!=0){
				c[j]=i;j++;
			}
		}
		T--;
	}
	return 0;
}
