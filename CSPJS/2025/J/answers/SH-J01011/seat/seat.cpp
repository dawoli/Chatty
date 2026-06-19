#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int index=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(index==a[i]){
			index=i;break;
		}
	}
	int col,row;
	if(index%n==0){
		col=index/n;
		if(col%2==1){
			row=n;
		}else{
			row=1;
		}
	}else{
		col=index/n+1;
		if(col%2==1){
			row=index-(col-1)*n;
		}else{
			row=n-(index-(col-1)*n)+1;
		}
	}
	cout<<col<<' '<<row;
	fclose(stdin);fclose(stdout);
	return 0;
}
