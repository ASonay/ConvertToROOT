
#include <map>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

#include "inc/Converter.hpp"

using namespace std;
int main(int argc,char **argv)
{

  auto conv = make_unique<Converter>("CSVtoROOT");

  conv->Parser(argc,argv);

  conv->SetCSV(conv->GetCSVName().c_str());
  conv->SetFile(conv->GetNtupName().c_str());
  conv->SetEvents();
  conv->CloseFile();
  
}
