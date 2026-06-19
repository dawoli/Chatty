#include<bits/stdc++.h>
using namespace std;
int n,m,tar,tarkey;
int lst[105];
int bio_search(int x){
	int left=1,right=n*m;
	int mid=(left+right)/2;
	while(left<right){
		mid=(left+right)/2;
		if(lst[mid]>tar){
			left=mid+1;
		}else{
			right=mid;
		}
		//cout<<left<<" "<<right<<" "<<mid<<endl;
	}
	return right;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>lst[i];
	}
	tar=lst[1];
	sort(lst+1,lst+n*m+1,cmp);
	tarkey=bio_search(tar);
	int mdd=tarkey%(2*n);
	if(mdd==0){
		mdd=2*n;
	} 
	if(mdd>n){
		cout<<(tarkey-1)/n+1<<" "<<2*n-mdd+1;
	}else{
		cout<<(tarkey-1)/n+1<<" "<<mdd;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
