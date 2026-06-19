#include<bits/stdc++.h>
using namespace std;
int a[2000],b,n,m,aa,c,d,e;
char s[2000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>aa>>b;
	c=aa*b;
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	d=a[0];
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		if(a[i]==d){
			n=i/aa;
			e=i%aa+1;
			if(e>0){
				n++;
			}
		}
	}
	if(n%2==0){
		m=b-e+1;
	}else{
		m=e;
	}
	cout<<n<<" "<<m;
}
