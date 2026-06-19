#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],a1,score[105],cnt;
bool cmp(int a,int b) 
{return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		if(i==1) a1=score[i];
	}
	sort(score+1,score+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<score[i]<<" ";
	int fx=1,zz=1,i=1,j=1;
	for(;;){
		a[j][i]=score[zz++];cnt++;
//		cout<<a[j][i]<<" "<<j<<" "<<i<<" "<<fx<<" "<<cnt<<endl;
		if(cnt%n==0) i++;
		else j+=fx;
		if(j==1) fx=1;
		else if(j==n) fx=-1;
		if(cnt==n*m) break;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[j][i]==a1) {
				cout<<i<<" "<<j;
				return 0; 
			}
	return 0;
}
