#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ex[n*m];
	for(int i=0;i<=n*m-1;i++){
		cin>>ex[i];
	}
	int i=0,j=0,cmp=1;
	while(ex[cmp]>ex[0]){
		cmp++;
		if(i%2==0 and j==n-1 or i%2==1 and j==0){
			i++;
		}
		else if(i%2==0){
			j++;
		}
		else{
			j--;
		}
	}
	cout<<i+1<<' '<<j+1;
	return 0;
	
}
