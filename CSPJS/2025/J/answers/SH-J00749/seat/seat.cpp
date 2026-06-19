#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int idx=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[idx];
			idx++;
		}
	}
	int x=a[1];
	sort(a+1,a+m*n+1,cmp);
	idx=1;
	for(int i=0;i<n*m;i++){
		if(a[idx]==x){
			break;
		}
		idx++;
	}
	int c=(idx-1)/n+1;
	cout<<c;
	int r;
	if(c%2==1)
		r=(idx-1)%n+1;
	else{
		r=n-((idx-1)%n);
	}
	cout<<" "<<r;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
