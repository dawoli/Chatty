#include<iostream>
#include<algorithm>
using namespace std;
int arr[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m,time;
	for(int i=1;i<=num;i++)cin>>arr[i];
	int r=arr[1];
	sort(arr+1,arr+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(arr[i]==r){
			time=i-1;
			break;
		}
	}
	int x=1,y=1;
	while(time--){
		if((x==n&&y%2==1)||(x==1&&y%2==0))y++;
		else if(y%2==1)x++;
		else if(y%2==0)x--;
	}
	cout<<y<<" "<<x;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
