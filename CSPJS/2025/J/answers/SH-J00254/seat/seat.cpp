#include<iostream>
#include<algorithm>
int a[101];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n*m;i++)std::cin>>a[i];
	int x=a[0];
	std::sort(a,a+n*m,cmp);
	int i=1,j=1;
	bool f=1;
	for(int k=0;a[k]!=x;k++){
		if(f){
			j++;
			if(j>n){f=0;j=n;i++;}
		}
		else{
			j--;
			if(j<1){f=1;j=1;i++;}
		}
	}
	std::cout<<i<<" "<<j;
	return 0;
}
