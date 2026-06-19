//CCFл╚ифа╪ак 
#include <bits/stdc++.h>
using namespace std;
int m,c,r,f,n;
int b[11][11];
struct stu{
	int cz,ind;
}s[105];
bool cmp(stu a,stu b){
	return a.cz>b.cz;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin<<s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].ind==1){
			f=i;
			break;
		}
	}
	c=ceil(f*1.0/n);
	r=f-(c-1)*n;
	cout<<c<<" "<<r;
	return 0;
}
