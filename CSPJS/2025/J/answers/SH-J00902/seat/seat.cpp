#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[12][12],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((i==1)&&(j==1)){
				cin>>c;
				a[1][1]=c;
				continue;
			}
			cin>>a[i][j];
		}
		if(i%2){
			for(int p=1;p<n;p++){
				for(int q=n;q>p;q--){
					if(a[i][q]>a[i][q-1]){
						int t;
						t=a[i][q];
						a[i][q]=a[i][q-1];
						a[i][q-1]=t;
					}
				}
			}
		}else{
			for(int p=1;p<n;p++){
				for(int q=n;q>p;q--){
					if(a[i][q]<a[i][q-1]){
						int t;
						t=a[i][q];
						a[i][q]=a[i][q-1];
						a[i][q-1]=t;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==c){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
