#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,scroe[105],seat[15][15]={},x,y,mys;
	long long zhuangtai=0;
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> scroe[i];
	}
	mys=scroe[0];
	sort(scroe,scroe+(m*n),cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			seat[i][j] = scroe[zhuangtai];
			zhuangtai++;
		}
		if(i+1<n) i++;
		else break;
		for(int j=m-1;j>=0;j--){
			seat[i][j] = scroe[zhuangtai];
			zhuangtai++;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mys!=seat[i][j]) continue;
			else{
				x=i+1;
				y=j+1;
			}
		}
	}
	cout << x << " " << y;
	return 0;
} 
