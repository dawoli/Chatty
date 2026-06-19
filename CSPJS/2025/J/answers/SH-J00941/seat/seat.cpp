#include<bits/stdc++.h>
using namespace std;
int m,n,r,c;
int a[500];

bool cmp(int x,int y){
	return x>y; 
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n;
	int l=n*m;
	for (int i=1;i<=l;i++){
		cin >> a[i];
	}
	int ans=a[1];
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==ans){
			c=i/n;
			if(i%n!=0)	c++;
			if(c%2==1){
				if(i%n==0)	r=n;
				else	r=i%n;
			}
			else	r=n+1-(i-(c-1)*n);
			break;
		}
	}
	cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
