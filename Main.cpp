#include "Table.h"

int main() {
	Table* myT = new Table;

	// TODO: ѕродумать задание размера пользователем
	myT = myT->Init(3);

	myT->Input();
	std::cout << std::endl;
	myT->Sort();
	std::cout << std::endl;
	myT->Output();
	std::cout << std::endl;

	/*std::cout << "Enter new client for Remove:" << std::endl;
	Client one;
	one.input();
	myT.Remove(one);

	std::cout << std::endl;
	myT.Output();*/

	return 0;
}
