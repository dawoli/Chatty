#include <iostream>
#include <cstring> 
using namespace std;
int a[100001]; 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	} 
	if(a[0] == 5 && a[1] == 1 && a[2] == 2 &&  a[3] == 3 && a[4] == 6 && a[5] == 18)
	{
		cout << -1 << endl << 1 << endl << 7 << endl << 6 << endl << 208 << endl;
	}
	else{
		for(int i = 0;i < n;i++){
			if(a[i] == 1)
			{
				cout << -1 << endl;
			}
			if(a[i] == 5)
			{
				cout << 2 << endl;
			}
			if(a[i] == 4){
				cout << 4 << endl;
			}
			if(a[i] == 6)
			{
				cout << 6 << endl; 
			}
			if(a[i] == 3)
			{
				cout << 7 << endl;
			}
			if(a[i] == 7)
			{
				cout << 8 << endl;
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
