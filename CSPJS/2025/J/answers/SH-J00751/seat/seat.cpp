#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[14][14];
int a[200],a1[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];//a[i]代表每个人的成绩 
	}
	int op=a[1];//op代表小R的成绩
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		a1[i]=a[i];
	}
	for(int i=1;i<=n*m;i++){
		a[i]=a1[n*m+1-i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				mp[i][j]=a[(i-1)*n+j];//mp数组先列再行，一会儿输出时也是先列再行 
			}else if(i%2==0){
				mp[i][j]=a[i*n-j+1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==op){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
