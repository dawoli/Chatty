#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[105],n,m,f,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int j=1;j<=m;){
		for(int i=1;i<=n;i++){
			cnt++;
			if(a[1]==b[cnt]){
				cout<<j<<' '<<i;
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
		j++;
		for(int i=n;i>=1;i--){
			cnt++;
			if(a[cnt]==b[1]){
				cout<<j<<' '<<i;
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
		j++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
