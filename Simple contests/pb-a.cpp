#include<iostream>
#include<vector>
using namespace std;
int main()
{
	unsigned int n = 0; //getting no of elements in vector
		cin >> n;
		//int test_id = 1;
		
		string result = "NO";
		vector <int> input_ele;
		
		
		for (unsigned int i = 0;i < n;i++)  //input is feed here
		{
			int temp;
			cin >> temp;
			input_ele.push_back(temp);
		}
		for (unsigned int i = 0;i < n;i++)
		{
			for (unsigned int j = i+1;j < n;j++)
			{
				if (input_ele[i] == input_ele[j])
				{
					result = "YES";
					cout << result;
					return 0;
				}
			}
		}
		cout << result;
	return 0;
}