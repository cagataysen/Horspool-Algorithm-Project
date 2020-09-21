#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;

unsigned int HorsePool(string);

//Timer
clock_t startTime, endTime;



int main() {
	
	string fileName1 = "C:\\the_truman_show_script.txt";
	ifstream file1;
	string line1;

	file1.open(fileName1);
	while (file1 >> line1)
	{
		getline(file1, line1);
		transform(line1.begin(), line1.end(), line1.begin(), ::tolower);
	}


	vector<char> v1(line1.begin(), line1.end());

	string fileName2 = "C:\\statements.txt";
	ifstream file2;
	string line2;

	file2.open(fileName2);
	while (file2 >> line2)
	{
		getline(file2, line2);
		transform(line2.begin(), line2.end(), line2.begin(), ::tolower);

	}

	vector<char> v2(line2.begin(), line2.end());
	file2.close();

	int index;
	index = HorsePool(line1);
	time_t srand(time(NULL));
	startTime = clock();
	if (index >= 0)
	{
		cout << "FOUND AT " << index << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	endTime = clock();
	double diff((double)((float)endTime - (float)startTime) / 1000);
	cout << "\n\n    Total Second : " << diff << "\n\n" << endl;
	system("PAUSE");
	
	return 0;
}

unsigned int HorsePool(string line1) {
	// input string pattern
	string line2;
	cout << "Input the sentence =" << endl;
	cin.ignore();
	getline(cin, line2);


	//creating a shifting table	
	int const n = 256;
	int Table[n];
	int m = line2.length();    //m = pattern size
	int i = 0;
	for (i = 0; i <= n - 1; i++)
	{
		Table[i] = m;
	}
	int j = 0;
	for (j = 0; j <= m - 2; j++)
	{
		int d = (int)line2[j];
		Table[(int)line2[j]] = m - 1 - j;
	}
	//shifting table created on above

	int n1 = line1.length();  
	i = m - 1;			
	while (i < n1)        
	{
		int k = 0;

		while (k < m && line2[m - 1 - k] == line1[i - k])
		{
			k = k + 1;
		}

		if (k == m)
		{
			return i - m + 1;
		}
		else
		{
			i = i + Table[line1[i]];
		}

	}

	return -1;

}
