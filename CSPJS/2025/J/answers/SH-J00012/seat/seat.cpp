#include  <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c[100010];
	cin >>a>>b;
    for(int i=0;i<a*b;i++){
    cin >> c[i];
}
int cn=0;
for(int i=1;i<a*b;i++){
	if(c[i]>c[0]){
		cn +=1;
	}
}
int cnt=cn+1;
int n,m;
if(cnt%a!=0){
	n= cnt/a+1;
}else{
	n= cnt/a;
}
int cnt2=cnt-(n-1)*a;
if(n%2==1){
	m=cnt2;
}else{
	m=b+1-cnt2;
}
cout <<n<<" "<<m;
fclose(stdin);
fclose(stdout);
	return 0;
}
