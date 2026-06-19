#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,num=1;
	bool flag=0;
	for(int j=1;j<=m&&!flag;j++){
		if(i<=1){
			for(i=1;i<=n;i++,num++){
				if(a[num]==k){
					cout<<j<<" "<<i;
					flag=1;
					break;
				}
			}
		}else{
			for(i=n;i>=1;i--,num++){
				if(a[num]==k){
					cout<<j<<" "<<i;
					flag=1;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
