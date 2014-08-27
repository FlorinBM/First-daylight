#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "inainte de fork\n";
	int a = 0;

	int pid = fork();

	if (pid > 0) {
		while (true)
			a ++;
	} else {
		while (true)
			cout << a << "\n";
	}
	return 0;
}