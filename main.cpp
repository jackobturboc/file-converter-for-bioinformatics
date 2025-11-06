#include "global_const.hpp"
#include "sequences_files_format_descriptions.h"

long long getTimeFromStart(){
    return time(NULL) - TimeFromStart;
}

std::string getaddress(std::string adress){
    return "examples\\" + adress;
};

void read(std::string fileAdress ){
    std::string line;
    std::ifstream in(fileAdress);
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::cout << line << std::endl;
        }
    }
    in.close();
}

struct SequenceItem{
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

struct SequencesBox{
    SequencesBox();
    AllSequencesFileFormatDescription type;
    std::vector<SequenceItem> Sequences;
    std::string format;
    void fileFormatSearcher(std::string fileAddress);
    void manager(std::string address);
    void parser();
};

SequencesBox::SequencesBox(){
    type.init();
}

void SequencesBox::fileFormatSearcher(std::string fileAddress){
    std::string line;
    std::ifstream in(fileAddress);
    if (in.is_open()) {
        std::getline(in, line);

//        std::cout << "FILE WAS OPEN" << "\n";

        if ((line[0] == '>') and
           ((line[3] == '|') or
            (line[4] == '|')) ) {
            format = "FASTA_NCBI_db_link";
//            std::cout << "FASTA_NCBI_db_link" << "\n";
        }

        if ((line[0] == '>') and
            ((line[line.size() - 1] == '|') or
             (line[4] == '|')) ) {
            format = "FASTA_NCBI_db_link";
//            std::cout << "FASTA_NCBI_db_link" << "\n";
        }

        if ((line[0] == '>') and
            ((line[line.size() - 1] == '|') or
             (line[4] == '|')) ) {
            format = "FASTA_NCBI_db_link";
//            std::cout << "FASTA_NCBI_db_link" << "\n";
        }

        if ((line[0] == '>') and
            ((65 <= line[0]) and (line[0] <= 90)) and
            ((65 <= line[1]) and (line[1] <= 90)) and
            ((48 <= line[1]) and (line[1] <= 57)) and
            ((48 <= line[1]) and (line[1] <= 57)) and
            ((48 <= line[1]) and (line[1] <= 57)) and
            ((48 <= line[1]) and (line[1] <= 57)) and
            ((48 <= line[1]) and (line[1] <= 57)) and
            ((48 <= line[1]) and (line[1] <= 57))){
            format = "NCBI_common";
//            std::cout << "NCBI_common" << "\n";
        }

        if (line[0] == '>'){
            format = "FASTA_general";
//            std::cout << "FASTA" << "\n";
        }

        if (line[0] == '@'){
            if (line[1] != '@'){
                format = "FASTAQ_sanger";
//                std::cout << "FASTAQ_sanger" << "\n";
            }
            else {
//                std::cout << "MAYBE SAM" << "\n";
            }
        }
        if ((line[0] == 'L') and
            (line[1] == 'O') and
            (line[2] == 'C') and
            (line[3] == 'U') and
            (line[4] == 'S')    ) {
            format = "FASTA_GenBank";
//            std::cout << "GENBANK" << "\n";
        }
        if ((line[0] == 'Q') and
            (line[1] == 'u') and
            (line[2] == 'e') and
            (line[3] == 'r') and
            (line[4] == 'y')    ) {
//            std::cout << "BLAST" << "\n";
        }

        if ((line[0] == 'C') and
            (line[1] == 'L') and
            (line[2] == 'U') and
            (line[3] == 'S') and
            (line[4] == 'T') and
            (line[5] == 'A') and
            (line[6] == 'L') ) {
//            std::cout << "CLUSTAL" << "\n";
        }

        if ((line[0] == '#') and
            (line[1] == 'N') and
            (line[2] == 'E') and
            (line[3] == 'X') and
            (line[4] == 'U') and
            (line[5] == 'S') ) {
//            std::cout << "NEXUS" << "\n";
        } else {
            if (line[0] == '#'){
//                std::cout << "Stockholm" << "\n";
            }
        }

        if ((line[0] == '!') and
            (line[1] == '!') ) {
//            std::cout << "MSF" << "\n";
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
//            std::cout << "PHILIP" << "\n";
        }
        if (format == ""){
            format = "FASTA_bare";
        }
    }
    in.close();
}

void SequencesBox::manager(std::string address) {
    fileFormatSearcher(getaddress(address));
    std::cout << "is this: " << format << "Y/N" << "\n";
    std::string s;
    std::cin >> s;
    if (s == "N"){
        std::cin >> s;
        format = s;
    }
    parser();
}

void SequencesBox::parser(){
    std::string start = type.dlst[format].header_line_start;
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
    SequencesBox n;
    n.fileFormatSearcher(getaddress("003_ncbi_two_with_asterics.fasta "));
    return 0;
}