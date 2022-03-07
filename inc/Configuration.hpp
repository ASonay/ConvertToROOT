#ifndef CONVCONF_HPP
#define CONVCONF_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Configuration{
  
public:
  
  Configuration(const char* name);
  ~Configuration();

  void Parser(int argc,char **argv);

  string GetNtupName() {return m_ntup;}
  string GetCSVName() {return m_csv;}

protected:

  string m_ntup;
  string m_csv;

private:
  string m_base_name;

};
#endif
