#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],frz[1010];
bool ch(int i){
	return (i%2==1); 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>frz[i];
	int _p=frz[1];
	sort(frz+1,frz+n*m+1);
	int _i=n*m;
	for(int i=1;i<=m;i++){
		int h=ch(i);
		if(h==1){
			for(int j=n;j>=1;j--){
				if(frz[_i]==_p){
					cout<<i<<' '<<n-j+1;
					//cout<<'\n'<<_i<<' '<<_p;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				a[i][j]=frz[_i--];
				
			}
		}else{
			for(int j=1;j<=n;j++){
				if(frz[_i]==_p){
					cout<<i<<' '<<n-j+1;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				a[i][j]=frz[_i--];
				
			}
		}
	}
} 
