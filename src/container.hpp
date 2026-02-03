//
// Created by User on 23.11.2025.
//

#ifndef PROJECTFM_CONTAINER_HPP
#define PROJECTFM_CONTAINER_HPP

#include "sequences_files_format_descriptions.h"
#include "global_const.hpp"

struct SequenceItem{
    void clear(){
        title.clear();
        sequence.clear();
        comments.clear();
        quality.clear();
        title_quality.clear();
        titles.clear();
    }
    std::string title;
    std::string sequence;
    std::string comments;
    std::string quality;
    std::string title_quality;
    std::vector<std::string> titles;
};

struct PairItem{
    void clear(){
        title.clear();
        sequenceOne.clear();
        sequenceTwo.clear();
    }
    std::string title;
    std::string sequenceOne;
    std::string sequenceTwo;
};

struct MSAItem{
    void clear(){
        sequences.clear();
        titles.clear();
    }
    std::vector<std::string> sequences;
    std::vector<std::string> titles;
};

struct SequencesBox{
    SequencesBox();
    SequenceFileFormatDescript formatDescription;
    AllSequencesFileFormatDescription type;
    std::string format;
    std::vector<SequenceItem> sequences;
    void show(bool tit, bool seq, bool com, bool qua);
};

struct PairBox{
    PairBox();
    SequenceFileFormatDescript formatDescription;
    AllSequencesFileFormatDescription type;
    std::string format;
    PairItem item;
    void show(bool tit, bool seq, bool com, bool qua);
};

struct MSABox{
    MSABox();
    SequenceFileFormatDescript formatDescription;
    AllSequencesFileFormatDescription type;
    std::string format;
    std::vector<MSAItem> items;
    void show(bool tit, bool seq, bool com, bool qua);
};
#endif //PROJECTFM_CONTAINER_HPP


