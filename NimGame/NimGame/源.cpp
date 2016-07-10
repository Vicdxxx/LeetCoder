#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Solution1 {
	int N;
	int odd;
	bool get;
	
public:
	vector<int> a;
	bool canWinNim(int n) {
		N = n;
		odd = 0;
		get = false;
		for (int i = 1; i < 3; i++)
		{
			count(n - i);
		}
		return get;
	}
	void count(int x)
	{
		odd++;
		a.push_back(x);
		if (x==0)
		{
			if (odd % 2 == 1)
			{
				get = true;
			}
			odd--;
			return;
		}
		if (x < 0)
		{
			odd--;
			return;
		}
		for (int i = 1; i < 3; i++)
		{
			count(x - i);
		}
		a.pop_back();
		odd--;
	}
};
class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}

	void moveZeroes(vector<int>& nums) {
		int a = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				nums[a++] = nums[i];
			}
		}
		for ( ; a < nums.size(); a++)
		{
			nums[a] = 0;
		}
		
	}
	void sort(vector<int>& nums,int begin,int end)
	{
		for (int j = 0; j < end - begin - 1; j++)
		for (int i = begin+1+j; i <= end; i++)
		{
			if (nums[i] < nums[i-1])
			{
				int tmp = nums[i];
				nums[i] = nums[i - 1];
				nums[i-1] = tmp;
			}
		}
	}
};

void main()
{
	Solution s = Solution();
	vector<int> nums(5,0);
	nums[0]=0;
	nums[1] = 1;
	nums[2] = 0;
	nums[3] = 3;
	nums[4] = 12;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";

	cout << endl;
	s.moveZeroes(nums);
	for (int i = 0; i < nums.size();i++)
		cout <<nums[i] << " ";
	
	cin.get();
}