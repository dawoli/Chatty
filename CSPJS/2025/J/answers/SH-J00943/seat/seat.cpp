#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],b[15][15],q,ansi,ansj;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[k];
				if(a[k]==q){
					ansi=i;
					ansj=j;
				}
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[k];
				if(a[k]==q){
					ansi=i;
					ansj=j;
				}
				k++;
			}
		}
	}
	cout<<ansi<<" "<<ansj;
}
