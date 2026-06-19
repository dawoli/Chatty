#include<bits/stdc++.h>
using namespace std;
int c,r,a[1500],an,ind;
//rиообур 
void ch(int x){
	for(int i = 1;i<=r;i++){
		if(a[ind]==an){
			cout<<x<<" "<<i;
			exit(0);
		}
		ind++;
	}
	return ;
}

void ch1 (int x){
	for(int i = r;i>=1;i--){
		if(a[ind]==an){
			cout<<x<<" "<<i;
			exit(0);
		}
		ind++;
	}
	return ;
}

bool cmp(int aa,int bb){
	return aa>bb;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	cin>>a[0];
	an=a[0];
	for(int i = 1;i<(c*r);i++){
		cin>>a[i];
	}
	sort(a,a+(c*r)+1,cmp);
//	for(int i = 0;i<(c*r);i++){
//		cout<<a[i]<<" ";
//	}
	for(int i = 1;i<=c;i++){
		if(i%2==1) ch(i);
		if(i%2==0) ch1(i);
	}
	return 0;
}
