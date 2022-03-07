#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <thread>

#include "TTree.h"
#include "TFile.h"
#include "TChain.h"

#include "inc/Configuration.hpp"

using namespace std;

class Converter : public Configuration {
  
public:
  Converter(const char *name);
  ~Converter();
  void CloseFile();
  
  void SetCSV(const char *name);
  void SetFile(const char *name);
  void SetEvents();

private:
  vector<string> m_variables;

  string first_row;
  
  unique_ptr<Double_t[]> m_var_rec;
  
  unique_ptr<TTree> m_ttree;
  unique_ptr<TFile> m_tfile;
  unique_ptr<TChain> m_tchain;

  unique_ptr<fstream> m_csv_stream;

  bool b_csv{0};
  bool b_file{0};


};
#endif
