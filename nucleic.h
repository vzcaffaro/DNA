#include <iostream> //preproccessor directive

using namespace std;

class nucleic{
    public:
    nucleic(); //constructor
    ~nucleic(); //destructor
    int sum(string nucleotides);
    double mean(string nucleotides);
    double lineCounter(string nucleotides);
    double total(string nucleotides);
    double variance(string nucleotides);
    double deviation(string nucleotides);
    string probability(string nucleotides);
    string genNucleotide();
    int genLength(string nucleotides);
};
