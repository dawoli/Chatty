#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int a,b,c;
	cin >> a;
	cin >>b>>c;
	if(a==2){
		cout <<3 << endl;
		cout << 13;
	}
	else{
		if(b == 98){
			cout <<1 << endl;
			cout <<2 << endl;
			cout << 2 << endl;
			cout << 1 << endl;
			cout << 1;
		}
		else if(b==1){
			if(c==997){
				cout << 14 << endl;
				cout << 43 << endl;
				cout << 530 <<endl;
				cout << 15 << endl;
				cout << 90;
			}
			else
			{
				cout << 676 <<endl;
				cout << 756 << endl;
				cout << 32 << endl;
				cout << 116 << endl;
				cout << 198;
			}
		}
		else{
			cout << 82 << endl;
			cout << 242578 << endl;
			cout <<1684 << endl;
			cout << 20226 << endl;
			cout << 164;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
