#include<iostream>
#include<cmath>
#include<vector>
#include<map>

using namespace std;

class NumArray1 {
	vector<int> Nums;
public:
	NumArray1(vector<int> &nums) {
		Nums = nums;
	}

	int sumRange(int i, int j) {
		int x = 0;
		for (int k = i; k <= j; k++)
		{
			x += Nums[k];
		}
		return x;
	}
};

class NumArray2 {
	map<int, int> mp;
public:
	NumArray2(vector<int> &nums) {
		mp[-1] = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum+= nums[i];
			mp[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		
		return mp[j]-mp[i-1];
	}
};
class NumArray {
	vector<int> v;
public:
	NumArray(vector<int> &nums) {
		v = nums;
		for (int i = 1; i < nums.size(); i++)
		{
			v[i] += v[i - 1];
		}
	}

	int sumRange(int i, int j) {
		if (i < 0)
		{
			return 0;
		}
		else if (i == 0)
		{
			return v[j];
		}
		else
		{
			return (v[j] - v[i - 1]);
		}
	}
};