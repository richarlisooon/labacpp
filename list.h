#pragma once
#include "mitech.h"
class List {
private:
	int n;
	MiTech* arr;
public:
	~List();
	void create(MiTech* arr, int n);
	void write(MiTech* arr, int n);
	MiTech* load(int n);
	void add(MiTech* arr, int n);
	void remove(int id);
	void edit(int id);
	void search(int k);
};
