#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c,r;
int s[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++)cin>>s[i];
	int a=s[1];
	sort(s+1,s+num+1,cmp);
	int idx=0;
	for(int i=1;i<=num;i++){
		if(s[i]==a){
			idx=i;
			break;
		}
	}
	c=idx/n;
	if(idx%n!=0){
		c++;
	}
	if(c%2==1){
		if(c==1)r=idx;
		else{
			r=idx-c*n+n;
		}
	}else{
		r=n-(idx-c*n+n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
