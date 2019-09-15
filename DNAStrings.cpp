#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream> //for file access
#include <random>





using namespace std;
int main(int argc, char** argv)
{

    if (argc > 1)
     {
        cout << "argv[1] = " << argv[1] << endl;
     }
    else
     {
        cout << "No file name entered. Exiting...";
        return -1;
     }
    ifstream infile(argv[1]); //open the file
    ofstream outputFile; // copy to a file
    outputFile.open("Nawal.out");
    if (infile.is_open() && infile.good())
     {
        cout << "File is now open:\n" << endl;

        string line = "";
        int count = 0;
        int sum = 0;
        int mean;
        int addingsquaredlines = 0;

        // for probability
        int occurrences_A;
        double probability_A;
        int occurrences_T;
        double probability_T;
        int occurrences_G;
        double probability_G;
        int occurrences_C;
        double probability_C;

        int occurrences_AA;
        double probability_AA;
        int occurrences_AT;
        double probability_AT;
        int occurrences_AG;
        double probability_AG;
        int occurrences_AC;
        double probability_AC;

        int occurrences_TA;
        double probability_TA;
        int occurrences_TG;
        double probability_TG;
        int occurrences_TC;
        double probability_TC;
        int occurrences_TT;
        double probability_TT;

        int occurrences_CC;
        double probability_CC;
        int occurrences_CG;
        double probability_CG;
        int occurrences_CA;
        double probability_CA;
        int occurrences_CT;
        double probability_CT;

        int occurrences_GG;
        double probability_GG;
        int occurrences_GC;
        double probability_GC;
        int occurrences_GA;
        double probability_GA;
        int occurrences_GT;
        double probability_GT;


        char c;
        char d;
        int countA = 0;
        int countT = 0;
        int countG = 0;
        int countC = 0;
        int countAA = 0;
        int countAT = 0;
        int countAG = 0;
        int countAC = 0;
        int countCA = 0;
        int countCT = 0;
        int countCG = 0;
        int countCC = 0;
        int countGA = 0;
        int countGT = 0;
        int countGG = 0;
        int countGC = 0;
        int countTA = 0;
        int countTT = 0;
        int countTG = 0;
        int countTC = 0;






        while (getline(infile, line))
        {
          //  cout << line << endl;
          //  cout << line.size()-1 << endl;

            // to find the length of DNA strings and adding it up (sum of DNA strings)
            sum += line.size()-1;
            // to find the number of lines
            count++;
            // squaring number of strings in each line and adding them up for variance calculation
            addingsquaredlines += pow(line.size()-1,2);
          //  cout << addingsquaredlines << endl;


            // for loop to iterate through list of strings and find the occurrences of each nucleotide and nucleotide biagram
            for (int i =0; i<sum; ++i)
            {
              c = line[i];
              d = line[i-1];

              if(c == 'A')
              {
                countA++;
                if (d == 'A')
                {
                  countAA++;
                }
                if (d == 'T')
                {
                  countAT++;
                }
                if (d == 'G')
                {
                  countAG++;
                }
                if (d == 'C')
                {
                  countAC++;
                }
             }
             else if (c == 'T')
             {
               countT++;
               if (d == 'A')
               {
                 countTA++;
               }
               if (d == 'G')
               {
                 countTG++;
               }
               if (d == 'C')
               {
                 countTC++;
               }
               if (d == 'T')
               {
                 countTT++;
               }
             }
             else if (c == 'G')
             {
               countG++;
               if (d == 'A')
               {
                 countGA++;
               }
               if (d == 'G')
               {
                 countGG++;
               }
               if (d == 'C')
               {
                 countGC++;
               }
               if (d == 'T')
               {
                 countGT++;
               }
             }
             else if (c == 'C')
             {
               countC++;
               if (d == 'A')
               {
                 countCA++;
               }
               if (d == 'G')
               {
                 countCG++;
               }
               if (d == 'C')
               {
                 countCC++;
               }
               if (d == 'T')
               {
                 countCT++;
               }
             }

              }


      }


        // printing out the number of lines, mean, variance and std.
        outputFile << "The number of lines in the file is: " << count <<endl;
        outputFile <<  "The sum of DNA strings' length is: " << sum <<endl;
      //  cout <<  "each line of the DNA squared indivisually and added equals: " << addingsquaredlines <<endl;
        mean = sum/count;
        outputFile << "Mean equals: " << mean << endl;



        // calculating variance w/o using arrays
        float sum_square = pow((sum),2);
        float devide_by_linesnum = sum_square/count;
        float substract = addingsquaredlines - devide_by_linesnum;
        float substract_one = count - 1;
        float variance = substract/substract_one;
        outputFile << "Variance equals: " << variance << endl;

        // calculating Standard deviation
        float square_root = pow(variance,0.5);
        outputFile << "Standard deviation equals: " << square_root << endl;


        //counting the probability for each nucleotide and nucleotide biagram
        occurrences_A = countA;
        probability_A = (double) occurrences_A / sum;
        occurrences_T = countT;
        probability_T = (double) occurrences_T / sum;
        occurrences_G = countG;
        probability_G = (double) occurrences_G / sum;
        occurrences_C = countC;
        probability_C = (double) occurrences_C / sum;
        outputFile << "The probability of A in the sequence equals: " <<probability_A << ", " << probability_A*100 <<"% "<< occurrences_A << " A's" << endl;
        outputFile << "The probability of T in the sequence equals: " <<probability_T << ", " << probability_T*100 <<"% "<< occurrences_T << " T's" << endl;
        outputFile << "The probability of G in the sequence equals: " <<probability_G << ", " << probability_G*100 <<"% "<< occurrences_G << " G's" << endl;
        outputFile << "The probability of C in the sequence equals: " <<probability_C << ", " << probability_C*100 <<"% "<< occurrences_C << " C's \n" << endl;

        occurrences_AA = countAA;
        probability_AA = (double) occurrences_AA / sum;
        outputFile << "The probability of AA in the sequence equals: " <<probability_AA << ", " << probability_AA*100 <<"% "<< occurrences_AA << " AA's" << endl;
        occurrences_AT = countAT;
        probability_AT = (double) occurrences_AT / sum;
        outputFile << "The probability of AT in the sequence equals: " <<probability_AT << ", " << probability_AT*100 <<"% "<< occurrences_AT << " AT's" << endl;
        occurrences_AG = countAG;
        probability_AG = (double) occurrences_AG / sum;
        outputFile << "The probability of AG in the sequence equals: " <<probability_AG << ", " << probability_AG*100 <<"% "<< occurrences_AG << " AG's" << endl;
        occurrences_AC = countAC;
        probability_AC = (double) occurrences_AC / sum;
        outputFile << "The probability of AC in the sequence equals: " <<probability_AC << ", " << probability_AC*100 <<"% "<< occurrences_AC << " AC's\n" << endl;

        occurrences_TA = countTA;
        probability_TA = (double) occurrences_TA / sum;
        outputFile << "The probability of TA in the sequence equals: " <<probability_TA << ", " << probability_TA*100 <<"% "<< occurrences_TA << " TA's" << endl;
        occurrences_TC = countTC;
        probability_TC = (double) occurrences_TC / sum;
        outputFile << "The probability of TC in the sequence equals: " <<probability_TC << ", " << probability_TC*100 <<"% "<< occurrences_TC << " TC's" << endl;
        occurrences_TT = countTT;
        probability_TT = (double) occurrences_TT / sum;
        outputFile << "The probability of TT in the sequence equals: " <<probability_TT << ", " << probability_TT*100 <<"% "<< occurrences_TT << " TT's" << endl;
        occurrences_TG = countTG;
        probability_TG = (double) occurrences_TG / sum;
        outputFile << "The probability of TG in the sequence equals: " <<probability_TG << ", " << probability_TG*100 <<"% "<< occurrences_TG << " TG's\n" << endl;

        occurrences_GA = countGA;
        probability_GA = (double) occurrences_GA / sum;
        outputFile << "The probability of GA in the sequence equals: " <<probability_GA << ", " << probability_GA*100 <<"% "<< occurrences_GA << " GA's" << endl;
        occurrences_GC = countGC;
        probability_GC = (double) occurrences_GC / sum;
        outputFile << "The probability of GC in the sequence equals: " <<probability_GC << ", " << probability_GC*100 <<"% "<< occurrences_GC << " GC's" << endl;
        occurrences_GT = countGT;
        probability_GT = (double) occurrences_GT / sum;
        outputFile << "The probability of GT in the sequence equals: " <<probability_GT << ", " << probability_GT*100 <<"% "<< occurrences_GT << " GT's" << endl;
        occurrences_GG = countGG;
        probability_GG = (double) occurrences_GG / sum;
        outputFile << "The probability of GG in the sequence equals: " <<probability_GG << ", " << probability_GG*100 <<"% "<< occurrences_GG << " GG's\n" << endl;

        occurrences_CA = countCA;
        probability_CA = (double) occurrences_CA / sum;
        outputFile << "The probability of CA in the sequence equals: " <<probability_CA << ", " << probability_CA*100 <<"% "<< occurrences_CA << " CA's" << endl;
        occurrences_CT = countCT;
        probability_CT = (double) occurrences_CT / sum;
        outputFile << "The probability of CT in the sequence equals: " <<probability_CT << ", " << probability_CT*100 <<"% "<< occurrences_CT << " CT's" << endl;
        occurrences_CG = countCG;
        probability_CG = (double) occurrences_CG / sum;
        outputFile << "The probability of CG in the sequence equals: " <<probability_CG << ", " << probability_CG*100 <<"% "<< occurrences_CG << " CG's" << endl;
        occurrences_CC = countCC;
        probability_CC = (double) occurrences_CC / sum;
        outputFile << "The probability of CC in the sequence equals: " <<probability_CC << ", " << probability_CC*100 <<"% "<< occurrences_CC << " CC's\n" << endl;

        //generating 1000 DNA strings
        int x;
        int y;
        char n;
        int mean1 = 6;
        float variance1 = 0.214286;
        float sDeviation = 0.46291;
        string random = "ACGT";

        // to calculate the length of strings based with known mean variance and std.
        y = sqrt( -2*log( rand() ) ) * cos(6.2831853*rand() );
        for (int i = 0; i < 1000; ++i)
          {
            // x is the length of the strings generated
            x = 6 + 0.46291*y;
            return x;

            // to generate stings with a specific length
            for (int j = 0; j < x; ++j)
            {
               n = random[rand() % x];
               return n;
            }
          }
          // appends a new list of strings.
        outputFile << n << endl;
          // askes if the user wants to process another lest.
        char command;
        cin >> command;
        cout << "Do you want to process another list(y/n) ?" << endl;
        // if the answer is no the program will exist
        if(command == 'n' || command == 'N')
        {
          return 1;
        }
      // close the files!
      infile.close();
      outputFile.close();
      cout << "Done!\n"<<endl;
    }

    else
    {
        cout << "Failed to open file.." << endl;
    }

  return 0;

}
