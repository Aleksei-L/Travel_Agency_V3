#include "Table.h"

int main() {
	Table myT;

	myT.size = 3; // TODO: ѕродумать задание размера пользователем
	myT.T = myT.Init(myT.size);

	myT.Input();
	std::cout << std::endl;
	myT.Sort();
	std::cout << std::endl;
	myT.Output();
	std::cout << std::endl;

	std::cout << "Enter new client for Replace:" << std::endl;
	Client one;
	one.input();
	myT.Replace(&one);

	std::cout << std::endl;
	myT.Output();

	return 0;
}
