#include "nucleic.h"
#include <fstream>
#include <iostream>

using namespace std;

nucleic::nucleic()
{

}
nucleic::~nucleic()
{
    cout << "object deleted" << endl;
}

string nucleic::countNucleotides(string file)
{
    int acount = 0;
    int gcount = 0;
    int ccoutn = 0;
    int tcount = 0;

    string nucleotides;
    string dnastring;
    ifstream inf;
    inf.open(file);
    while (inf.peek()!=EOF){
        getline(inf,dnastring);
        nucleotides=nucleotides + "\n" + dnastring;
    }
    return nucleotides;
    inf.close();
}
