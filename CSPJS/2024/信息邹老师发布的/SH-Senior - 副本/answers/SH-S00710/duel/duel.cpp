#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,i,b,m,e;
	int min,mina,minb,mins,minc;
	int ans;
	int a[100002][2];
	cin>>n;
	ans=n;
	for(i=0;i<n;i++){
		cin>>a[i][1];
	}
	for(i=0;i<n;i++){
		a[i][0]=a[i][1];
	}
	if(n%2==0){
		b=n/2;
	}else{
		b=n/2+1;
	}
	for(e=0;e<b;e++){
		min=100020;
		mins=100020;
		for(i=0;i<n;i++){
			if(a[i][1]<min){
				min=a[i][1];
				mina=i;
			}
		}
		for(i=0,m=0;i<n;i++){
			if(a[i][m]<mins&&a[i][m]!=min){
				mins=a[i][m];
				minb=i;
			}
		}
		if(mins==100020){
			mins==100020;
		}
		else{
			a[minb][0]=100020;
			if(mins>min){
				ans=ans-1;
			}
		}
	}
	cout<<ans;
}

