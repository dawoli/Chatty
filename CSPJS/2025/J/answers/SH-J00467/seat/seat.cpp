#include<bits/stdc++.h>
using namespace std;
int a[30][30],b[1000],m,n,r,flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			r=b[i];
		}
	}
	sort(1+b,m*n+b+1);
	for(int i=1;i<=n*m;i++){
		if(r==b[i]){
			flag=i;
		}
	}
	flag=m*n-flag+1;

	int count=0;
	if(flag%m!=0){
		count=flag/m+1;
	}else{
		count=flag/m;
	}
	int count2=count;
    count2%=2;
	if(flag%m!=0){
		flag%=m; 
	}else{
		flag%=m;
		flag=m;
	}
	cout<<count<<' ';
	if(count2==1){
        cout<<flag<<' ';
	}else{
		int k=m-flag+1;
		cout<<k<<' ';
   }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92

