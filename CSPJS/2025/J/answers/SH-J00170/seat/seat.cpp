#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[150];
int leng;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    leng=n*m;
    int r=0;
    
    for(int i=1;i<=leng;i++){
    	cin>>a[i];
    	
	}
	r=a[1];
	sort(a+1,a+leng+1,cmp);
    
    int itaaa=0;
    while(a[itaaa]!=r){
    	itaaa++;
	}
	
    int lie=itaaa/n;
    if(n*lie<itaaa)lie++;
    
    
    int hang=(itaaa%n);
    if(lie%2!=0){
    	if(hang==0)hang=n;
	}
	else{
		if(hang==0)hang=1;
		else{
			hang=n-hang+1;
		}
	}
    cout<<lie<<" "<<hang;
	return 0;

}
