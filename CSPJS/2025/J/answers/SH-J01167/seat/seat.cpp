#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return (a>b ? true : false);
}
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m,a[num+1],score,cnt;
	for(int i=0;i<num;i++) cin>>a[i];
	score=a[0];
	sort(a,a+num,cmp);
	//for(int i=0;i<num;i++) cout<<a[i]<<" ";
	for(int i=0;i<num;i++){
		if(a[i]==score){
			cnt=i;
			break;
		}
	}
	int x=cnt/n+1;
	cnt%=n;
	int y=(x%2==1 ? cnt+1 : m-cnt);
	cout<<x<<" "<<y;
	return 0;
}
