#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

int main()
{
	int count = 0;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = chrono::steady_clock:now();

	while (count < 100)
	{
		count++;
		cout << count << endl;


		chrono::steady_clock::duration dur = end - start;
		int duration_ms = chrono::duration_cast<chrono::milliseconds>(dur).count();


		if (duration_ms > 1000)
		end = chrono::steady_clock::now();
	
	}


}