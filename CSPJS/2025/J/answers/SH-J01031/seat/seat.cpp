#include <bits/stdc++.h>
using namespace std;
int x,l,k=1,f=1;
int a[110];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freoprn("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			l=i;
		}
	}int i=1,j=1;
	while(1){
		if(k==l){
			cout << j << " " << i;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}k++;
		i+=f;
		if(k==l){
			cout << j << " " << i;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(i==n || i==1){
			f*=-1;
			j++;
			k++;
		}
	}
}
