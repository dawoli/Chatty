#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=109;
const int M=19;
struct Node{
	int score,id;
}a[N];
bool cmp(const Node&a,const Node&b){
	if(a.score<b.score) return 0;
	else if(a.score>b.score) return 1;
}
int n,m;
int seat[M][M];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
    }
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m;i++){
    	if(i%2==1){
    		for(int j=1;j<=n;j++)
    		    seat[j][i]=a[(i-1)*n+j].id;
		}
		else{
			for(int j=n;j>=1;j--)
    		    seat[j][i]=a[(i-1)*n+n-j+1].id;
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        if(seat[i][j]==1){
	        	cout<<j<<" "<<i<<endl;
	        	return 0;
			}
	return 0;
} 
