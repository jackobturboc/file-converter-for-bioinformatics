#include "manager.hpp"

int Detector::fileFormatSearcher() {

    if (prop.pathToInp == "nothing") {
        return 4;
    }
    prop.log("RUN: detector start\n");
    std::string line;
    std::ifstream in(prop.pathToInp);
    if (in.is_open()) {
        std::getline(in, line);
        std::regex patternFNDL(">..||");
        if (std::regex_match(line, patternFNDL)) {
            format = "FASTA_NCBI_db_link";
            type = "seq";
        }
        std::regex patternNC("[A-Z][A-Z][0-9][0-9][0-9][0-9][0-9][0-9]");
        if (std::regex_match(line, patternNC)) {
            format = "NCBI_common";
            type = "seq";
        }
        if (line[0] == '>') {
            format = "FASTA_general";
            type = "seq";
        }
        if (line[0] == '@') {
            format = "FASTAQ_sanger";
            type = "seq";
        }

//        std::regex patternFGB("LOCUS");
        if (line.find("LOCUS") == 0) {
            format = "FASTA_GenBank";
            type = "seq";
        }
        if (line.find("ID") == 0) {
            format = "EMBL";
            type = "seq";
        }
        std::regex patternFQB("Query");
        if (std::regex_match(line, patternFQB)) {
//
        }
        std::regex patternC("CLUSTAL");
        if (std::regex_match(line, patternC)) {
//            std::cout << "CLUSTAL" << "\n";
        }
        std::regex patternN("#NEXUS");
        if (std::regex_match(line, patternN)) {
//            std::cout << "NEXUS" << "\n";
        } else {
            if (line[0] == '#') {
//                std::cout << "Stockholm" << "\n";
            }
        }
        std::regex patternM("!!");
        if (std::regex_match(line, patternM)) {
//            std::cout << "MSF" << "\n";
        }
        std::regex patternP("\\s*\\d+ \\d+");
        if (std::regex_match(line, patternP)) {
//            std::cout << "PHILIP" << "\n";
        }

        if (format.empty()) {
            if (isupper(line[0])){
                format = "FASTA_bare";
                if (prop.redactTitles != "SH") {
                    prop.codeOut = "ERROR: Unable to change title in FASTA_bare.\n";
                    prop.log("ERROR: Unable to change title in FASTA_bare.\n");
                }
            }
        }
    }
    in.close();
    AllSequencesFileFormatDescription temp;
    if (format.empty()) { return 1; }
    prop.log("RUN: detector finish\n");
    return 0;
}

void Manager::checkFormat() {
//    std::map<std::string, std::string> FASTA_NCBI_db_link;
    std::vector<std::string> formatsS = {
                                            "FASTA_NCBI_db_link",
                                            "FASTA_bare",
                                            "EMBL",
                                            "FASTA_GenBank",
                                            "FASTA_general",
                                            "NCBI_common",
                                            "FASTAQ_sanger"
                                         };
    std::map<std::string, std::vector<std::vector<std::string>>> formatBox {
            {"FASTA_NCBI_db_link",
               {
                   {"NCBI_common", "AG"},
                   {"FASTA_general", "AG"},
                   {"FASTA_bare", "loss of title"},
                   {"EMBL", "loss of multi title"},
                   {"FASTA_GenBank", "loss of multi title"},
                   {"FASTAQ_sanger", "loss of quality"}
               }
            },
                {"NCBI_common", {
                    {"FASTA_NCBI_db_link", "AG"},
                    {"FASTA_general", "AG"},
                    {"FASTA_bare", "loss of title"},
                    {"EMBL", "loss of multi title"},
                    {"FASTA_GenBank", "loss of multi title"},
                    {"FASTAQ_sanger", "loss of quality"}
                }
            },
            {"FASTA_GenBank", {
                    {"EMBL", "AG"}

                }
            },
            {"EMBL", { {"FASTA_GenBank", "AG"} }}
    };
    std::vector<std::string> formatsP = {}; // TODO add Pair irFiles
    std::vector<std::string> formatsM = {}; // TODO add MSAFiles
    if (!find(formatBox[fileType], fileType)) {
        if (!find(formatBox[fileType], fileType)) {

        }
    }

}

std::string Manager::writeT() {
    std::string tot;
    if (properties.indOfSeqWhYNd == -1) {
        if (fileType == "seq") {
            for (int i = 0; i < sList.sequences.size(); i++) {
                tot += sWriter.writer(properties.outFileTy, sList, i);
            }
        }
        if (fileType == "pair") {
            tot += pWriter.writer(properties.outFileTy, pList);
        }
        if (fileType == "msa") {
            for (int i = 0; i < mList.items.size(); i++) {
                tot += mWriter.writer(properties.outFileTy, mList);
            }
        }
    } else {
        if (fileType == "seq") { tot += sWriter.writer(properties.outFileTy, sList, properties.indOfSeqWhYNd); }
        if (fileType == "msa") { tot += mWriter.writer(properties.outFileTy, mList); }
    }
    return  tot;
}

bool Manager::write() {
    if (properties.indOfSeqWhYNd == -1) {
        std::ofstream out;
        out.open(properties.pathToOut);
        std::string file;
        if (out.is_open()) {
            std::string tot;
            if (fileType == "seq") {
                for (int i = 0; i < sList.sequences.size(); i++) {
                    tot += sWriter.writer(properties.outFileTy, sList, i);
                }
            }
            if (fileType == "pair") {
                out << pWriter.writer(properties.outFileTy, pList);
            }
            if (fileType == "msa") {
                for (int i = 0; i < mList.items.size(); i++) {
                    tot += mWriter.writer(properties.outFileTy, mList);
                }
            }
            out << tot;
            out.close();
        }
        else {
            properties.codeOut = "ERROR: Unable to change title in FASTA_bare.\n";
            properties.log("ERROR: Unable to change title in FASTA_bare.\n");
            return 0;
        }
        return 1;
    }
    std::ofstream out;
    out.open(properties.pathToOut);
    if (out.is_open()) {
        if (fileType == "seq")  { out << sWriter.writer(properties.outFileTy, sList, properties.indOfSeqWhYNd); }
        if (fileType == "msa")  { out << mWriter.writer(properties.outFileTy, mList); }
    }
    else {
        properties.codeOut = "ERROR: The file cannot be opened for writing. Check if it is open by another program.\n";
        properties.log("ERROR: The file cannot be opened for writing. Check if it is open by another program.\n");
        return 0;
    }
    out.close();
    return 1;
}

bool Manager::run(Properties & p) {
    if (properties.inpFileTy == "FASTA_bare" && properties.redactTitles == "SH"){
        properties.codeOut = "ERROR: The title is not set, when translating \"FASTA_bare\" you must set a title.\n";
        properties.log("ERROR: The title is not set, when translating \"FASTA_bare\" you must set a title.\n");
        return 0;
    }
    properties = p;

    properties.log("RUN: Start\n");

    detect.prop = properties;
    if (properties.inpFileTy == "AUTO") {
        switch (detect.fileFormatSearcher()) {

            case 0:
                properties.codeOut = "RUN: All good.\n";
                properties.log("RUN: All good.\n");
                break;
            case 1:
                properties.codeOut = "ERROR: Unrecognized type, try specifying the type manually.\n";
                properties.log("ERROR: Unrecognized type, try specifying the type manually.\n");
                return 0;
            case 2:
                properties.codeOut = "ERROR: Unable to change title in FASTA_bare.\n";
                properties.log("ERROR: Unable to change title in FASTA_bare.\n");
                return 0;
            case 3:
                properties.codeOut = "ERROR: File wasn't select.\n";
                properties.log("ERROR: File wasn't select.\n");
                return 0;
        }
    }
    fileType = detect.type;
    if (fileType == "seq") {
        sWriter.prop = properties;
        sReader.prop = properties;

        sList.format = detect.format;
        fileType = detect.type;
        sReader.parser(sList);
    } else if (fileType == "pair") {
        pWriter.prop = properties;
        pReader.prop = properties;

        pList.format = detect.format;
        fileType = detect.type;
        pReader.parser(pList);
    } else if (fileType == "msa") {
        mWriter.prop = properties;
        mReader.prop = properties;

        mList.format = detect.format;
        fileType = detect.type;
        mReader.parser(mList);
    } else {
        properties.codeOut = "ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n";
        properties.log("ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n");
    }


    if ((properties.indOfSeqWhYNd < -1) || (properties.indOfSeqWhYNd > sList.sequences.size())){
        properties.codeOut = "ERROR: Invalid satisfaction index\n";
        properties.log("ERROR: Invalid satisfaction index\n");
        return 0;
    }
    if (!write()) {
        return 0;
    }
}

bool Manager::doProperties() {
    properties.log("RUN: update properties start\n");
    detect.prop = properties;
    mReader.prop = properties;
    sReader.prop = properties;
    pReader.prop = properties;
    mWriter.prop = properties;
    sWriter.prop = properties;
    pWriter.prop = properties;
    properties.log("RUN: update properties finish\n");
    return 1;
}


bool Manager::getFiles() {
    properties.log("RUN: file get start\n");
    doProperties();
    if (properties.inpFileTy == "FASTA_bare" && properties.redactTitles == "SH"){
        properties.codeOut = "ERROR: The title is not set, when translating \"FASTA_bare\" you must set a title.\n";
        properties.log("ERROR: The title is not set, when translating \"FASTA_bare\" you must set a title.\n");
        return 0;
    }
    detect.prop = properties;
    if (properties.inpFileTy == "AUTO") {
        switch (detect.fileFormatSearcher()) {
        case 0:
            break;
        case 1:
            properties.codeOut = "ERROR: Unrecognized type, try specifying the type manually.\n";
            properties.log("ERROR: Unrecognized type, try specifying the type manually.\n");
            return false;
        case 2:
            properties.codeOut = "ERROR: Unable to change title in FASTA_bare.\n";
            properties.log("ERROR: Unable to change title in FASTA_bare.\n");
            return false;
        }
    }
    detect.prop = properties;
    if (fileType == "seq") {
        doProperties();
        sList.format = detect.format;
        fileType = detect.type;
        sReader.parser(sList);
    } else if (fileType == "pair") {
        doProperties();
        pList.format = detect.format;
        fileType = detect.type;
        pReader.parser(pList);
    } else if (fileType == "msa") {
        doProperties();
        mList.format = detect.format;
        fileType = detect.type;
        mReader.parser(mList);
    } else {
        properties.codeOut = "ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n";
        properties.log("ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n");
        return false;
    }
    properties.log("RUN: file get finish\n");
    return true;
}

bool Manager::writeFiles() {
    properties.log("RUN: writing start\n");
    doProperties();
    if (!write()) {
        return 0;
    }
    properties.log("RUN: writing finish\n");
    return 1;
}

bool Manager::editFiles(std::vector<int> index) {
    properties.log("RUN: delate files start \n");
    for (int n : index){
        editFilesSlave(n);
    }
    properties.log("RUN: delate files finish \n");
}

bool Manager::editFilesSlave(int idx) {
    properties.log("RUN: delate file " + std::to_string(idx) + " start \n");
    if (fileType == "seq") {
        sList.sequences.erase(sList.sequences.begin() + idx);
    } else if (fileType == "msa") {
        mList.items.erase(mList.items.begin() + idx);
    } else {
        properties.codeOut = "ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n";
        properties.log("ERROR: Unknown error, unable to determine SEQ/PAIR/MSA.\n");
        return false;
    }
    properties.log("RUN: delate file " + std::to_string(idx) + " finish \n");
    return 1;
}

int QualityConverter::getPherdScore(char character) {
    std::vector<int> qualityScoreIncoding = qualityScoreIncodingSolexa;
    int pherd_score = 0;
    if (prop.inpFileTy == "FASTAQ_solexa") {
        int solexa_score = static_cast<int>(character) - qualityScoreIncoding[0] - 5;
        if (solexa_score < -3) {
            pherd_score = 1;
        } else if (solexa_score < -1) {
            pherd_score = 2;
        } else if (solexa_score < 1) {
            pherd_score = 3;
        } else if (solexa_score < 3) {
            pherd_score = 4;
        } else if (solexa_score < 6) {
            pherd_score = 5;
        } else if (solexa_score < 9) {
            pherd_score = solexa_score + 1;
        } else if (solexa_score < 11) {
            pherd_score = 10;
        } else {
            pherd_score = round(10.0 * log10(pow(10.0, solexa_score / 10.0) + 1.0));
        }
    } else {
        pherd_score = static_cast<int>(character) - qualityScoreIncodingSolexa[0];
        if (prop.inpFileTy == "FASTAQ_illumina_v_1_5" && pherd_score == 2) {
            pherd_score = 0; // if I understand correctly
        }
    }
//    printf("%d ", pherd_score);
    return pherd_score;
}

char QualityConverter::getTargetCharacter(int pherd_score){
    std::vector<int> qualityScoreIncoding = qualityScoreIncodingSolexa;
    std::vector<int> qualityScoreRange = qualityScorerRangeSolexa;
    if (pherd_score > qualityScoreRange[1]) pherd_score = qualityScoreRange[1];
    char character = '!';
    if (prop.outFileTy == "FASTAQ_illumina_v_1_5" && pherd_score < 3) {
        pherd_score = 3;
        character = static_cast<char>(pherd_score + qualityScoreIncoding[0]);
    } else if (prop.outFileTy == "FASTAQ_solexa") {
        int solexa_score = 0;
        if (pherd_score > 9) {
            solexa_score = 10.0 * log10( pow(10.0, pherd_score/ 10.0) - 1.0);
            if (solexa_score >  qualityScoreRange[1]) {
                solexa_score = qualityScoreRange[1];
            }
        } else if (pherd_score > 6) {
            solexa_score = pherd_score - 1;
        } else if (pherd_score > 3) {
            solexa_score = pherd_score - 2;
        } else if (pherd_score == 3) {
            solexa_score = 0;
        } else if (pherd_score == 2) {
            solexa_score = -2;
        } else if (pherd_score == 1 || pherd_score == 0) {
            solexa_score = -5;
        }
        character = static_cast<char>(solexa_score + 5 + qualityScoreIncoding[0]);
    } else {
        character = static_cast<char>(pherd_score + qualityScoreIncoding[0]);
    }
    return character;
}

std::string QualityConverter::mainQualityConvertor(std::string & input_data) {
    std::string output_data;
    if (prop.outFileTy == prop.outFileTy) {
        output_data = input_data;
        return output_data;
    }
    for (char ch : input_data){
        int pherd_score = getPherdScore(ch);
        output_data += getTargetCharacter(pherd_score);
    }
    return output_data;
}