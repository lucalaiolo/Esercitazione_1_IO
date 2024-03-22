#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

double map(double val, double a, double b, double c, double d) { // increasing linear function that maps the interval [a,b] in the interval [c,d]
    return ((d-c)*val+b*c-a*d)/(b-a);
}


int main()
{
    double val = 0.0;
    double sum = 0.0;
    unsigned int countVal = 0;
    double mean = 0.0;

    double a = 1.0;
    double b = 5.0;
    double c = -1.0;
    double d = 2.0;


    std::string inputFileName = "data.csv";
    std::ifstream inputFile(inputFileName);

    std::string outputFileName = "result.csv";
    std::ofstream resultsFile(outputFileName);


    if(inputFile.fail()) {
        std::cerr << "Input file does not exist" << "\n";
        return 1;
    }

    if (resultsFile.fail()){
        std::cout << "Something went wrong." << "\n";
        return 2;
    }


    std::string header;
    header = "# N Mean";
    resultsFile << header << "\n";
    resultsFile << std::scientific;
    resultsFile << std::setprecision(16);

    while(inputFile >> val) {
        sum += map(val,a,b,c,d);
        countVal++;
        mean = sum/countVal;
        resultsFile << countVal << " " << mean << "\n";
    }

    inputFile.close();
    resultsFile.close();

    return 0;
}
