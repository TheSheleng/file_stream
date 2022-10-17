#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace drctr
{
	struct Record
	{
		string film;
		string owner;
		string number;
		string adress;
		string occupation;

		Record() = default;
		Record(string _f, string _ow, string _n, string _a, string _oc);
		void print();
	};

	class Directory
	{
		const string Notebook;

	public:
		Directory(const string _path) : Notebook(_path) {}

		void save(Record _r);
		void fillByGet(Record& _a, ifstream& _s);
		void print();

		void findByFilm(const string& _n);
		void findByOwner(const string& _n);
		void findByOccupation(const string& _n);
	};
}

