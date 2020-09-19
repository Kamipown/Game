#include "engine/Config.hpp"

#include <iostream>
#include <fstream>

Config::Config(void)
{
	this->dictionnary["window_fullscreen"] = "false";
	this->dictionnary["window_width"] = "1920";
	this->dictionnary["window_height"] = "1080";
}

Config::~Config(void)
{
}

static string trim(const string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r\v\f");
	if (first == std::string::npos)
		return ("");
	size_t last = str.find_last_not_of(" \t\n\r\v\f");
	return (str.substr(first, (last - first + 1)));
}

void Config::parse(string path)
{
	string line;
	ifstream file;

	this->path = path;
	file.open(this->path);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			size_t pos = line.find('=');
			if (pos > 0 && pos < line.length())
			{
				string key, value;
				key = line.substr(0, pos);
				value = line.substr(pos + 1, line.length());
				this->insert(key, value);
			}
		}
		file.close();
	}
	else
		cerr << "Unable to open the configuration file. Path: \"" << path << "\" Errno: " << errno << endl;
}

void Config::insert(string key, string value)
{
	string k = trim(key);
	string v = trim(value);

	if (k.length() && v.length())
	{
		this->dictionnary[k] = v;
	}
}

void Config::log(void)
{
	map<string, string>::iterator it;

	for (it = this->dictionnary.begin(); it != this->dictionnary.end(); it++)
		cout << it->first << ' ' << it->second << endl;
}

void Config::save(void)
{
	ofstream file;

	file.open(this->path);
	if (file.is_open())
	{
		map<string, string>::iterator it;
		for (it = this->dictionnary.begin(); it != this->dictionnary.end(); it++)
			file << it->first << " = " << it->second << endl;
		file.close();
	}
	else
		cerr << "Unable to open the configuration file. Path: \"" << path << "\" Errno: " << errno << endl;
}

string Config::get_string(string key)
{
	return (this->dictionnary[key]);
}

int Config::get_int(string key)
{
	return (stoi(this->dictionnary[key]));
}

float Config::get_float(string key)
{
	return (stof(this->dictionnary[key]));
}

bool Config::get_bool(string key)
{
	string value = this->dictionnary[key];
	return (value == "true" || value == "TRUE" || value == "1");
}
