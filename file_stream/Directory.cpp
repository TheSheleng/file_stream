#include "Directory.h"

void drctr::Directory::save(Record _r)
{
	ofstream save(Notebook, ios::app);
	save << _r.film << endl
	 	 << _r.owner << endl
	  	 << _r.number << endl
		 << _r.adress << endl
		 << _r.occupation << endl
		 << endl;
	save.close();
}

void drctr::Directory::fillByGet(Record& _a, ifstream& _s)
{
	getline(_s, _a.film);
	if (_a.film == "") throw "EOF str";

	getline(_s, _a.owner);
	getline(_s, _a.number);
	getline(_s, _a.adress);
	getline(_s, _a.occupation);
}

void drctr::Directory::print()
{
	Record temp;
	ifstream r(Notebook);
	do
	{
		try { fillByGet(temp, r); }
		catch (...) { continue; }
		temp.print();

	} while (!r.eof());
	r.close();
}

void drctr::Directory::findByFilm(const string& _n)
{
	Record temp;
	ifstream r(Notebook);

	do
	{
		try { fillByGet(temp, r); }
		catch (...) { continue; }
		
		if (temp.film == _n) temp.print();
	} while (!r.eof());
	r.close();

	r.close();
}

void drctr::Directory::findByOwner(const string& _n)
{
	Record temp;
	ifstream r(Notebook);

	do
	{
		try { fillByGet(temp, r); }
		catch (...) { continue; }

		if (temp.owner == _n) temp.print();
	} while (!r.eof());
	r.close();
}

void drctr::Directory::findByOccupation(const string& _n)
{
	Record temp;
	ifstream r(Notebook);

	do
	{
		try { fillByGet(temp, r); }
		catch (...) { continue; }

		if (temp.occupation == _n) temp.print();
	} while (!r.eof());
	r.close();
}

drctr::Record::Record(string _f, string _ow, string _n, string _a, string _oc)
{
	film = _f;
	owner = _ow;
	number = _n;
	adress = _a;
	occupation = _oc;
}

void drctr::Record::print()
{
	cout << "Film: " << film << endl
		 << "Owner: " << owner << endl
		 << "Number: " << number << endl
		 << "Adress: " << adress << endl
		 << "Occupation: " << occupation << endl
		 << endl;
}