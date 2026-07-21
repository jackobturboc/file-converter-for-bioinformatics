//
// Created by User on 23.11.2025.
//

#ifndef PROJECTFM_MANAGER_HPP
#define PROJECTFM_MANAGER_HPP

#include "sequences_files_format_descriptions.h"
#include "globalConsts.hpp"
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

struct QualityConverter{
    std::vector<int> qualityScoreIncodingSolexa = {59, 126};
    std::vector<int> qualityScoreIncodingSanger = {33, 126};
    std::vector<int> qualityScoreIncodingIllumina_v1_0 = {59, 126};
    std::vector<int> qualityScoreIncodingIllumina_v1_3 = {64, 126};
    std::vector<int> qualityScoreIncodingIllumina_v1_5 = {64, 126};
    std::vector<int> qualityScorerRangeSolexa = {-5, 63};
    std::vector<int> qualityScoreRangeSanger = {0, 93};
    std::vector<int> qualityScoreRangeIllumina_v1_0 = {-5, 63};
    std::vector<int> qualityScoreRangeIllumina_v1_3 = {0, 62};
    std::vector<int> qualityScoreRangeIllumina_v1_5 = {3, 62};
    Properties prop;
    SequencesBox * sList;
    QualityConverter(SequencesBox * sL){
        sList = sL;
    }
    int getPherdScore(char character);
    char getTargetCharacter(int pherd_score);
    std::string mainQualityConvertor(std::string & input_data);
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
    std::string writeT();
    void checkFormat();
    std::string fileType;
    bool stopValve = 0;
    std::string codeOut;
    bool run(Properties & prop);
    bool getFiles();
    bool doProperties();
    bool writeFiles();
    bool editFiles(std::vector<int> index);
    bool write();
private:
    bool editFilesSlave(int idx);
};



#endif //PROJECTFM_MANAGER_HPP
