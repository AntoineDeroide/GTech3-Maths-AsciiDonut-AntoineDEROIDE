#pragma once

#include <string>
#include <vector>

using namespace std;

class File
{
public:
	// Static method to return a 50x50 array with characters to print
	static vector<vector<char>> GenerateArray(File* _pFile, unsigned int _rowLength = 50, unsigned int _colLength = 50);
	static vector<vector<char>> GenerateArray(std::string _input, unsigned int _rowLength = 50, unsigned int _colLength = 50);

	File(std::string path = "");

	std::string Read();

	bool Save(std::string path, File** dst);
	
	void SetPath(std::string path) { m_path = path; };
	
	int Size();
	bool IsOpen();

private:
	std::string m_path;

	fstream* m_pFile;
	unsigned int m_cursor;
	bool m_isOpen;
	
	bool Open();
	void Close();
};