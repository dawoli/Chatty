#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;


//
int arr[500001];
int n, k;




//
int BI(int x)
{
	if(x == 0)
		return 0;
	if(x == 1)
		return 1;
		
		
	int num = 1;
	int bi[25];
	while(x>0){
		int tmp = x%2;
		bi[num] = tmp;
		//cout<<tmp<<endl;
		x = x / 2;
		num++;
	}
	int ans = 0;
	for(int i = num-1; i>=1; i--)
	{
		ans = ans * 10 + bi[i];
	}
	return ans;
}

int times(int a, int b)
{
	if(b == 0)
		return 1;
	int ans = 1;
	for(int i=0; i<b; i++)
	{
		ans = ans * a;
	}
	return ans;
}


int DEC(int x)
{
	int tmp;
	int i = 0;
	int ans = 0;
	
	while(x>0)
	{
		tmp = x%10;
		x = x / 10;
		if(tmp == 1)
			ans = ans + times(2, i);
		i++;
	}
	return ans;
}










//
int XOR(int a, int b)
{
	if(a == 0 && b != 0)
	{
		return b;
	}
	if(a != 0 && b == 0)
	{
		return a;
	}
	
	int x = BI(a);
	int y = BI(b); 
	//cout<<x<<" "<<y<<endl; 
	int A[25] = {0};
	int B[25] = {0};
	int C = 0;
	int i = 0;
	int tmp_A = 0;
	int tmp_B = 0;
	int num_A = 0;
	int num_B = 0;
	
	
	while(x>0)
	{
		if(x%10 >1)
			break;
		i++;
		tmp_A = x%10;
		A[i] = tmp_A;
		x = x / 10;
		//cout<<tmp_A<<" ";
	}
	//cout<<endl;
	num_A = i;
	i = 0;
	while(y>0)
	{
		i++;
		tmp_B = y%10;
		B[i] = tmp_B;
		//cout<<tmp_B<<" ";
		y = y / 10;
		
	}
	//cout<<endl;
	num_B = i;
	//cout<<"num_A:"<<num_A<<endl;
	//cout<<"num_B:"<<num_B<<endl;
	
	
	for(i = max(num_A, num_B); i>=1; i--)
	{
		if(A[i] == B[i])
		{
			C = C * 10;
		}
		else{
			C = C * 10 + 1;
		}
	}
	//cout<<C<<endl;
	return DEC(C);
		
}





//
int ans_ = 0;

void dfs(int index, int x, int num, bool flag)
{
	if(index > n){
		ans_ = max(ans_, num);
		return ;
	}
	if(x > k)
	{
		//cout<<"no"<<endl;
		return ;
	}
	if(XOR(x, arr[index]) == k)
	{
		dfs(index+1, 0, num + 1, false);
		//cout<<"yes"<<endl;
	}
	
	int tmp = arr[index];
	dfs(index+1, XOR(tmp, x), num, true);
	
	if(flag == false){
		//cout<<"escape"<<endl;
		dfs(index+1, 0, num, false);
	}
		
	
}










//
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		//cout<<bi_arr[i]<<endl;
		if(arr[i] == 0)
			ans_++;
	}
	if(k == 0)
	{
		cout<<ans_<<endl;
		return 0;
	}
	dfs(1, 0, 0, false);
	cout<<ans_;
	return 0;
	
	//cout<<XOR(1,7);
	//cout<<DEC(10);
	
 } 
