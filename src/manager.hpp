//
// Created by User on 23.11.2025.
//

#ifndef PROJECTFM_MANAGER_HPP
#define PROJECTFM_MANAGER_HPP

#include "sequences_files_format_descriptions.h"
#include "global_const.hpp"
#include "container.hpp"
#include "reader.hpp"
#include "writer.hpp"

template <typename T >
bool find(const std::vector<std::vector<T>> & list, const T & target){
    for (auto s:list) {
        if (s[0] == target) {
            return true;
        }
    }
    return false;
}

struct  Detector{
    Detector() { aSD.init(); }
    std::string format;
    std::string type;
    Properties prop;
    SequenceFileFormatDescript sD;
    AllSequencesFileFormatDescription aSD;
    int fileFormatSearcher();
};

struct Manager{
    Properties properties;
    SequencesBox sList;
    PairBox pList;
    MSABox mList;
    Detector detect;
    SequenceReader sReader;
    PairReader pReader;
    MSAReader mReader;
    SequenceWriter sWriter;
    PairWriter pWriter;
    MSAWriter mWriter;
    void checkFormat();
    std::string fileType;
    bool stopValve = 0;
    std::string codeOut;
    bool run(Properties & prop);
private:
    bool write();
};



#endif //PROJECTFM_MANAGER_HPP