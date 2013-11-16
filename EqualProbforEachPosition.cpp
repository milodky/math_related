#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <exception>
#include <algorithm>
using namespace std;

vector<int> split(int Num, int Amount)
{
	if (Num <= 0)
		throw exception();

	vector<int> splash_position(Amount + 1, 0);
	for (int i = 1; i < Amount; i++)
		splash_position[i] = rand() % (Num + 1);
	splash_position[Amount] = Num;
	sort(splash_position.begin(), splash_position.end());
	vector<int> ret(Amount);
	for (int i = 0; i < Amount; i++)
		ret[i] = splash_position[i + 1] - splash_position[i];

	return ret;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);

	int Amount = atoi(argv[2]);
	srand(time(NULL));
	vector<int> ret = split(Num, Amount);
	for (int i = 0; i < Amount; i++)
		cout << ret[i] << " ";
	cout << endl;
	return 1;
}
