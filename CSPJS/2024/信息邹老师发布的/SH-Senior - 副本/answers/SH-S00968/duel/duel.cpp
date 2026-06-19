#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n;
int a[N];
int remain[N];
int sum=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		remain[a[i]]++;
	}
	sum=0;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			sum=sum+remain[a[i-1]]-1;//填充并杀死一个怪兽 
		}
		else{
			if(sum){
				sum--;
			}
		}
	}
	sum=sum+remain[a[n]]; //显然最后一个不会被杀死
	printf("%d",sum); 
	return 0;
}
