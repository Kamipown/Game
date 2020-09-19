#pragma once

#include <string>
#include <map>

using namespace std;

class Config
{
private:
	map<string, string> dictionnary;
	string path;

public:
	Config(void);
	~Config(void);

	void parse(string path);
	void insert(string key, string value);
	void log(void);
	void save(void);

	string get_string(string key);
	int get_int(string key);
	float get_float(string key);
	bool get_bool(string key);
};
