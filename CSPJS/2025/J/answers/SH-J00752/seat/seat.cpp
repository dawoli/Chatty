#include<bits/stdc++.h>
using namespace std;
int a[110],s[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t1=1,t2=1,w=1,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(n==2){
		if(a[1]==r) cout<<"1 1";
		else if(a[2]==r) cout<<"1 2";
		else if(a[3]==r) cout<<"2 2";
		else if(a[4]==r) cout<<"2 1";
	}
	else{
		s[1][1]=a[1];
		if(a[1]==r){
			cout<<"1 1";
			return 0;
		}
		for(int i=2;i<=n*m;i++){
			t1+=w;
			s[t1][t2]=a[i];
			if(a[i]==r){
				cout<<t2<<" "<<t1;
				break;
			}
			if(t1==1){
				t2++;
				w=-w;
				s[t1][t2]=a[++i];
			}
			else if(t1==n){
				t2++;
				w=-w;
				s[t1][t2]=a[++i];
			}
			if(a[i]==r){
				cout<<t2<<" "<<t1;
				break;
			}
		}
	}
	return 0;
}

