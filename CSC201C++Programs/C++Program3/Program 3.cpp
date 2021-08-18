/*
File Name: Program 3 "Bodylastics"
Name: Aditya Maleeswaran
Input: Reads the strings as colors from an input file; Also asks the user for
the total resistance
Output: Outputs the number of each bands that can be used for the total
resistance in the output file
Description: This program uses the array of records and enum types to read the
strings from the input file. Then, it converts the string to the band color
and sets the boolean flag to false. It also ask the user the total resistance
in order to calculate the number of each color bands the user needs.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

enum Bandtype {YELLOW, GREEN, RED, BLUE, BLACK};

struct BandRecord
{
       string BandColor;
       int Weight;
       bool Flag;
};

void GetBands (ifstream&, BandRecord [], Bandtype);      // Prototypes
Bandtype str_to_color(const string&);
void PrintBands (ostream&, const BandRecord []);
int TotalResistance (const BandRecord []);
void ResetBands (BandRecord []);
void Weight_to_Bands (ofstream&, int, BandRecord []);

int main(void)
{
    ifstream infile;
    ofstream outfile;
    Bandtype B1;
    int Resistance;
    BandRecord Members [] = {"YELLOW", 3, false, "GREEN", 5, false,
                            "RED", 8, false, "BLUE", 13, false,
                            "BLACK", 19, false};

    infile.open("Input Bands.txt");
    if(!infile)
    {
               cout << "Unable to open Input Bands.txt \n";
               system ("pause");
               return 1;
    }
    outfile.open("Output File.txt");
    if(!outfile)
    {
                cout << "Unable to open Output File.txt \n";
                system ("pause");
                return 1;
    }

    /*
    for (Bandtype B = YELLOW; B <= BLACK; B = Bandtype (B + 1))
    {
        cout << setw (7) << Members [B].BandColor << setw (5) << Members [B].Weight
        cout << setw (5) << Members [B].Flag << endl;
    }
    */

    GetBands (infile, Members, B1);                // Call in the main function
    PrintBands (outfile, Members);
    cout << "Total Resistance: " << TotalResistance (Members) << endl;
    outfile << "Total Resistance: " << TotalResistance (Members) << endl;

    // Call for the Second Part of the Program
    cout << "Please input the resistance in pounds: " << endl;
    cin >> Resistance;
    ResetBands (Members);
    Weight_to_Bands(outfile, Resistance, Members);
    //PrintBands (outfile, Members);
    //cout << "Total Resistance: " << TotalResistance (Members) << endl;
    //outfile << "Total Resistance: " << TotalResistance (Members) << endl;

    infile.close();
    outfile.close();
    system("pause");
    return 0;
} // Close main function

////////////////////////////////////////////////////////////////////////////////

void GetBands (ifstream& infile, BandRecord Members[], Bandtype B1)// Parameters
{
     string temp;
     infile >> temp;                                            // Priming Read
     //int i = 0;
     while (infile)                                         // End of file loop
     {
           B1 = str_to_color(temp);             // Calling str_to_color function
           Members [B1].Flag = true;

           //cout << "Flag is " << Members [B1].Flag << endl;

           infile >> temp;
           //cout << temp << endl;
     }
} // Close getbands function

////////////////////////////////////////////////////////////////////////////////

Bandtype str_to_color(const string& temp)
{
         switch (temp[0])
         {
                case 'Y': return YELLOW;
                case 'G': return GREEN;
                case 'R': return RED;
                case 'B': switch (temp[2])
                          {
                                 case 'u': return BLUE;
                                 case 'a': return BLACK;
                          }
         }
} // Close Str_to_color function

////////////////////////////////////////////////////////////////////////////////

void PrintBands (ostream& outfile, const BandRecord Members[])
{
     for (Bandtype B1 = YELLOW; B1 <= BLACK; B1 = Bandtype (B1 + 1))
    {
        if (Members [B1].Flag == true)
        {
                    outfile << setw (7) << Members [B1].BandColor;
                    outfile << setw (5) << Members [B1].Weight;
                    outfile << " pounds of resistance" << endl;
                    cout << setw (7) << Members [B1].BandColor;
                    cout << setw (5) << Members [B1].Weight;
                    cout << " pounds of resistance" << endl;
        }
    }
} // Close PrintBands function

////////////////////////////////////////////////////////////////////////////////

int TotalResistance (const BandRecord Members[])
{
     int Total = 0;
     for (Bandtype B1 = YELLOW; B1 <= BLACK; B1 = Bandtype (B1 + 1))
     {
         if (Members [B1].Flag == true)
         {
         Total = Total + Members [B1].Weight;
         }
     }
     //cout << Total << endl;
     return 2*Total;
} // Close Total Resistance function

////////////////////////////////////////////////////////////////////////////////

void ResetBands (BandRecord Members[])
{
     bool x;
     for (Bandtype B1 = YELLOW; B1 <= BLACK; B1 = Bandtype (B1 + 1))
     {
         Members [B1].Flag = false;
         x = Members [B1].Flag;
     }
} // Close Reset Bands function

////////////////////////////////////////////////////////////////////////////////

void Weight_to_Bands (ofstream& outfile, int Resistance, BandRecord Members [])
{
     int Yellow, Green, Red, Blue, Black, total = 0;

     Resistance = Resistance / 2;


     Black = Resistance / Members [BLACK].Weight;     // Calculating Black Bands
     if (Black >= 1)
     {
               Members [BLACK].Flag = true;
               cout << "You need about " << Black << " band(s) of ";
               outfile << "You need about " << Black << " band(s) of ";
               PrintBands (outfile, Members);
               total = total + (Members[BLACK].Weight * Black);
     }

     Resistance = Resistance % Members [BLACK].Weight;
     ResetBands (Members);


     Blue = Resistance / Members [BLUE].Weight;        // Calculating Blue Bands
     if (Blue >= 1)
     {
               Members [BLUE].Flag = true;
               cout << "You need about " << Blue << " band(s) of ";
               outfile << "You need about " << Blue << " band(s) of ";
               PrintBands (outfile, Members);
               total = total + (Members[BLUE].Weight * Blue);
     }

     Resistance = Resistance % Members [BLUE].Weight;
     ResetBands (Members);


     Red = Resistance / Members [RED].Weight;           // Calculating Red Bands
     if (Red >= 1)
     {
               Members [RED].Flag = true;
               cout << "You need about " << Red << " band(s) of ";
               outfile << "You need about " << Red << " band(s) of ";
               PrintBands (outfile, Members);
               total = total + (Members [RED].Weight * Red);
     }

     Resistance = Resistance % Members [RED].Weight;
     ResetBands (Members);


     Green = Resistance / Members [GREEN].Weight;     // Calculating Green Bands
     if (Green >= 1)
     {
               Members [GREEN].Flag = true;
               cout << "You need about " << Green << " band(s) of ";
               outfile << "You need about " << Green << " band(s) of ";
               PrintBands (outfile, Members);
               total = total + (Members [GREEN].Weight * Green);
     }

     Resistance = Resistance % Members [GREEN].Weight;
     ResetBands (Members);


     if (Resistance >= 3)
     {
                Yellow = Resistance / Members [0].Weight; // Calculating Yellow Bands
                if (Yellow >= 1)
                {
                           Members [0].Flag = true;
                           cout << "You need about " << Yellow << " band(s) of ";
                           outfile << "You need about " << Yellow << " band(s) of ";
                           PrintBands (outfile, Members);
                           total = total + (Members [YELLOW].Weight * Yellow);
                }
     }
     ResetBands (Members);

     cout << "The total resistance for those bands is: " << total * 2 << endl;
     outfile << "The total resistance for those bands is: " << total * 2 << endl;
} // Close Weight_to_Bands function

////////////////////////////////////////////////////////////////////////////////
