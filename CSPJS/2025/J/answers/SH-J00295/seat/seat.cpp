#include<bits/stdc++.h>
using namespace std;
int point[120]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>point[i];
	}
	int rpoint=point[0];
	sort(point,point+m*n);
	int cnt=m*n-1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
			if(point[cnt]==rpoint){
				cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt--;
			}
		}else{
			for(int j=m;j>=1;j--){
			if(point[cnt]==rpoint){
				cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt--;
			}
		}
		
	}
	return 0;
}
