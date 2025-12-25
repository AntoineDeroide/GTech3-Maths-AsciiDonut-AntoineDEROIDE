#include "File.h"
#include <fstream>
#include <iostream>

File::File(std::string _path) : 
	m_pFile(nullptr),
	m_path(_path), 
	m_cursor(0),
	m_isOpen(false)
{
	// code...
}

bool File::Open()
{
	if (m_path == "")
		return false;

	m_pFile->open("file.txt", ios::in);
	
	if (m_pFile->is_open() == false)
	{
		cout << "Failed to open following file : " << m_path << "\n";

		return false;
	}

	// cout << "File " << fileName << " succesfully opened !" << std::endl;
	
	return true;
}

void File::Close()
{
	m_pFile->close();
}

std::string File::Read()
{
	string toReturn;

	(*m_pFile) >> toReturn;

	return toReturn;
}

/// <summary>
/// Saves the current file's content into a destination file, which represents the save
/// </summary>
/// <param name="path">the path to the save</param>
/// <param name="dst">[out] A handle to the save</param>
/// <returns>Returns true if the save was a success</returns>
bool File::Save(std::string path, File** dst)
{
	cout << "Saving file...\n";

	if (Open() == false and m_isOpen == false)
	{
		cout << "Failed to save following file : " << m_path << " | File was not open\n";
		return false;
	}
	
	fstream save(path, ios::out);
	
	save << Read();

	File* out = new File(path);
	out->m_pFile = &save;

	dst = &out;
	
	cout << "Succesfully saved file "<< m_path << "\n";

	return true;
}

int File::Size() 
{
	if (!m_isOpen)
		Open();

	m_pFile->seekg(ios::end);

	return (int)m_pFile->tellg();
}

bool File::IsOpen()
{
	return m_isOpen;
}
