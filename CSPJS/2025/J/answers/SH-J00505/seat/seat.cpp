#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
int bi,ai;
int R,num=1;
int n[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	
	cin>>R;
	n[1]=R;
	for(int i=2;i<=a*b;i++){
		cin>>n[i];
	}

	sort(n+1,n+1+a*b);
	for(int i=1;i<=a*b;i++){
		if(n[i]==R){
			num=a*b+1-i;
			break;
		}
	}

	ai=num;
	while (1){
		ai-=a;
		if(ai>0){
			bi++;
		}
		else{
			break;
		}
	}
	ai+=a;
	if(bi%2==1){
		cout<<bi+1<<" "<<a+1-ai;
	}
	else{
		cout<<bi+1<<" "<<ai;
	}
	return 0;
}
