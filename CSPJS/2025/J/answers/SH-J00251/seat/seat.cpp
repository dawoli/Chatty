#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,s;
	cin>>n>>m;
	int scores[110];
	for(int i=1;i<=n*m;i++){
		cin>>scores[i];
	}
	s=scores[1];
	sort(scores+1,scores+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(scores[i]==s){
			if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2){
					if(i%n==0){
						cout<<n;
					}else{
						cout<<i%n;
					}
				}else{
					cout<<m+1-i%n;
				}
			}else{
				cout<<i/n+1<<" ";
				if((i/n+1)%2){
					if(i%n==0){
						cout<<n;
					}else{
						cout<<i%n;
					}
				}else{
					cout<<m+1-i%n;
				}
			}
			
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
