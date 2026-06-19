#include<bits/stdc++.h>
using namespace std;
string s[31];
int main()
{
	for(int i=1;i<=22;i++)
		getline(cin,s[i]);
	system("cls");
	for(int i=1;i<=22;i++)
		cout<<"printf(\""<<s[i]<<"\\n\");\n";
	for(;;);
	return 0;
}
