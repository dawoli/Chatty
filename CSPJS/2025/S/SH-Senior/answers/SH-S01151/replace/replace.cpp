#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
std::ifstream fin ("replace.in" );
std::ofstream fout("replace.out");
int main() {
	int n, q; fin >> n >> q; 
	std::string x[n], y1[n], y2[n], z[n]; 
	for (int i = 0; i < n; i++) {
		std::string a, b; 
		fin >> a >> b; 
		if (a == b) {
			y1[i] = "@"; 
			continue; 
		}
		int start = 0; 
		while (a[start] == b[start]) start++; 
		int end = a.length()-1; 
		while (a[end] == b[end]) end--;
		end++; 
		x [i] = a.substr(0, start); 
		y1[i] = a.substr(start, end-start); 
		y2[i] = b.substr(start, end-start); 
		z [i] = a.substr(end, a.length()); 
//		std::cout << '|' << x [i] << '|' << y1[i] << '|'
//		 		  << y2[i] << '|'
//		          << z [i] << '|' << '\n';
	}
	
	
	for (int i = 0; i < q; i++) {
		std::string a, b; 
		fin >> a >> b; 
		if (a == b) {
			y1[i] = "@"; 
			continue; 
		}
		int start = 0; 
		while (a[start] == b[start]) start++; 
		int end = a.length()-1; 
		while (a[end] == b[end]) end--;
		end++; 
	std::string qx, qy1, qy2, qz; 
		qx = a.substr(0, start); 
		qy1 = a.substr(start, end-start); 
		qy2 = b.substr(start, end-start); 
		qz = a.substr(end, a.length()); int count = 0; 
		for (int i = 0; i < n; i++) {
			if (y1[i] == qy1 &&
			y2[i] == qy2 && qx.length() >= x[i].length()
			&& qz.length() >= z[i].length() &&
			qx.substr(qx.length()-x[i].length(), qx.length()) == x[i]
			&& qz.substr(0, z[i].length()) == z[i]) count++;
		}
		std::cout << count << '\n'; 
//		std::cout << '|' << x [i] << '|' << y1[i] << '|'
//		 		  << y2[i] << '|'
//		          << z [i] << '|' << '\n';
	}
}
