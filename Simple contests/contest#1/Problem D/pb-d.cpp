#include<iostream>
#include<vector>
#include<string>
using namespace std;
int* Addexeption(char* a, char* b, int no_exep);
string MyCompare(string x, string y, int* p, int size);
int main()
{
	char exe1[8] = { 'b','b','i','i','B','B','I','I'};
	char exe2[8] = { 'p','P','e','E','P','p','E','e'};
	int* p_exe = Addexeption(exe1, exe2, 8);
	unsigned short n;
	cin >> n;
	string* run = new string[n*2];
	
	for (int i = 0;i < n*2;i++)  //input is feed here
	{
		string test1, test2;
		
		cin >> test1;
		run[i] = test1;
		cin.ignore();
		cin >> test2;
		run[i+1] = test2;
		i++;
		
	}
	for (int i = 0;i < n*2;i+=2)
	{
		
		string result = MyCompare(run[i], run[i+1], p_exe, 8);
		cout << result << endl;
	}
	delete[]run;
	
	return 0;
}
string MyCompare(string x, string y,int*p,int size) 					//this pointer is to add a custom exeption list in main func for compare 
{											// where u will enter for example x  = "b p" this means that b===p (case equality) will be true
	string result = "Yes";								// assumed size of list is 2 characters or size of exeption list
	bool test1 = 0, test2 = 0;
		if (x.length() != y.length())
		{
			result = "No";
			//cout << "because of length mismatch" << endl;
			return result;
		}
		else
		{
			for (int i = 0;i < x.length();i++)
			{
				if (abs(int(x[i]) - int(y[i])) == 32)
				{
					test1 = 1;
					//cout << "case upper lower caught at" << x[i] << "and" << y[i] << endl;
				}
				for (int j = 0;j <size;j++)
				{
					if (abs(int(x[i]) -int( y[i])) == p[j])
					{
						test2 = 1;
						//cout << "exeption is caught at " << x[i] << " and " << y[i] << endl;
						if (!(test1 | test2))
						{
							result = "No";
							return result;
						}
					}
				}
				if (int(x[i]) - int(y[i]) != 0&&!(test2|test1))
				{
					result = "No";
					return result;
				}
				test1 = 0;
				test2 = 0;
			}
		}
		return result;
}
int* Addexeption(char*a, char *b,int no_exep)      // will return pointer to an array of ascii difference between i/p(s)
{
	int* p = new int[no_exep];
	
	for (int i = 0;i < no_exep;i++)
	{
		p[i] = abs(int(a[i]) - int(b[i]));
	}
	return p;
}
