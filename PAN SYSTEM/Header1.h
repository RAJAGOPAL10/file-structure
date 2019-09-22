#pragma once

#include <fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
std::string index[50], indexadd[50];
int nor;
void smi()
{
	std::string temp, temp1;
	int a, b,t;
	char sadd[50];
	for (int i = 0; i < nor; i++)
	{
		for (int j = i + 1; j < nor; j++)
		{
			if (strcmp(index[i].c_str(), index[j].c_str()) > 0)
			{
				temp = index[i];
				index[i] = index[j];
				index[j] = temp;

				a = atoi(indexadd[i].c_str());
				b = atoi(indexadd[j].c_str());
				_itoa_s(a, sadd, 10);
				indexadd[j] = sadd;
				_itoa_s(b, sadd, 10);
				indexadd[i] = sadd;
				/*temp1 = indexadd[i];
				indexadd[i] = indexadd[j];
				indexadd[j] = temp;*/
			}
		}
	}
}

class stud
{
public:std::string acno, name, address, balance;
	   void unpack(int add);
	   void rewrite();
};

char* add(std::string x[])
{
	char buf[300], sadd[50];
	char* result = "INSERTION SUCESSFULL!!!";
	char* result1 = "UNSUCESSFULL!!!";
	for (int i = 0; i < nor; i++)
	{
		if (x[0].compare(index[i]) == 0)
		{
			return result1;
		}
	}
	strcpy_s(buf,100, x[0].c_str());
	strcat_s(buf, "|");
	strcat_s(buf,100, x[1].c_str());
	strcat_s(buf, "|");
	strcat_s(buf,100, x[2].c_str());
	strcat_s(buf, "|");
	strcat_s(buf,100, x[3].c_str());
	strcat_s(buf, "|");
	std::fstream f1("index.txt", std::ios::app);
	std::fstream f2("rec.txt", std::ios::app);
	f2.seekp(0, std::ios::end);
	index[nor] = x[0];
	_itoa_s(f2.tellp(), sadd, 10);
	indexadd[nor] = sadd;
	f1 << x[0].c_str() << '|' << f2.tellp() << '\n';
	f2 << buf;
	nor++;
	std::ofstream o("track",std::ios::trunc);
	o << nor;
	o.close();
	smi();
	f1.close();
	f2.close();
	return result;
}
char* Search(std::string acno)
{
	smi();
	stud s;
	char* result = new char[500];
	int max = nor - 1, min = 0, flag = 0, add, mid;
	while (min <= max && flag == 0)
	{
		mid = (min + max) / 2;
		if (strcmp(acno.c_str(), index[mid].c_str()) == 0)
		{
			flag = 1;
			add = atoi(indexadd[mid].c_str());
			s.unpack(add);
			strcpy_s(result, 25, "");
			strcat_s(result, 500, "      PAN     ");
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, "    NAME    ");
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, "   ADDRESS  ");
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, "     DOB    ");
			strcat_s(result, 500, "\r\n");
			strcat_s(result, 500, "---------------------------------------------------");
			strcat_s(result, 500, "--------------------------------------------\r\n");
			strcat_s(result, 500, acno.c_str());
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, s.name.c_str());
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, s.address.c_str());
			strcat_s(result, 500, "  \t");
			strcat_s(result, 500, s.balance.c_str());
			strcat_s(result, 500, "\n");
			
		}
		else
			if (strcmp(acno.c_str(), index[mid].c_str()) > 0)
				min = mid + 1;
			else
				max = mid - 1;
	}
	if (!flag)
		return "Not Found";
	return result;
}
void stud::unpack(int add)
{
	std::fstream f1("rec.txt", std::ios::in);
	f1.seekg(add);
	char* str = new char[30];
	f1.getline(str, 15, '|');
	acno = str;
	f1.getline(str, 15, '|');
	name = str;
	f1.getline(str, 15, '|');
	address = str;
	f1.getline(str, 15, '|');
	balance = str;
	f1.close();
}
int del(std::string c)
{
	stud s1;
	smi();
	std::fstream f1("index.txt", std::ios::out | std::ios::trunc);
	int max = nor - 1, min = 0, flag = 0, add, mid;
	while (min <= max && flag == 0)
	{
		mid = (min + max) / 2;
		if (strcmp(c.c_str(), index[mid].c_str()) == 0)
		{
			flag = 1;
			for (int i = mid; i < nor; i++)
			{
				index[i] = index[i + 1];
				indexadd[i] =indexadd[i + 1];
			}
			nor--;
			std::ofstream o("track", std::ios::trunc);
			o << nor;
			o.close();
		}
		else
			if (strcmp(c.c_str(), index[mid].c_str()) > 0)
				min = mid + 1;
			else
				max = mid - 1;
	}
	for (int i = 0; i < nor; i++)
	{
		f1.write(index[i].c_str(), strlen(index[i].c_str()));
		f1.write("|", 1);
		f1.write(indexadd[i].c_str(), strlen(indexadd[i].c_str()));
		f1.write("\n", 1);
	}
	f1.close();
	s1.rewrite();
	if (!flag)
		return 0;
	return 1;
}
void stud ::rewrite() 
{
	std ::fstream f1("rec.txt", std::ios::in);
	std::fstream f2("record.txt", std::ios::app);
	std::fstream f3("index1.txt",std::ios::app);
	char* str = new char[30];
	char buf[300], sadd[50];
	int add;
	for (int i = 0; i < nor; i++)
	{
		add = atoi(indexadd[i].c_str());
		f1.seekg(add);
		f1.getline(str, 15, '|');
		acno = str;
		f1.getline(str, 15, '|');
		name = str;
		f1.getline(str, 15, '|');
		address = str;
		f1.getline(str, 15, '|');
		balance = str;
		strcpy_s(buf, 100, acno.c_str());
		strcat_s(buf, "|");
		strcat_s(buf, 100, name.c_str());
		strcat_s(buf, "|");
		strcat_s(buf, 100, address.c_str());
		strcat_s(buf, "|");
		strcat_s(buf, 100, balance.c_str());
		strcat_s(buf, "|");
		f2.seekp(0, std::ios::end);
		index[i] = acno;
		_itoa_s(f2.tellp(), sadd, 10);
		indexadd[i] = sadd;
		f3 << acno.c_str() << '|' << f2.tellp() << '\n';
		f2 << buf;
	}
	f1.close();
	f2.close();
	f3.close();
	remove("index.txt");
	remove("rec.txt");
	rename("index1.txt","index.txt");
	rename("record.txt", "rec.txt");
}
char* disp()
{
	stud s;
	int add;
	char* result = new char[3000];
	strcpy_s(result, 25, "");
	smi();

	strcat_s(result, 1000, "      PAN     ");
	strcat_s(result, 1000, "  \t");
	strcat_s(result, 1000, "    NAME    ");
	strcat_s(result, 1000, "  \t");
	strcat_s(result, 1000, "   ADDRESS  ");
	strcat_s(result, 1000, "  \t");
	strcat_s(result, 1000, "     DOB    ");
	strcat_s(result, 1000, "\r\n");
	strcat_s(result, 1000, "---------------------------------------------------");
	strcat_s(result, 1000, "--------------------------------------------\r\n");

	for (int i = 0; i < nor; i++)
	{
		add = atoi(indexadd[i].c_str());
		s.unpack(add);
		strcat_s(result, 1000, s.acno.c_str());
		strcat_s(result, 1000, "  \t");
		strcat_s(result, 1000, s.name.c_str());
		strcat_s(result, 1000, "  \t");
		strcat_s(result, 1000, s.address.c_str());
		strcat_s(result, 1000, "  \t");
		strcat_s(result, 1000, s.balance.c_str());
		strcat_s(result, 1000, "\r\n");
	}
	return result;
}

char* Search_m(std::string acno)
{
	smi();
	stud s;
	char* result = new char[500];
	int max = nor - 1, min = 0, flag = 0, add, mid;
	while (min <= max && flag == 0)
	{
		mid = (min + max) / 2;
		if (strcmp(acno.c_str(), index[mid].c_str()) == 0)
		{
			flag = 1;
			add = atoi(indexadd[mid].c_str());
			s.unpack(add);
			strcpy_s(result, 25, "");
			strcat_s(result, 500, "\r\nPAN : ");
			strcat_s(result, 500, acno.c_str());
			strcat_s(result, 500, "\r\n\r\nNAME : ");
			strcat_s(result, 500, s.name.c_str());
			strcat_s(result, 500, "\r\n\r\nADDRESS : ");
			strcat_s(result, 500, s.address.c_str());
			strcat_s(result, 500, "\r\n\r\nDOB : ");
			strcat_s(result, 500, s.balance.c_str());

		}
		else
			if (strcmp(acno.c_str(), index[mid].c_str()) > 0)
				min = mid + 1;
			else
				max = mid - 1;
	}
	if (!flag)
		return "Not Found";
	return result;
}
char* modify(std::string x[])
{
	char buf[300], sadd[50];
	char* result = "MODIFICATION SUCESSFULL!!!";
	char* result1 = "UNSUCESSFULL!!!";
	int f = del(x[0]);
	strcpy_s(buf, 100, x[0].c_str());
	strcat_s(buf, "|");
	strcat_s(buf, 100, x[1].c_str());
	strcat_s(buf, "|");
	strcat_s(buf, 100, x[2].c_str());
	strcat_s(buf, "|");
	strcat_s(buf, 100, x[3].c_str());
	strcat_s(buf, "|");
	std::fstream f1("index.txt", std::ios::app);
	std::fstream f2("rec.txt", std::ios::app);
	f2.seekp(0, std::ios::end);
	index[nor] = x[0];
	_itoa_s(f2.tellp(), sadd, 10);
	indexadd[nor] = sadd;
	f1 << x[0].c_str() << '|' << f2.tellp() << '\n';
	f2 << buf;
	nor++;
	std::ofstream o("track", std::ios::trunc);
	o << nor;
	o.close();
	smi();
	f1.close();
	f2.close();
	return result;
}