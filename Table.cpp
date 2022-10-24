#include <algorithm>
#include "Table.h"

// Выделение памяти под таблицу
Table* Table::Init(int size) {
	Table* t = new Table;
	t->size = size;
	t->m = new Client * [size];
	t->last = NULL;
	return t;
}

// Ввод таблицы
int Table::Input() {
	for (int i = 0; i < size; i++) {
		m[i] = new Client;
		m[i]->input();
	}
	return !std::cin.eof();
}

// TODO: Выводить номер клиента и разделители между клиентами
// Вывод таблицы
void Table::Output() {
	bool flag = false;
	for (int i = 0; i < size; i++) {
		m[i]->output();
		flag = true;
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const Client& tempClient) {
	for (int i = 0; i < size; i++) {
		if (m[i]->equal(tempClient))
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
		delete[] m[index]->name;
		delete m[index];

		m[index] = newClient;

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
		delete[] m[index]->name;
		delete m[index];
		m[index] = NULL;
		for (int i = index; i < size - 1; i++) {
			m[i] = m[i + 1];
		}
		size--;
		index = Search(badClient);
	}
	m = Resize(m, size);
}
