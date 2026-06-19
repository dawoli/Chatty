#include <iostream>
#include <cmath>


using namespace std;

//
int max_ = 0;
int n;
int arr[5001];



//
void dfs(int index, int length, int maxl, int sides)
{
	if(index>n)
	{
		return;
	} 
	if(length > 2*maxl && sides >= 3){
		max_++;
	}
	
	dfs(index+1, length, maxl, sides);
	int tmp = arr[index];
	int tmax = max(maxl, arr[index]);
	//cout<<"All Length:"<<length+tmp<<"tmax:"<<tmax<<"sides:"<<sides<<endl;
	dfs(index+1, length+tmp, tmax, sides+1);
	
} 


//
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
	}
	dfs(1,0,0,0);
	cout<<max_%998%224%353<<endl;
	return 0;
}
 
