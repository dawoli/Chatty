#include <iostream>
#include <cstring> 
using namespace std;
string a[53];
int n;
int v[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int cnt = 52-n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)
			{
				continue;
			}
			else
			{
				if(a[i] == a[j] && v[i] == 0)
				{
					cnt++;
					v[j] = 1;
				}
				else
				{
					continue;
				}
			}
		}
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
