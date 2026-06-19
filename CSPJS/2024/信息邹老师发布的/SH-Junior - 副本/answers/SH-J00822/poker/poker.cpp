#include<bits/stdc++.h>

using namespace std;

int alist[53];
int number = 0;

int GetIndex(char text){
	switch(text){
		case 'D':
		return 0;
		case 'C':
		return 13;
		case 'H':
		return 26;
		case 'S':
		return 39;
	} 
} 
int GetIndex2(char text){
	switch(text){
		case 'A':
		return 1;
		case '2':
		return 2;
		case '3':
		return 3;
		case '4':
		return 4;
		case '5':
		return 5;
		case '6':
		return 6;
		case '7':
		return 7;
		case '8':
		return 8;
		case '9':
		return 9;
		case 'T':
		return 10;
		case 'J':
		return 11;
		case 'Q':
		return 12;
		case 'K':
		return 13;
	} 
} 

bool find(string text)
{
	int index1 = GetIndex(text[0]);
	int index2 = GetIndex2(text[1]);
	int index = index1 + index2; 
	int test = alist[index];
	if(test == 1)
	{
		return true; 
	} 
	alist[index] = 1; 
	return false; 
} 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(alist,0,sizeof(alist)); 
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		 string newpoker;
		 cin >> newpoker;
		 if(!find(newpoker))
		 {
		 	number++;
		 } 
	} 
	cout << 52 - number; 
	return 0; 
} 
