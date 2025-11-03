#include "global_const.hpp"
#include "sequences_files_format_descriptions.h"

long long getTimeFromStart(){
    return time(NULL) - TimeFromStart;
}

std::string getadress(std::string adress){
    return "examples\\" + adress;
};

struct sequenceItem{
    std::string tittle;
    std::string sequence;
    std::string comments;
    std::string quality;
    std::string tittle_quality;
    void show(bool tit, bool seq, bool com, bool qua){ //debug only
        if (tit) { std::cout << "title:" << tittle << "\n"; }
        if (seq) { std::cout << "sequence:" << sequence << "\n"; }
        if (com) { std::cout << "comment:" << comments << "\n"; }
        if (qua) { std::cout << "quality:" << quality << "\n"; std::cout << "title_quality:" << tittle_quality << "\n"; }
    }
};

void fileFormatSearcher(std::string fileAdress){
    AllSequencesFileFormatDescription type;
    std::string line;
    std::ifstream in(fileAdress);
    if (in.is_open()) {
        std::getline(in, line);

        std::cout << "FILE WAS OPEN" << "\n";

        if (line[0] == '>'){
            //FASTA CALL
            std::cout << "FASTA" << "\n";
        }
        if (line[0] == '@'){
            if (line[1] != '@'){
                std::cout << "FASTAQ" << "\n";
            }
            else {
                std::cout << "MAYBE SAM" << "\n";
            }
        }
        if ((line[0] == 'L') and
            (line[1] == 'O') and
            (line[2] == 'C') and
            (line[3] == 'U') and
            (line[4] == 'S')    ) {
            std::cout << "GENBANK" << "\n";
        }
        if ((line[0] == 'Q') and
            (line[1] == 'u') and
            (line[2] == 'e') and
            (line[3] == 'r') and
            (line[4] == 'y')    ) {
            std::cout << "BLAST" << "\n";
        }

        if ((line[0] == 'C') and
            (line[1] == 'L') and
            (line[2] == 'U') and
            (line[3] == 'S') and
            (line[4] == 'T') and
            (line[5] == 'A') and
            (line[6] == 'L') ) {
            std::cout << "CLUSTAL" << "\n";
        }

        if ((line[0] == '#') and
            (line[1] == 'N') and
            (line[2] == 'E') and
            (line[3] == 'X') and
            (line[4] == 'U') and
            (line[5] == 'S') ) {
            std::cout << "NEXUS" << "\n";
        } else {
            if (line[0] == '#'){
                std::cout << "Stockholm" << "\n";
            }
        }

        if ((line[0] == '!') and
            (line[1] == '!') ) {
            std::cout << "MSF" << "\n";
        }
        bool flagout = true;
        std::vector<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (char s:line){
            if (s != ' '){
                bool flag = false;
                for (char ss:nums){
                    if (ss == s){
                        flag = true;
                    }
                }
                if (flag == 0){
                    flagout = false;
                }
            }
        }
        if (flagout){
            std::cout << "PHILIP" << "\n";
        }
    }
    in.close();
}

void log(std::string message){
    std::ofstream out;
    out.open("log.txt");
    if (out.is_open()) {
        out << "[ " << getTimeFromStart << " ms ] " << message << std::endl;
    }
    out.close();
}

void logErr(std::string message){
    std::ofstream out;
    out.open("log.txt");
    if (out.is_open()) {
        out << "[ " << getTimeFromStart << " ms ] " << message << " ERROR " << std::endl;
    }
    out.close();
}

int main() {
//    log("all good");
//    logErr("all bad");
    fileFormatSearcher(getadress("024_Stockholm_alignment.txt"));
    return 0;
}
