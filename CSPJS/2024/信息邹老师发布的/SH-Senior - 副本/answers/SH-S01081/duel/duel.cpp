#include<iostream>
	int count[100003];
	int sorted[100003];
int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		count[a]++;
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (count[i] > t)
			t = count[i];
	}
	std::cout << t;
}
