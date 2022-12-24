#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class CustomConfig
{
private:
	std::vector<std::pair<std::string, std::string>> data;

	std::vector<std::string> split(const std::string& s, char delim) {
		std::vector<std::string> result;
		std::stringstream ss(s);
		std::string item;

		while (getline(ss, item, delim)) {
			result.push_back(item);
		}

		return result;
	}
	void fetchLine(std::string rawLine)
	{
		std::vector<std::string> strvec= split(rawLine, ':');
		if (strvec.size() > 1)
			data.push_back(std::make_pair(strvec[0], strvec[1]));
	}
public:
	CustomConfig()
	{

	}
	void writeData(std::string description, std::string value) //don't put ':' after description, adds automatically
	{
		//check if desc exists
		bool exist = false;
		for (int i = 0; i < data.size(); i++)
		{
			if (description == data[i].first)
			{
				exist = true;
				printf("Cant write, entered description already exists!");
				break;
			}
				
		}
		if (!exist)
			data.push_back(std::make_pair(description, value));
	}
	void saveToFile(std::string filename = "config.txt")
	{
		std::ofstream myfile(filename);

		if (myfile.is_open())
		{
			for (int i = 0; i < data.size(); i++)
			{
				std::string str;
				myfile << data[i].first + ":" << data[i].second << std::endl;
			}
			
			myfile.close();
		}
		
	}
	void printAllData()
	{
		for (int i = 0; i < data.size(); i++)
			std::cout << "Description: " << data[i].first << " Value: " << data[i].second << std::endl;
	}

	std::string getDataByDescrtiption(std::string description)
	{
		std::string retData;
		for (int i = 0; i < data.size(); i++)
		{
			if (description == data[i].first)
			{
				retData = data[i].second;
				break;
			}
		}
		if (retData.size() == 0)
			std::cout << "Couldn't find data with this description" << std::endl;
		return retData;
	}
	void readData(std::string filename = "config.txt")
	{
		std::ifstream infile(filename);
		std::string line;
		if (infile.is_open()) {
			while (infile) {
				std::getline(infile, line);
				//std::cout << line << std::endl;
				fetchLine(line);
			}
		}
		std::cout << "Read " << data.size() << " lines of data" << std::endl;
	}
};
