#include "nucleic.h"
#include <iostream>
#include <fstream>

int main (int argc, char** argv)
{

    using namespace std;
    string f = "";
    cout<<"Enter the name of your file"<<endl;
    cin>>f;
    nucleic acid;



    cout << "Number of command line arguments: " <<argc <<endl;
    cout << "The nucleotides in the file "<< f << " are: \n" << acid.countNucleotides(f) << endl;
    cout << "argc is : " << argc << endl;

    cout << "Program exited successfully" << endl;

    return 0;



}
