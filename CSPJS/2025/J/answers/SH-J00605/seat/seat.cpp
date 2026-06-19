#include<bits/stdc++.h>
using namespace std;
int a[109],n,m,r,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=n*m-i+1;
			break;
		}
	}
	int shang=(cnt-1)/n+1;
	int yu=cnt%n;
	if(yu==0) yu=n;
	cout<<shang<<" ";
	if(shang%2==1){
		cout<<yu;
		return 0;
	}else{
		cout<<n-yu+1;
		return 0;
	}
	return 0;
}
