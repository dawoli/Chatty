#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
		}
	}
	int rn,rm;
	if(r%n==0){
		rm=r/m;
		if(rm%2==0){
			rn=1;
		}
		else rn=n;
	}
	else{
		rm=r/m+1;
		if(rm%2==0){
			rn=n+1-r%m;
		}
		else rn=r%m;
	}
	cout<<rm<<" "<<rn<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
