#include <iostream>
#include<algorithm>
using namespace std;
bool decreasing(int x, int y){
	if(x>y){
		return true;
	}
	return false;
}
int a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,decreasing);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pos=i;
			break;
		}
	}

	 int col = pos/n;
	 if(pos>col*n){
	 	col++; 
	 }
	 int row = pos%n;
	 if(row == 0){
	 	row=n;
	 }
	 if(col%2 == 0){
	 	row=n-row+1;
	 }
	 cout<<col<<" "<<row<<endl;
	return 0; 
}
