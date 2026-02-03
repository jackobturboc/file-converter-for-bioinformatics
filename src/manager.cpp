#include "manager.hpp"

//void Detector::fileFormatSearcher(std::string fileAddress){
//    std::string line;
//    std::ifstream in(fileAddress);
//    if (in.is_open()) {
//        std::getline(in, line);
//
//        std::regex patternFNDL(">..||");
//        if (std::regex_match(line, patternFNDL)) {
//            list.format = "FASTA_NCBI_db_link";
////            std::cout << "FASTA_NCBI_db_link" << "\n";
//        }
//        std::regex patternNC("[A-Z][A-Z][0-9][0-9][0-9][0-9][0-9][0-9]");
//        if (std::regex_match(line, patternNC)){
//            list.format = "NCBI_common";
////            std::cout << "NCBI_common" << "\n";
//        }
//        std::regex patternFG(">");
//        if (std::regex_match(line, patternFG)){
//            list.format = "FASTA_general";
////            std::cout << "FASTA" << "\n";
//        }
//        std::regex patternFQS("@{1}");
//        if (std::regex_match(line, patternFQS)){
//            list.format = "FASTAQ_sanger";
////          std::cout << "FASTAQ_sanger" << "\n";
//        }
//        std::regex patternFGB("LOCUS");
//        if (std::regex_match(line, patternFGB)) {
//            list.format = "FASTA_GenBank";
////          std::cout << "GENBANK" << "\n";
//        }
//        std::regex patternFQB("Query");
//        if (std::regex_match(line, patternFQB)) {
////            std::cout << "BLAST" << "\n";
//        }
//        std::regex patternC("CLUSTAL");
//        if (std::regex_match(line, patternC)) {
////            std::cout << "CLUSTAL" << "\n";
//        }
//        std::regex patternN("#NEXUS");
//        if (std::regex_match(line, patternN)) {
////            std::cout << "NEXUS" << "\n";
//        } else {
//            if (line[0] == '#'){
////                std::cout << "Stockholm" << "\n";
//            }
//        }
//        std::regex patternM("!!");
//        if (std::regex_match(line, patternM)) {
////            std::cout << "MSF" << "\n";
//        }
//        std::regex patternP("\\s*\\d+ \\d+");
//        if (std::regex_match(line, patternP)){
////            std::cout << "PHILIP" << "\n";
//        }
//        if (list.format == ""){
//            list.format = "FASTA_bare";
//        }
//    }
//    in.close();
//    AllSequencesFileFormatDescription temp;
//    list.formatDescription = temp.dlst[list.format];
//    return "seq";
//}

int Detector::fileFormatSearcher() {
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
        std::regex patternFQS("@{1}");
        if (std::regex_match(line, patternFQS)) {
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
    std::vector<std::string> formatsP = {}; // TODO add Pa irFiles
    std::vector<std::string> formatsM = {}; // TODO add MSAFiles
    if (!find(formatBox[fileType], fileType)) {
        if (!find(formatBox[fileType], fileType)) {

        }
    }

}

bool Manager::write() {
    if (properties.indOfSeqWhYNd == -1) {
        std::ofstream out;
        out.open(properties.pathToOut);
        std::string file;

        if (out.is_open()) {
            std::string tot;
            if (fileType == "seq") {
                for (int i = 0; i < sList.sequences.size(); ++i) {
                    tot += sWriter.writer(properties.outFileTy, sList, i);
                }
            }
            if (fileType == "pair") {
                out << pWriter.writer(properties.outFileTy, pList);
                return 1;
            }
            if (fileType == "msa") {
                for (int i = 0; i < mList.items.size(); ++i) {
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

    properties.log("RUN: Start");

    detect.prop = properties;
    if (properties.inpFileTy == "AUTO") {
        switch (detect.fileFormatSearcher()) {
            case 0:
                break;
            case 1:
                properties.codeOut = "ERROR: Unrecognized type, try specifying the type manually.\n";
                properties.log("ERROR: Unrecognized type, try specifying the type manually.\n");
                return 0;
            case 2:
                properties.codeOut = "ERROR: Unable to change title in FASTA_bare.\n";
                properties.log("ERROR: Unable to change title in FASTA_bare.\n");
                return 0;
        }
    }

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

    if (!write()){
        return 0;
    }
    return 1;
}