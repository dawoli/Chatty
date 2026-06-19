#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
bool p(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(i==1){
			k=a[i];
		}
	}
	sort(a+1,a+n*m+1,p);
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			id=i;
		}
	}
	int i=1,j=1,cnt=1;
	while(cnt<id){
		if(i%2==1 && j+1<=m){
			j++;
		}
		else if(i%2==1 && j==m){
			i++;
		}
		else if(i%2==0 && j-1>=1){
			j--;
		}
		else{
			i++;
		}
		cnt++;
	}
	cout << i << ' ' << j;
	return 0;
}
