#include<bits/stdc++.h>
using namespace std;

int n,m;
int p[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>p[i];
	int a=p[0];// 小R的成绩 
	sort(p,p+n*m);
//	for(int i=0;i<n*m;i++)
//		cout<<p[i]<<" "; 
//	
	int seat;
	for(int i=0;i<n*m;i++) if(p[i]==a) seat=i;
	seat=n*m-seat-1;
	//cout<<seat<<endl;
	//列
	int width=seat/n+1;
	//行
	int height;
	if(width%2==0){
		height=n-(seat%n);
	}else{
		height=seat%n+1;
	}
	
	cout<<width<<" "<<height;
	
}
