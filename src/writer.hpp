///
// Created by User on 22.11.2025.
//

#ifndef PROJECTFM_WRITER_HPP
#define PROJECTFM_WRITER_HPP

#include "sequences_files_format_descriptions.h"
#include "global_const.hpp"
#include "container.hpp"

struct SequenceWriter{
    SequencesBox list;
    Properties prop;
    std::string writer(const std::string& format, SequencesBox sList, int idx);
};

struct PairWriter{
    PairBox list;
    Properties prop;
    std::string writer(const std::string& format, PairBox pList);
};

struct MSAWriter{
    MSABox list;
    Properties prop;
    std::string writer(const std::string& format, MSABox mList);
};

#endif //PROJECTFM_WRITER_HPP
