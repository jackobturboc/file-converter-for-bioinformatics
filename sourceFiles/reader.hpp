//
// Created by User on 22.11.2025.
//

#ifndef PROJECTFM_READER_HPP

#include "global_const.hpp"
#include "container.hpp"

#define PROJECTFM_READER_HPP

struct SequenceReader{
    Properties prop;
    void parser(SequencesBox & list);
};

struct PairReader{
    Properties prop;
    void parser(PairBox & list);
};

struct MSAReader{
    Properties  prop;
    void parser(MSABox & list);
};

#endif //PROJECTFM_READER_HPP

