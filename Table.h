#pragma once
#include <string.h>
#include "Client.h"

struct Table {
	int size; // Размер таблицы
	Client** m; // Таблица клиентов
	Client** current; // Указатель на первый свободный в таблице
	Table* Init(int size);
	void Resize(int newsize);
	Client* Copy(Client client);
	Client** Insert(Client newClient);
	int Input();
	void Output();
	void Sort();
	int Search(const Client& tempClient);
	void Replace(Client* newClient);
	void Remove(Client& badClient);
};
