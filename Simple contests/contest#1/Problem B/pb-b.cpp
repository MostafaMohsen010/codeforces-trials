#include<iostream>
#include<vector>

using namespace std;
bool isequal(int x, int y);
int main() {
	
	unsigned int n = 0; //getting no of elements in vector
	cin >> n;
	int test_id = 1;
	
	string result = "NO";
	vector <int> input_ele;
	
	
	for (unsigned int i = 0;i < n;i++)  //input is feed here
	{
		int temp;
		cin >> temp;
		input_ele.push_back(temp);
	}
	
	if (n < 3)
	{
		bool check1 = isequal(input_ele[test_id], input_ele[test_id - 1]);
		if (check1)
			result = "YES";
		cout << result;
		return 0;
	}
	for (unsigned int i = 0;i < n/2;i++)
	{
		if (test_id != n-1)
		{
			bool check1 = isequal(input_ele[test_id], input_ele[test_id - 1]);

			bool check2 = isequal(input_ele[test_id], input_ele[test_id + 1]);
			if (check1 | check2)
			{
				result = "YES";
				break;
			}
		}
		else {
			bool check1 = isequal(input_ele[test_id], input_ele[test_id - 1]);
			if (check1)
			{
				result = "YES";
				break;
			}
		}
		test_id += 2;
		
	}
	cout << result;
	return 0;
}
bool isequal(int x, int y)
{
	bool temp;
	(x == y) ? temp= 1 : temp= 0;
	return temp;
}
