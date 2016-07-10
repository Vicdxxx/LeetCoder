#include<iostream>
#include<cmath>

using namespace std;
class Solution {
public:
	bool isPowerOfThree(int n) {
		int log_max=(int)log(0x7fffffff) / log(3);
		int power_max=pow(3, log_max);
		if (power_max%n==0)
			return true;
		return false;
	}
};

void main1()
{
	cout << std::numeric_limits<int>::max() << endl;

	cout<<pow(3, (int)log(0x7fffffff)/log(3))<<endl;
	cout << ceil(3.1)<<endl;
	Solution s = Solution();
	bool x=s.isPowerOfThree(243);
	cout << (log(1594322) / log(3)) << endl;
	cout << ceil(log(1594322) / log(3)) << endl;
	cout<< floor(log(1594322) / log(3) )<<endl;
	cin.get();
}