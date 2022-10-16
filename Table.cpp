#include <algorithm>
#include "Table.h"

// Выделение памяти под таблицу
Client** Table::Init(int size) {
	Client** arr = NULL;
	arr = new Client * [size];
	return arr;
}

// Ввод таблицы
int Table::Input() {
	for (int i = 0; i < size; i++) {
		T[i] = new Client;
		T[i]->input();
	}
	return !std::cin.eof();
}

// TODO: Выводить номер клиента и разделители между клиентами
// Вывод таблицы
void Table::Output() {
	bool flag = false;
	for (int i = 0; i < size; i++) {
			T[i]->output();
			flag = true;
		}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (T[i]->cmp(*T[j]) > 0)
				std::swap(T[i], T[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const Client& tempClient) {
	for (int i = 0; i < size; i++) {
		if (T[i]->equal(tempClient))
			return i;
	}
	return -1;
}

// Замена клиента в таблице
void Table::Replace(Client* newClient) {
	// Запрос старого клиента
	std::cout << std::endl << "Enter old client: " << std::endl;
	Client oldClient;
	oldClient.input();

	// Поиск и замена
	int index = Search(oldClient);
	while (index != -1) {
		delete[] T[index]->name;
		delete T[index];

		T[index] = newClient;

		index = Search(oldClient);
	}
}

// Пересоздаёт таблицу после удаления клиентов
Client** Resize(Client** myTable, int newsize) {
	Client** arr = NULL;
	arr = new Client * [newsize];
	for (int i = 0; i < newsize; i++) {
		arr[i] = new Client;
		arr[i] = myTable[i];
	}
	return arr;
}

// Удаление всех вхождений
void Table::Remove(Client& badClient) {
	int index = Search(badClient);
	while (index != -1) {
		delete[] T[index]->name;
		delete T[index];
		T[index] = NULL;
		for (int i = index; i < size - 1; i++) {
			T[i] = T[i + 1];
		}
		size--;
		index = Search(badClient);
	}
	T = Resize(T, size);
}
