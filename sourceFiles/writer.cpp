//
// Created by User on 22.11.2025.
//

#include "writer.hpp"

std::string spaceWalker(int n) {

    std::string s;
    s += std::to_string(n);
    for (int i = 0; i < 10 - s.size(); ++i) { s += " "; }
    return s;
}

std::string SequenceWriter::writer(const std::string& format, SequencesBox sList, int idx) {

    std::string out;
    list = sList;

    if (prop.redactTitles != "SH"){
        for (int i = 0; i < sList.sequences.size(); ++i) {
            list.sequences[i].title = prop.redactTitles;
        }
    }

    std::vector<std::string> outs;
    if (format == "FASTA_general" || format == "FASTA_NCBI_common" || format == "FASTA_NCBI_db_link") {
        out += ">" + list.sequences[idx].title + "\n";
        for (int i = 0; i < list.sequences[idx].sequence.size(); ++i) {
            if (i % prop.lenghtOfLine == 0 && i) {out += "\n";}
            out += list.sequences[idx].sequence[i];
        }

        out += "\n\n";
    }

    if (format == "FASTA_bare") {

        for (int i = 0; i < list.sequences[idx].sequence.size(); ++i) {
            if (i % prop.lenghtOfLine == 0 && i) {out += "\n";}
            out += list.sequences[idx].sequence[i];
        }
        out += "\n\n";
    }
    if (format == "FASTA_GenBank") {
        if (prop.indOfSeqWhYNd == -1) {
            prop.indOfSeqWhYNd = 0;
        }
        out += "LOCUS       ";
        out += list.sequences[prop.indOfSeqWhYNd].title;
        if (!list.sequences[prop.indOfSeqWhYNd].titles.empty()){
            for (auto s: list.sequences[prop.indOfSeqWhYNd].titles){
                out += s;
            }
        }
        out += "\nORIGIN\n";
        out += spaceWalker(1);
        for (int i = 0; i < list.sequences[prop.indOfSeqWhYNd].sequence.size(); ++i) {
            if ((i % 10) == 0) { out += " "; }
            if ((i % 60) == 0) {
                out += spaceWalker(i + 1);
            }
            out += _tolower(list.sequences[prop.indOfSeqWhYNd].sequence[i]);
        }
        out += "\n//\n\n";
    }

    return out;
}

std::string PairWriter::writer(const std::string & format, PairBox pList) {
    list = pList;
    if (prop.redactTitles != "SH"){
        list.item.title = prop.redactTitles;
    }
    return "1";
}

std::string MSAWriter::writer(const std::string & format, MSABox mList) {
    list = mList;
    if (prop.redactTitles != "SH"){
        for (int i = 0; i < mList.items.size(); ++i) {
            for (int j = 0; j < mList.items.size(); ++j) {
                list.items[i].titles[j] = prop.redactTitles;
            }
        }
    }
    return "1";
}
