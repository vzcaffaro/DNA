#include "nucleic.h"
#include <fstream>
#include <iostream>
#include <cmath> //used to carry out math operations for statistics
#include <cstdlib> //includes rand operator

using namespace std;

double PI = 3.14159;
//initialize all counting variables to 0
double count = 0;
double lines = 0;

double acount = 0;
double gcount = 0;
double ccount = 0;
double tcount = 0;
double errorcount = 0;

double a_prob = 0;
double g_prob = 0;
double c_prob = 0;
double t_prob = 0;

double aa_count = 0;
double ag_count = 0;
double ac_count = 0;
double at_count = 0;

double aa_prob = 0;
double ag_prob = 0;
double ac_prob = 0;
double at_prob = 0;

double ga_count = 0;
double gc_count = 0;
double gg_count = 0;
double gt_count = 0;

double ga_prob = 0;
double gc_prob = 0;
double gg_prob = 0;
double gt_prob = 0;

double ca_count = 0;
double ct_count = 0;
double cg_count = 0;
double cc_count = 0;

double ca_prob = 0;
double ct_prob = 0;
double cg_prob = 0;
double cc_prob = 0;

double ta_count = 0;
double tg_count = 0;
double tc_count = 0;
double tt_count = 0;

double ta_prob = 0;
double tg_prob = 0;
double tc_prob = 0;
double tt_prob = 0;




nucleic::nucleic() //default constructor
{

}
nucleic::~nucleic() //default destructor
{
    cout << "object deleted" << endl;
}


int nucleic::sum(string nucleotides) //function for getting sum of nucleotides
{

    for (int i=0; i<nucleotides.size();++i) //loop through nucleotides variable that stores data from file
        {
            char letter= toupper(nucleotides[i]); //capitalizes all letters and stores in temporary variable called letter
            if(letter=='A' || letter=='G' || letter =='C' || letter == 'T') //only adds to count if letter is an A, C, T, or G
                ++count;
        }
    return count;

}

double nucleic::lineCounter(string nucleotides) //function for average nucleotides per line
{

    for (int i=0; i<nucleotides.size();++i)
        {
            if(nucleotides[i]=='\n')
                ++lines; //adds to int lines when new line detected
        }
    return lines;

}


double nucleic::mean(string nucleotides) //function for average nucleotides per line
{

    double av = count/lines; //calculates mean by dividing total count by number of lines
    return av;

}





double nucleic::total(string nucleotides) //function to calculate variance and standard deviation
{
    double av=mean(nucleotides); //calls mean function to calculate average
    double linecounter = 0; // variable for counting length of each line
    double difference; //variable for difference of mean length and each line's length
    double total = 0; //variable for summing all the differences


    for (int i=0; i<nucleotides.size();++i) //loops through data
        {
            char letter= toupper(nucleotides[i]);
            if(letter=='A' || letter=='G' || letter =='C' || letter == 'T')
                ++linecounter; //adds to individual line count if A, C, T, or G
            else if(letter=='\n')
                ++lines; //adds to total lines in \n is detected
                difference=(linecounter-av); //takes difference of individual line and line average
                total=total+pow(difference,2); //adds difference squared to total count
                linecounter=0; //resets individual line count to 0
        }

    return(total); //returns total to be calculated in variance() and deviation()

}

double nucleic::variance(string nucleotides)
{
    double tot = total(nucleotides); // stores total from total() function
    //double lines = lineCounter(nucleotides);//stores lines from lineCounter()

    double var = tot/(lines-1);//calculates variance by total/(n-1)
    return var;

}


double nucleic::deviation(string nucleotides)
{
    double tot = total(nucleotides);
    //double lines = lineCounter(nucleotides);

    double dev = sqrt(tot)/(lines-1);//takes square root of total for standard deviation
    return dev;

}


string nucleic::probability(string nucleotides) //calculatrs probability of nucleotides and nucleotide bigrams
{


    for (int i=0; i<nucleotides.size();i+=2) //iterates through data by twos, to evaluate each bigram
    {
        char letter= toupper(nucleotides[i]);//variable for first nucleotide in bigram
        char letternext = toupper(nucleotides[i+1]); //variable for second nucleotide in each bigram
        //nested if/else loops to read first letter and second letter
        if(letter == 'A'){ //checks first letter
            ++acount;
            if(letternext=='A'){ //checks second letter
                ++aa_count;//increments bigram variable
                ++acount;//increments singular variable
            }
            else if(letternext=='C'){
                ++ac_count;
                ++ccount;
            }
            else if(letternext=='G'){
                ++ag_count;
                ++gcount;
            }
            else if(letternext=='T'){
                ++at_count;
                ++tcount;
            }
        }
        else if(letter == 'G'){
            ++gcount;
            if(letternext=='A'){
                ++ga_count;
                ++acount;
            }
            else if(letternext=='C'){
                ++gc_count;
                ++ccount;
            }
            else if(letternext=='G'){
                ++gg_count;
                ++gcount;
            }
            else if(letternext=='T'){
                ++gt_count;
                ++tcount;
            }
        }
        else if(letter == 'C'){
            ++ccount;
            ++count;
            if(letternext=='A'){
                ++ca_count;
                ++acount;
            }
            else if(letternext=='C'){
                ++cc_count;
                ++ccount;
            }
            else if(letternext=='G'){
                ++cg_count;
                ++gcount;
            }
            else if(letternext=='T'){
                ++ct_count;
                ++tcount;
            }
        }
        else if(letter == 'T'){
            ++tcount;
            if(letternext=='A'){
                ++ta_count;
                ++acount;
            }
            else if(letternext=='C'){
                ++tc_count;
                ++ccount;
            }
            else if(letternext=='G'){
                ++tg_count;
                ++gcount;
            }
            else if(letternext=='T'){
                ++tt_count;
                ++tcount;
            }
        }
        else
            ++errorcount; //increments count of letters that are nto A,C,T or G
    }
    //calculates probability of each by dividing individual count by total count and multiplying by 100 for percentage value
    a_prob = (acount/count);
    aa_prob = (aa_count/count)*200; //calculates by multiplying by 200 (100*2) because you divide by half as many pairs as the letter count
    ag_prob = (ag_count/count)*200;
    ac_prob = (ac_count/count)*200;
    at_prob = (at_count/count)*200;

    g_prob = (gcount/count);
    ga_prob = (ga_count/count)*200;
    gc_prob = (gc_count/count)*200;
    gg_prob = (gg_count/count)*200;
    gt_prob = (gt_count/count)*200;

    c_prob = (ccount/count);
    ca_prob = (ca_count/count)*200;
    cc_prob = (cc_count/count)*200;
    cg_prob = (cg_count/count)*200;
    ct_prob = (ct_count/count)*200;

    t_prob = (tcount/count);
    ta_prob = (ta_count/count)*200;
    tc_prob = (tc_count/count)*200;
    tg_prob = (tg_count/count)*200;
    tt_prob = (tt_count/count)*200;

    string a = to_string(a_prob*100); //converts double to string
    string aa = "AA:"+to_string(aa_prob)+"%\n"; //formats probability of pairs
    string ag = "AG:"+to_string(ag_prob)+"%\n";
    string ac = "AC:"+to_string(ac_prob)+"%\n";
    string at = "AT:"+to_string(at_prob)+"%\n";

    string g = to_string(g_prob*100);
    string ga = "GA:"+to_string(ga_prob)+"%\n";
    string gg = "GG:"+to_string(gg_prob)+"%\n";
    string gc = "GC:"+to_string(gc_prob)+"%\n";
    string gt = "GT:"+to_string(gt_prob)+"%\n";

    string c = to_string(c_prob*100);
    string ca = "CA:"+to_string(ca_prob)+"%\n";
    string cg = "CG:"+to_string(cg_prob)+"%\n";
    string cc = "CC:"+to_string(cc_prob)+"%\n";
    string ct = "CT:"+to_string(ct_prob)+"%\n";

    string t = to_string(t_prob*100);
    string ta = "TA:"+to_string(ta_prob)+"%\n";
    string tg = "TG:"+to_string(tg_prob)+"%\n";
    string tc = "TC:"+to_string(tc_prob)+"%\n";
    string tt = "TT:"+to_string(tt_prob)+"%\n";


    //variable to store output for nucleotide probability
    string nuc_prob = ("The likelihood of each nucleotide occurring is as follows:\nA:"+a+"%\nG:"+g+"%\nC:"+c+"%\nT:"+t+"%");
    // variable to store output for bigram probability
    string nuc_bi_prob = ("The likelihood of each nucleotide bigram occurring is as follows:\n"+aa+ag+ac+at+ga+gg+gc+gt+ca+cg+cc+ct+ta+tg+tc+tt);
    //returns all data
    return(nuc_prob+"\n"+nuc_bi_prob);
}

string nucleic::genNucleotide() //generates a random letter
{
    while(true)
    {
        double x = ((double) rand() / RAND_MAX);
        //if statements compare randomly generated number to individual probabilities
        if(x<=a_prob)
        return "A";

        x = ((double) rand() / RAND_MAX);
        if(x<=g_prob)
        return "G";

        x = ((double) rand() / RAND_MAX);
        if(x<=c_prob)
        return "C";

        x = ((double) rand() / RAND_MAX);
        if(x<=t_prob)
        return "T";

    }


}

int nucleic::genLength(string nucleotides) //method to generate a random length for the string which will be appended
{
    double av = mean(nucleotides);
    double var = variance(nucleotides);
    double dev = deviation(nucleotides);

    //generates a number between 0 and 1
    double a = ((double) rand() / RAND_MAX);
    double b = ((double) rand() / RAND_MAX);

    b = cos(2 * PI * b);
    //makes b positive if it was negative
    if (b<0){
        b=b*-1;
    }

    double c = sqrt((-2)*log(a)) * b;

    if (c<0){
        c=c*-1;
    }

    double d = (dev*c) + av;//calculates a random length

    int final_length = ceil(d); //turns d into an int

    return final_length;

}
