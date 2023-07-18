#include "Logg.h"

Logg::Logg(const string& fileName) :_fileName(fileName)
{
	_fs.open(_fileName, fstream::in | fstream::out | fstream::app); 

	if (_fs.is_open()) 
		this->_status = true;
}
Logg::~Logg()
{
	_fs.close(); 
}
bool Logg::setLog(const string& from, const string& to, const string& messag)
{
	string sendText = "From:_" + from + "_to:_" + to + "_message:_" + messag;
	if (this->_status == true)
	{
		_m.lock();
		_fs << sendText;
		_fs << endl;
		_m.unlock();
		return true;
	}
	return false;
}

void Logg::getLog()
{
	string text = " ";
	if (this->_status == true)
	{
		_m.lock();
		while (!_fs.eof())
		{
			_fs >> text;
			cout << text << endl;
		}
		_m.unlock();
	}
}

const string Logg::getFileName() const
{
	return _fileName;
}