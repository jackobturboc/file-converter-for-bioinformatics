#ifndef PROJECTFM_GLOBAL_CONST_HPP
#define PROJECTFM_GLOBAL_CONST_HPP

#include <fstream>
#include <vector>
#include <time.h>
#include <string>
#include <regex>
#include <cstdlib>
#include <map>
#include <iostream>
#include <math.h>

struct Properties{
    std::string codeOut;
    int isImport = 0; // for QT
    std::string logFileName = "codeProgress.log";
    int indOfSeqWhYNd = -1; //index of sequence which you need (-1 if all)
    std::string inpFileTy = "AUTO";  // type Of inp file
    std::string outFileTy = "FASTA_general";  // type of inp file
    std::string pathToOut = "newFile.FM";  // path to output file
    std::string outFileName = "newFile.FM";  // name of output file
    std::string pathToInp = "nothing";  // path to input files
    int lenghtOfLine = 80; // lenght of line in output file
    std::string redactTitles = "SH"; // if SH keep
    void log(std::string text){
        std::ofstream out(logFileName, std::ios::app);
        if (out.is_open()) {
            out << text << std::endl;
            out.close();
        }
        else {
            codeOut = "ERROR: can't make log";
        }
    }
    void clearLog(){
        std::ofstream out(logFileName);
        if (out.is_open()) {
            out << "This is log from https://github.com/jackobturboc/file-converter-for-bioinformatics\n";
            out.close();
        }
    }
};

//long long timeFromStart;'

#endif //PROJECTFM_GLOBAL_CONST_HPP
