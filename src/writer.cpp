//
// Created by User on 22.11.2025.
//

#include "writer.hpp"

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
    if (format == "FASTA_GENBANK") {
        out += "LOCUS       ";
        out += list.sequences[0].title;
        if (!list.sequences[0].titles.empty()){
            for (auto s: list.sequences[0].titles){
                out += s;
            }
        }
        out += "ORIGIN\n";
        out += "\n\n";
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