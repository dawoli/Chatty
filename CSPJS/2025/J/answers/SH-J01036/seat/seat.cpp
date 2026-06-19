#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,coin[105];
	cin>>n>>m>>r;
	for(int i=1;i<=n+m-1;i++){
		cin>>coin[i];
	}
	sort(coin+1,coin+n+m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				//	cout<<1<<" "<<(i-1)*n+j<<endl;
				if(r>coin[(i-1)*n+j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				//cout<<2<<" "<<i*n-j+1<<endl;
				if(r>coin[i*n-j+1]){
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
