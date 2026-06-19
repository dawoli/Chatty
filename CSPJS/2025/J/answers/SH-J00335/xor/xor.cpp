#include<bits/stdc++.h>
using namespace std;
int cal(int p,int q){
	int sum1=0,sum2=0;
	int s[500];
	int t[500];
	int k[500];
	while(p!=0){
		int i=0;
		if(p%2==0){
			p/=2;
			s[i]=0;
		}
		else{
			p=(p-1)/2;
			s[i]=1;
		}
		i++;
		sum1++;
	}
	while(q!=0){
		int i=0;
		if(q%2==0){
			q/=2;
			t[i]=0;
		}
		else{
			q=(q-1)/2;
			t[i]=1;
		}
		i++;
		sum2++;
	}
	if(sum1>=sum2){
		sum2=sum1;
	}
	for(int i=sum2-1;i>=0;i+=0){
		for(int j=sum2-1;j>=0;j--){
		    if((s[i]==1&&s[j]==1)||(s[i]==0&&s[j]==0)){
		    	k[j]=0;
			}
			else{
				k[j]=1;
			}
			i--;
	    }
	}
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,k,sum=0;
	cin >> n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[n];
	}
	int x[n];
	for(int i=0;i<n;i++){
		x[i]=a[i];
		if(i>0){
			x[i]=cal(x[i],x[i-1]);
		}
		if(x[i]==k){
			sum++;
			x[i]=0;
		}
	}
	cout << sum;
	return 0;
}
