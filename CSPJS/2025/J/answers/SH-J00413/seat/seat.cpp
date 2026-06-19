#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
bool f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,c=1,r=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0) s=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==s){
			cout<<c<<" "<<r;
			break;
		}else{
			if(r!=n && f==0){
				r++;
			}else if(r!=1 && f==1){
				r--;
			}else{
				c++;
				if(c%2==0){
					f=1;
				}else{
					f=0;
				}
			}
		}
	}
	return 0;
}

