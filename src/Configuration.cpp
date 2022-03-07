#include "inc/Configuration.hpp"

using namespace std;

Configuration::Configuration(const char *name):
  m_ntup("ntup.root"),
  m_csv("file.csv"),
  m_base_name(string(name))
{}

Configuration::~Configuration()
{}

void
Configuration::Parser(int argc,char **argv)
{

  string app_name = argv[0];
  string command = app_name+" --ntup <ntup.root> --csv <file.csv>";
  

  for (int i=1;i<argc;i++){
    string check = argv[i];
    //cout << check << endl;
    if (check=="--ntup")
      {m_ntup = argv[i+1];i++;}
    else if (check=="--csv")
      {m_csv = argv[i+1];i++;}
    else{
      cout << "Usage of the script :" << endl;
      cout << "Check here, " << check << endl;
      cout << command << endl;
      exit(0);
    }
  }

}
