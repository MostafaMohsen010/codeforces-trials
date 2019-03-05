#include<iostream>
#include<vector>

using namespace std;
struct test_case
{
	int final_result = 1500;
	int* p_sub_score = NULL;
	int size = 0;
};

int main()
{
	unsigned short n = 0; //getting no of test cases
		cin >> n;
		test_case* p = new test_case[n];
		string result = "NO";

		for (int i = 0;i < n;i++)  //input is fed here
		{
			unsigned short trials = 0;
			cin >> trials;
			cin.ignore();
			unsigned short final_score = 0;
			cin >> final_score;
			p[i].final_result = final_score;
			p[i].p_sub_score = new int[trials];
			p[i].size = trials;
			for ( int j = 0;j < trials;j++)
			{
				int temp;

				cin >> temp;
				cin.ignore();
				p[i].p_sub_score[j] = temp;
			}
			//cout << "===============end of test [" << i +1<<"] ========================="<< endl;
		}
		
		for (int i = 0;i < n;i++)		// input is procecssed here
		{
			unsigned short final_score = 1500;
			for ( int j = 0 ;j < p[i].size;j++)
			{
				final_score += p[i].p_sub_score[j];
			}
			//cout << "final score [" << i+1 << " ] " << final_score<<endl;
			if(p[i].final_result==final_score)
			{
				result = "Correct";
			}
			else
			{
				result = "Bug";
			}
			cout << result<<endl;
		}
		delete[]p;
		
	return 0;
}