#include<bits\stdc++.h>
using namespace std;
int n,m,num=1,c,r;
int s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;++i)
		cin>>s[i];
	for(int i=0;i<n*m;++i){
		if(s[i]>s[0])
			num++;
	}
	c=num/n;
	if(num%n!=0)
		c++;
	if(c==1)
		r=num;
	else if(c%2!=0&&num%c!=0)
		r=num%c;
	else if(num%c!=0)
		r=n-num%c+1;
	else
		r=n-num%c;
	cout<<c<<" "<<r;
	return 0;
}
