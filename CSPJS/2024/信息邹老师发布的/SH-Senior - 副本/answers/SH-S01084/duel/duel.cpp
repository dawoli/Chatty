#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n;
int a[100009];
bool v[100009] = {0};
bool died[100009] = {0};
int r;
int func()
{
	for(int i = 0; i < n; i++)
	{
		int j = i+1;
		for(; j < n; j++)
		{
			if(!v[j] and !died[i] and a[i]<a[j])
			{
				//cout << a[j] << "È¥¹¥»÷" << a[i] << ' ' << r-1 << endl; 
				v[j]=true;//attacked
				died[i]=true;
				r--;
			}
		}
	}
	return 0;
}


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	r = n;
	sort(a,a+n);
	func();
	printf("%d",r);
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
