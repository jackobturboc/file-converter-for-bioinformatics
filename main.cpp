#include <iostream>
#include "global_const.hpp"

int get_time_from_start(){
    return time(NULL) - time_of_start;
}

enum class Operation: char {fasta=0, fasta_q=1};

struct sequence_unif{
    int format;
    std::vector<std::string> sequences;
    std::vector<std::string> qual;
    std::string titlevmk;

};

void log(std::string message, bool err){
    std::ofstream out;
    out.open("log.txt");
    if (out.is_open())
    {
        if (err){
            out << "[ " << get_time_from_start << " ms ] " << message << " EROR " << std::endl;
            int a = 1 / 0;
        }
        else {
            out << "[ " << get_time_from_start << " ms ] " << message << std::endl;
        }

    }
    out.close();
}

int main() {
    log("all good", 0);
    log("all bad", 0);
    return 0;
}
