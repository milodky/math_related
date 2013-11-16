#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <list>
#include <cstddef>
using namespace std;

void swap(vector<int> &Array, int i, int j)
{
	int tmp = Array[i];
	Array[i] = Array[j];
	Array[j] = tmp;
}

vector<int> shuffle(int Num)
{
	if (Num <= 0)
		throw exception();	
	vector<int> holder(Num);

	for (int i = 0; i < Num; i++) {
		holder[i] = i;
		int Position = rand() % (i + 1);
		swap(holder, i, Position);
	}

	return holder;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	srand(time(NULL));
	vector<int> result = shuffle(Num);
	for (int i = 0; i < Num; i++)
		cout << result[i] << " ";
	cout << endl;
	return 1;
}

