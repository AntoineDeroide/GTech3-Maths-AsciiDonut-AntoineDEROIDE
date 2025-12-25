#pragma once

#include <string>

using namespace std;

class File
{
public:
	File(std::string path = "");

	std::string Read();

	bool Save(std::string path, File** dst);
	
	void SetPath(std::string path) { m_path = path; };
	
	int Size(); // TODO
	bool IsOpen();

private:
	std::string m_path;

	fstream* m_pFile;
	unsigned int m_cursor;
	bool m_isOpen;
	
	bool Open();
	void Close();


};