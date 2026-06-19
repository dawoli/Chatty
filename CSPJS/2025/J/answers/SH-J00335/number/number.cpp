#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int a[100];
	int t;
	int a1;
	int k[100];
	int s=0;
	cin >> a1;
	int i =0;
	while(a[i]!=0){
		for(int i = 0;i<100;i++){
		    k[i]=a[i];
		    s++;
	    }
    }
 	for(int i = 1;i<s-1;i++){
        for(int j = 1;j<=s-i;j++){
            if(k[j-1]<k[j]){
        	    t=k[j-1];
        	    k[j-1]=k[j];
        	    k[j]=t;
		    }
	    }
	}
	int x;
	for(int i = s-1;i>=0;i--){
		x+=k[i]*pow(10,i);
	}
	cout << x;
	return 0;
}
