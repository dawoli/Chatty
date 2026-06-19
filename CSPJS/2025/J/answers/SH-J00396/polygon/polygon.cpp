#include<iostream>
using namespace std;
int arr[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i]; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
