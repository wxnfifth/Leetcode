#include <iostream>
using namespace std;
 
const int n = 10;
int sum[n + 1] = {0};
 
 
int lowbit(int t)
{
return t&(-t);
}
 
int get(int x) {
	int ans = 0;
	for (int i = x; i > 0;i -= lowbit(i)) {
		ans += sum[i];
	}
	return ans;
}
 
void add(int x,int value)
{
for(int i=x;i<=n;i+=lowbit(i))
sum[i]+=value;
}
 
 
int main() {
	for (int i = 1; i <= n; ++i) {
		add(i, i * 2);
	}
	for (int i = 1; i <= n; ++i) {
		cout << get(i) << "\n";
	}
 
 
	// your code goes here
	return 0;
}
