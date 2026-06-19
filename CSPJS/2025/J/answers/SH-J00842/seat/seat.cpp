#include<bits/stdc++.h>
using namespace std;
struct st{
	int a;
	int b;
};
st a[10001];
bool cmp(const st a,const st b){
	return a.a>b.a;
}
int n,m,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].b=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[cnt].b==1){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[cnt].b==1){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
