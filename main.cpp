#include "nucleic.h"
#include <iostream>
#include <fstream> //allows to read and write files

using namespace std;

int main (int argc, char** argv)
{
    //creates stream for writing to a file
    ofstream outf;
    outf.open("caffaro.out", ios::out);

    //stores command line argument
    string file_arg = argv[1];


    string nucleotides; // creates variable to store what is read from txt file
    string dnastring; // variable for temp storing of each line
    ifstream inf; //creates an in stream for reading the file
    inf.open(file_arg); //opens the file for reading
    while (inf.peek()!=EOF){ //uses peek to return whether or not the file has a next line
        getline(inf,dnastring); //reads line and stores in variable dnastring
        nucleotides=nucleotides + "\n" + dnastring; //appends dnastring to nucleotides, variable for the whole file
    }

    inf.close(); //closes reading stream




    nucleic acid;  //declare an instance of object nucleic

    outf << "Vinny Caffaro\n2298196\nCPSC 350-01" << "\n" <<endl;
    outf << "The nucleotides in the file "<< file_arg <<" are: \n" << nucleotides << endl;
    outf << "The sum of nucleotides is: " << acid.sum(nucleotides) << "\nThe number of lines in the file is: " << acid.lineCounter(nucleotides) << endl;
    outf << "The mean of nucleotides per line is: " << acid.mean(nucleotides) << endl;
    outf << "The variance of nucleotides is: " << acid.variance(nucleotides) << ", and the standard deviation is: " << acid.deviation(nucleotides) << endl;
    outf << acid.probability(nucleotides) << endl;



    //randomly generates 1000 strings to append
    for(int i = 0; i<1000; ++i)
    {
        string strand="";
        int strandLength = acid.genLength(nucleotides);


        for(int i = 0; i< strandLength; ++i)
        {
            string let = acid.genNucleotide();
            strand = strand+let;
        }


            outf << strand << endl;

    }

    cout << "Program exited successfully"<< endl;

    return 0;

    outf.close();



}
