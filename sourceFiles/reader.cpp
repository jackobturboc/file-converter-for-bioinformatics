//
// Created by User on 22.11.2025.
//

#include "reader.hpp"

void SequenceReader::parser(SequencesBox & list) {

    if (list.format == "FASTA_general" || list.format == "FASTA_NCBI_db_link") {
        std::string line;
        int fileNumber = 0;
        std::ifstream in(prop.pathToInp);
        SequenceItem exmp;
        if (in.is_open()) {
            while (getline(in, line)) {
                if (line[0] == '>'){
                    if (!exmp.sequence.empty()){
                        list.sequences.push_back(exmp);
                        exmp.clear();
                    }
                    exmp.title += line.substr(1, line.size());
                    continue;
                }
                exmp.sequence += line;
            }
            list.sequences.push_back(exmp);
        }
        in.close();
    }
    if (list.format == "FASTAQ_sanger") {
        std::string line;
        int fileNumber = 0;
        int lenLine = 0;
        std::ifstream in(prop.pathToInp);
        SequenceItem exmp;
        int phase = 0;
        std::string into;
        if (in.is_open()) {
            while (getline(in, line)) {
                if  (line.empty()){
                    return;
                }
                switch (phase) {
                    case 0:
                        list.sequences.push_back(exmp);
                        list.sequences[fileNumber].title += line.substr(1, line.size());\
                        phase = 1;
                        break;
                    case 1:
                        if (line[0] == '+') {
                            list.sequences[fileNumber].title_quality += line.substr(1, line.size());
                            phase = 2;
                            break;
                        }
                        lenLine += 1;
                        list.sequences[fileNumber].sequence  += line.substr(0, line.size());
                        break;
                    case 2:
                        lenLine--;
                        list.sequences[fileNumber].quality += line.substr(0, line.size());
                        if (!lenLine) {
                            fileNumber++;
                            phase = 0;
                        }
                        break;
                }
            }
        }
        in.close();
    }
    else if(list.format == "FASTA_GenBank") {
        std::string line;
        std::ifstream in(prop.pathToInp);
        SequenceItem exmp;
        list.sequences.push_back(exmp);
        int phase = 0;
        std::string into;
        if (in.is_open()) {
            while (getline(in, line)) {
                switch (phase) {
                    case 0:
                        for (int i = 0; i < line.size(); ++i) {
                            if (line[i] == ' ' && line[i + 1] != ' ') {
                                phase = 1;
                                list.sequences[0].title = line.substr(i, line.size());
                                break;
                            }
                        }
                        break;
                    case 1:
                        list.sequences[0].titles.push_back(line);
                        if (line.find("ORIGIN") == 0) {
                            phase = 2;
                            break;
                        }
                        break;
                    case 2:
                        for (char s:line) {
                            if (isalpha(s)) { into += s - 32;}
                        }
                        list.sequences[0].sequence += into;
                        into.clear();
                        break;
                }
            }
        }
        in.close();
    }
    else if(list.format == "EMBL") {
        std::string line;
        std::ifstream in(prop.pathToInp);
        SequenceItem exmp;
        list.sequences.push_back(exmp);
        int phase = -1;
        std::string into;
        if (in.is_open()) {
            while (getline(in, line)) {
                switch (phase) {
                    case -1:
                        phase = 0;
                        break;
                    case 0:
                        list.sequences[0].title = line;
                        phase = 1;
                        break;
                    case 1:
                        list.sequences[0].titles.push_back(line);
                        if (line.find("SQ") == 0) {
                            phase = 2;
                            break;
                        }
                        break;
                    case 2:
                        for (char s:line) {
                            if (isalpha(s)) { into += s - 32;}
                        }
                        list.sequences[0].sequence += into;
                        into.clear();
                        break;
                }
            }
        }
        in.close();
    }
}

void PairReader::parser(PairBox & list) {
//    if (list.format == "FASTA"){
//        int phase = 0;
//        std::string line;
//        int fileNumber;
//        std::ifstream in(fileAddress);
//        SequenceItem exmp;
//        list.sequences.push_back(exmp);
//        if (in.is_open()) {
//            for (int i = 0; i < line.size(); i++){
//                if (line[i] == '\n'){
//                    phase = 1;
//                }
//                switch (phase) {
//                    case 0:
//                        list.sequences[fileNumber].comments += line[i];
//                        if (line[i] == '>'){
//                            phase = 1;
//                        }
//                        break;
//                    case 1:
//                        list.sequences[fileNumber].tittle += line[i];
//                        if (line[i] == '\n'){
//                            phase = 2;
//                        }
//                        break;
//                    case 2:
//                        list.sequences[fileNumber].sequence += line[i];
//                        if (line[i] == '>'){
//                            SequenceItem exmp;
//                            list.sequences.push_back(exmp);
//                            fileNumber++;
//                            phase = 0;
//                        }
//                        break;
//                }
//            }
//        }
//        in.close();
//    }
//    if (list.format == "FASTA_NCBI_db_link"){
//        int phase = 0;
//        std::string line;
//        int fileNumber;
//        std::ifstream in(fileAddress);
//        SequenceItem exmp;
//        list.sequences.push_back(exmp);
//        if (in.is_open()) {
//            for (int i = 0; i < line.size(); i++){
//                if (line[i] == '\n'){
//                    phase = 1;
//                }
//                switch (phase) {
//                    case 0:
//                        list.sequences[fileNumber].comments += line[i];
//                        if (line[i] == '>'){
//                            phase = 1;
//                        }
//                        break;
//                    case 1:
//                        list.sequences[fileNumber].tittle += line[i];
//                        if (line[i] == '\n'){
//                            phase = 2;
//                        }
//                        break;
//                    case 2:
//                        list.sequences[fileNumber].sequence += line[i];
//                        if (line[i] == '>'){
//                            SequenceItem exmp;
//                            list.sequences.push_back(exmp);
//                            fileNumber++;
//                            phase = 0;
//                        }
//                        break;
//                }
//            }
//        }
//        in.close();
//    }
}

void MSAReader::parser(MSABox & list){
//    if (list.format == "FASTA"){
//        int phase = 0;
//        std::string line;
//        int fileNumber;
//        std::ifstream in(fileAddress);
//        SequenceItem exmp;
//        list.sequence.push_back(exmp);
//        if (in.is_open()) {
//            for (int i = 0; i < line.size(); i++){
//                if (line[i] == '\n'){
//                    phase = 1;
//                }
//                switch (phase) {
//                    case 0:
//                        list.sequences[fileNumber].comments += line[i];
//                        if (line[i] == '>'){
//                            phase = 1;
//                        }
//                        break;
//                    case 1:
//                        list.sequences[fileNumber].tittle += line[i];
//                        if (line[i] == '\n'){
//                            phase = 2;
//                        }
//                        break;
//                    case 2:
//                        list.sequences[fileNumber].sequence += line[i];
//                        if (line[i] == '>'){
//                            SequenceItem exmp;
//                            list.sequences.push_back(exmp);
//                            fileNumber++;
//                            phase = 0;
//                        }
//                        break;
//                }
//            }
//        }
//        in.close();
//    }
//    if (list.format == "FASTA_NCBI_db_link"){
//        int phase = 0;
//        std::string line;
//        int fileNumber;
//        std::ifstream in(fileAddress);
//        SequenceItem exmp;
//        list.sequences.push_back(exmp);
//        if (in.is_open()) {
//            for (int i = 0; i < line.size(); i++){
//                if (line[i] == '\n'){
//                    phase = 1;
//                }
//                switch (phase) {
//                    case 0:
//                        list.sequences[fileNumber].comments += line[i];
//                        if (line[i] == '>'){
//                            phase = 1;
//                        }
//                        break;
//                    case 1:
//                        list.sequences[fileNumber].tittle += line[i];
//                        if (line[i] == '\n'){
//                            phase = 2;
//                        }
//                        break;
//                    case 2:
//                        list.sequences[fileNumber].sequence += line[i];
//                        if (line[i] == '>'){
//                            SequenceItem exmp;
//                            list.sequences.push_back(exmp);
//                            fileNumber++;
//                            phase = 0;
//                        }
//                        break;
//                }
//            }
//        }
//        in.close();
//    }
}
