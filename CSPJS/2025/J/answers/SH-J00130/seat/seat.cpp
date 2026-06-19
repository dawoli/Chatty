#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,hn,hm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int score=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			if(i%n==0)
				hm=i/n;
			else
				hm=i/n+1;
			if(hm%2==1){
				if(i%n==0)
					hn=n;
				else
					hn=i%n;
			}else{
				if(i%n==0)
					hn=1;
				else
					hn=n+1-i%n;
			}
			break;
		}
	}
	cout<<hm<<" "<<hn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
