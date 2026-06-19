#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	int answer;
	cin >> n >> m;
	int p=n*m;
	int s[p];
	for(int i=0;i<p;i++){
		cin >> s[i];
	}
	int score=s[0];
	sort(s,s+p,cmp);
	int l=0,r=p,mid;
	while(1){
		mid=(l+r)/2;
		if(s[mid]<score){
			r=mid;
		}else if(s[mid]>score){
			l=mid+1;
		}else{
			answer=mid;
			break;
		}
	}
	cout<<answer/n+1<<" ";
	if((answer/n+1)%2==0){
		cout<<n-answer%n;
	}else{
		cout<<answer%n+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
