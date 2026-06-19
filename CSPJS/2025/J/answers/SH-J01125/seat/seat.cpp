#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e3 + 1e1;
int n,m,a[N],R,rk;
bool cmp(int& x,int& y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);//n - hang ; m - lie
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			rk=i;
			break;
		}
	}
	printf("%d ",(rk-1)/n+1);//lie ( first ) 
	if(((rk-1)/n)&1){
		printf("%d\n",n-(rk-1)%n);//hang
	}
	else{
		printf("%d\n",(rk-1)%n+1);//hang
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
