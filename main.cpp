#include <iostream>
#include <Windows.h>
#include "Logg.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		Logg log = Logg("Log.txt");
		char oper;
		string from = " ", to = " ", mess = " ";
		cout << " w - write, r - read, q - exit " << endl;
		cin >> oper;
		cout << endl;

		if (oper == 'q')
			break;

		switch (oper)
		{
		case 'w':
			SetConsoleCP(1251);
			cout << "From: ";
			cin >> from;
			cout << "To: ";
			cin >> to;
			cout << "Message text: ";
			cin >> mess;
			cout << endl;
			if (log.setLog(from, to, mess))
				cout << "Record added!" << endl;
			SetConsoleCP(866);
			cout << " ----------- " << endl;
			break;
		case 'r':
			cout << "Reading file data " << log.getFileName() << ": " << endl;
			log.getLog();
			break;
		}
	}
	return 0;
}