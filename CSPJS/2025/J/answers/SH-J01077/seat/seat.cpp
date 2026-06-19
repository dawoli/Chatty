#include<bits/stdc++.h> 
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,n,con=0,mm=1,nn=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
			if(a[i]>a[1])con++;
	}
	while(con--){
		if(nn==n&&mm%2==1)mm++;
		else if(nn==1&&mm%2==0)mm++;
		else if(mm%2==1)nn++;
		else if(mm%2==0)nn--;
	}
	cout<<mm<<' '<<nn;
	return 0;
}
