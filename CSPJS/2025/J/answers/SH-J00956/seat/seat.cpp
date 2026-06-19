#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[2];
	cin>>a[0]>>a[1];
	int b[a[0]*a[1]];
	int c=1;
	for(int i=0;i<a[0]*a[1];i++){
        cin>>b[i];
        if(i>0){
            if(b[i]>b[0]){
                c++;
            }
        }
	}
	int d[2];
	if(c%a[0]==0){
        d[0]=c/a[0];
        d[1]=a[0];
	}
	else if((c/a[0]+1)%2==0){
        d[0]=c/a[0]+1;
        d[1]=c%a[0]+1;
	}
	else{
        d[0]=c/a[0]+1;
        d[1]=a[0]-c%a[0]-1;
	}
	cout<<d[0]<<" "<<d[1];
	return 0;
}
