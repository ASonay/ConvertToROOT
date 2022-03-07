#include "inc/Converter.hpp"
#include "inc/Common.hpp"


Converter::Converter(const char *name) : Configuration(name)
{}
Converter::~Converter()
{}

void
Converter::CloseFile()
{

  m_ttree->Write();
  m_tfile->Write();

  m_ttree.reset();
  
  cout << "Closing file.." << endl;

  m_tfile->Close("R");

}

void
Converter::SetCSV(const char *name)
{
  const string fileName(name);

  string line;
 
  m_csv_stream.reset(new fstream(fileName, ios::in));

  if(!m_csv_stream->is_open()) {
    cout << "Can't find the CSV file " << fileName << endl;
    exit(0);
  }

  getline(*m_csv_stream.get(), line);

  m_variables = Common::StringSep(line,',');

  cout << "\nVariables will be filled" << endl;
  for (auto & var : m_variables) {
    var = "v_"+Common::RemoveSpecialChars(var);
    cout << var << endl;
  }

  b_csv = true;
}


void
Converter::SetFile(const char *name)
{
  if (!b_csv){
    cout << "Please set your CSV file first by SetCSV(file.csv)" << endl;
    exit(0);
  }
  
  const string base_name = "tr";
  int total_variables = m_variables.size();
  const int nov = total_variables;
  
  m_tfile.reset(new TFile(name,"recreate"));
  m_var_rec.reset(new Double_t[nov]);
  m_ttree.reset(new TTree(base_name.c_str(),"TTree converted from the CSV file"));

  int counter=0;
  for (auto const &var : m_variables){
    m_ttree->Branch(var.c_str(),&m_var_rec[counter],(var+"/D").c_str());
    counter++;
  }
  b_file = true;
}

void
Converter::SetEvents()
{  
  if (!b_file){
    cout << "Please set your CSV and Ntuple files first by SetCSV(file.csv) and SetFile(ntup.root)" << endl;
    exit(0);
  }
  
  string line;
  while(getline(*m_csv_stream.get(), line)) {
    vector<float> vars = Common::StringSepFloat(line,',');
    int counter=0;
    for (auto var : vars) {
      m_var_rec[counter]=var;
      counter++;
    }
    m_ttree->Fill();
  }
  m_csv_stream->close();
}
