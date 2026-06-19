#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
bool b1[100010],b2[100010];
int ansBF1(int n){
	int m=n;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int i=2;i<=n;i++){
		    if(b[i]>=b[i-1]) m-=b[i-1];
	    	else m-=b[i];
    }
    return m;
}
int ansBF2(int n){
	int m=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			if(b1[i]==0&&b2[i-j]==0)
		    if(b[i]>=b[i-j]){
		    	m-=b[i-j];
		    	
		    }
	    	else m-=b[i];
		}
    }
    return m;
}
bool ismin(int n){
	if(*max_element(a+1,a+n+1)==2&&*min_element(a+1,a+n+1)==1) return true;
	else return false;
}
int ansmin(int n){
	int one=0,two=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) one++;
		else two++;
	}
	if(two>=one)return two;
	else return n-two;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
		b1[i]=0;
	}
	if(ismin(n)){
		cout<<ansmin(n);
	}else cout<<ansBF1(n);
	return 0;
}
