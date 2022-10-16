#pragma once
#include <string.h>
#include "Client.h"

struct Table {
	int size; // Размер таблицы
	Client** T; // Таблица клиентов
	Client** Init(int size);
	int Input();
	void Output();
	void Sort();
	int Search(const Client& tempClient);
	void Replace(Client* newClient);
	void Remove(Client& badClient);
};
