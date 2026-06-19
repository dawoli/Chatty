#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
string s;
int nums[N];

void quick_sort(int l,int r){
	if (l >= r) return;
	
	int x = nums[(l+r)>>1], i = l-1, j = r+1;
	while(i < j){
		do i++; while (nums[i] > x && i <= r);
		do j--; while(nums[j] < x && j >= l);
		if (i < j) swap(nums[i], nums[j]);
	}
	
	quick_sort(l, j);
	quick_sort(j+1, r);
}


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>> s;
	string digits="0123456789";
	
	for(int i = 0; i < s.length(); i++){
		if (0 <= digits.find(s[i]) && digits.find(s[i]) < 10){
			nums[n++] = s[i] - '0';
		}
	}

	quick_sort(0, n-1);

	for (int i = 0; i < n; i++) cout << nums[i];
	cout << endl;
	
	return 0;
}
