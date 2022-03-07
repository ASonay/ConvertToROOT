The project is aiming to convert CSV file to ROOT's ntuples for the interactive analysis propose and the big data management with the low memory consumption.
Visit: https://root.cern/

The basic usage of the tool;

**Setup environment :**    
```
source setup.sh
```

**Compiling :**    
- First time: `converter-build`
- Recompile: `converter-make`
- Clean folder: `converter-clean`

**Running :**

```
CSVtoROOT --csv <file.csv> --ntup <ntup.root>
```