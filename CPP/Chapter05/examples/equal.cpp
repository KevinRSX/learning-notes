#include <iostream>
int main()
{
	using namespace std;
	int quizscores[10] = { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

	for (int i = 0; quizscores[i] == 20; i++)
	{
		cout << "Quiz " << i << ", Mark: " << quizscores[i] << endl;
	}

	return 0;
}