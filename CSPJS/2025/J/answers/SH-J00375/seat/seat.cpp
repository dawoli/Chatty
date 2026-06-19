#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int scores[1050];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n*m;i++) cin>>scores[i];
	int s = scores[0];
	sort(scores,scores+n*m,cmp);
	int a = find(scores,scores+n*m,s)-scores;
	int ln=a/n;
	int clm=(ln%2?n-a%n-1:a%n);
	cout<<ln+1<<" "<<clm+1<<endl;
	return 0;
} 
