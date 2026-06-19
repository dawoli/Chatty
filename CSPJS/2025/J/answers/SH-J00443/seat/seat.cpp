#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],k,w;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(k==a[i]){
			w=i;
			break;
		}
	}
	if(w%n==0){
		cout<<w/n<<" ";
		if((w/n)%2==0)	cout<<"1";
		else 	cout<<n;
	}else{
		cout<<w/n+1<<" ";
		int h=w/n+1,d=w%n;
		if(h%2==0){
			cout<<n+1-d;
		}else	cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
