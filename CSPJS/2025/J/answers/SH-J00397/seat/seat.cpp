#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin >> n >> m;
	int a[1010];
	for (int i=1;i<=m*n;i++){
		cin >> a[i];
	}
	int xiaoR=a[1];
	for(int i=1;i<m*n;i++){
		for(int j=1;j<m*n;j++){
			if(a[j]<=a[j+1]){
			    int n;
			    n=a[j];
			    a[j]=a[j+1];
			    a[j+1]=n;
		    }
		}
		//cout << a[i] <<endl;
	}

	for(int i=1;i<=m*n;i++){
		if(xiaoR==a[i]){
			//cout << i << endl;
			int p=i/m;
			c=i/m+1;
			//cout << c;
			if(i%m==0){
				c--;
			}
			r=i%n;
			//cout << r;
			if(r==0){
				r=n;
			}
			if(c%2==0){
				r=n;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
