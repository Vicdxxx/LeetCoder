#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;
class Solution {
	vector<int> Coins;
	vector<int> tmp;
	bool valid;
	vector<int> idx;
	int num;
public:
	//228
	vector<string> summaryRanges(vector<int>& nums) {
		int idx = 0;
		int i = 0;
		vector<string> answer;

		while (i+1<=nums.size())
		{
			if (i + 1 < nums.size())
			{
				while (nums[i + 1] - nums[i] == 1)
				{
					i++;
					idx++;
				}
				int a1 = nums[i] - idx;
				int a2 = nums[i];
				if (idx <= 0)
				{

					stringstream s1;
					s1 << a1;
					string x = s1.str();
					answer.push_back(x);
					i++;
				
				}
				else
				{
					stringstream s1, s2;
					s1 << a1;
					s2 << a2;
					string x = s1.str() + "->" + s2.str();
					answer.push_back(x);
					i++;
				}
				idx = 0;
			}
			else
			{
				stringstream s2;
				s2 << nums[i];
				string x2 = s2.str();
				answer.push_back(x2);
				i++;
			}
			
		}
		return answer;
	}
	//242
	bool isAnagram2(string s, string t) {
		if (s.size() != t.size())
		{
			return false;
		}
		vector<int> count(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++)
		{
			count[t[i] - 'a']--;
		}
		for (int i = 0; i < t.size(); i++)
		{
			if(count[i]!=0)
				return false;
		}
		return true;

	}
	bool isAnagram1(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;

	}
	bool isAnagram(string s, string t) {
		if (s.size()!=t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == t[i])
			{
				continue;
			}
			else
			{
				int idx = 0;
				for (int j = 0; j < t.size();j++)
				{
					if (s[i] == t[j] &&s[j]==t[i])
					{
						idx = 1;
					}
				}
				if (idx < 1)
				{
					return false;
				}
			}
		}
		return true;
	}
	vector<string> addOperators(string num, int target) {
		int a=(int)num[0];


	}
	int coinChange2(vector<int>& coins, int amount) {
		if (amount<0)
		{
			return -1;
		}
		vector<int> tot(amount + 1, amount + 1);
		tot[0] = 0;
		for (int money_tot = 1; money_tot <= amount; money_tot++)
		{
			for (int i = 0; i < coins.size(); i++)
			{
				if (money_tot>=coins[i])
				{
					tot[money_tot] = tot[money_tot - coins[i]] + 1 < tot[money_tot] ?
						tot[money_tot - coins[i]] + 1 : tot[money_tot];
				}
			}
		}
		return tot[amount] == amount + 1 ? -1 : tot[amount];
	}
	int coinChange1(vector<int>& coins, int amount) {
		if (amount < 0) return -1;
		vector<int> cnt(amount + 1, amount + 1);
		cnt[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j<coins.size(); ++j) {
				if (i >= coins[j]) {
					cnt[i]>cnt[i - coins[j]] + 1?
						cnt[i] = cnt[i - coins[j]] + 1:	cnt[i]= cnt[i];
				}
			}
		}
		return (cnt[amount] == amount + 1) ? -1 : cnt[amount];
	
	}

	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
		{
			return 0;
		}
		num = 0;
		tmp.resize(coins.size(), 0);
		idx.resize(coins.size(), 0);

		Coins = coins;
		valid = false;
	
		for (int i = 0; i < coins.size(); i++)
		{
			tmp[i]=amount - coins[i];
			tozero(tmp[i]);
			++idx[num];
		}

		if (valid==false)
		{
			return -1;
		}
		else
		{
			for (int i = 1; i < idx.size(); i++)
			{
				if (idx[i] < idx[i - 1])
				{
					int tmp = idx[i];
					idx[i] = idx[i - 1];
					idx[i - 1] = tmp;
				}
			}
			return idx[0];
		}
	}
	void tozero(int x)
	{
		if (x<0)
		{
			return;
		}
		if (x == 0)
		{
			valid = true;
			num++;
			if (num>idx.size()-1)
			{
				idx.resize(2 * idx.size());
			}
		}
			
		for (int i = 0; i < Coins.size(); i++)
		{
			tmp[i] = x - Coins[i];
			tozero(tmp[i]);
			++idx[num];
		}
	}
};
void main()
{
	vector<int> coins(3,9);
	coins[0] = 0;
	coins[1] = 1;

	for (int i = 0; i < coins.size(); i++)
		cout << coins[i] << " ";
	cout << endl;
	Solution s = Solution();
	//int x = s.coinChange(coins,3);
	vector<string> xs = s.summaryRanges(coins);
	for (int i = 0; i < xs.size();i++)
		cout << xs[i]<<" ";
	cin.get();
	cin.get();

}