#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N],b[N];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i] = a[i]; 
	}
	
	int i=n-1,j=n-1;
	
	while(i>=0){
		if(a[i] - b[j] < 0){
			a[i] = -1;
			i--;
			j--;
		}
		else{
			i--;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]>0)
			ans++;
	} 
	cout<<ans;
	return 0;
}

 
