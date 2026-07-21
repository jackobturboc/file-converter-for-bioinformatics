#include "container.hpp"

//гыгыгы

std::string SequencesBox::show(bool tit, bool seq, bool com, bool qua, bool isOut){ //debug only
    std::string s;
    int n = 0;
    for (auto that:sequences) {
        n++;
        s += "  -number " + std::to_string(n) + "\n";
        std::cout << "  -number " << std::to_string(n) << "\n";
        if (tit) {
            if (!that.title.empty()) {
                if (isOut) { std::cout << "title:" << that.title << "\n"; }
                s += "title:" + that.title + "\n";
            }
        }
        if (seq) {
            if (!that.sequence.empty()) {
                if (isOut) { std::cout << "sequence:" << that.sequence << "\n"; }
                s += "sequence:" + that.sequence.substr(0, 50) + "\n";
            }
        }
        if (com) {
            if (!that.comments.empty()) {
                if (isOut) { std::cout << "comment:" << that.comments << "\n"; }
                s += "comment:" + that.comments + "\n";
            }
        }
        if (qua) {
            if (!that.quality.empty() && !that.title_quality.empty()) {
                if (isOut) { std::cout << "quality:" << that.quality << "\n"; }
                if (isOut) { std::cout << "title_quality:" << that.title_quality << "\n"; }
                s += "quality:" + that.quality + "\n";
                s += "title_quality:" + that.title_quality + "\n";
            }
        }
        if (isOut) { std::cout << '\n'; }
        s += "\n";
    }
    return s;
}

void PairBox::show(bool tit, bool seq, bool com, bool qua){ //debug only
//    for (auto that:sequences) {
//        if (tit) { std::cout << "title:" << that.tittle << "\n"; }
//        if (seq) { std::cout << "sequence:" << that.sequence << "\n"; }
//        if (com) { std::cout << "comment:" << that.comments << "\n"; }
//        if (qua) { std::cout << "quality:" << that.quality << "\n";
//            std::cout << "title_quality:" << that.tittle_quality << "\n";}
//        std::cout << '\n';
//    }
}

void MSABox::show(bool tit, bool seq, bool com, bool qua){ //debug only
//    for (auto that:sequences) {
//        if (tit) { std::cout << "title:" << that.tittle << "\n"; }
//        if (seq) { std::cout << "sequence:" << that.sequence << "\n"; }
//        if (com) { std::cout << "comment:" << that.comments << "\n"; }
//        if (qua) { std::cout << "quality:" << that.quality << "\n";
//            std::cout << "title_quality:" << that.tittle_quality << "\n";}
//        std::cout << '\n';
//    }
}

SequencesBox::SequencesBox(){
    type.init();
}

PairBox::PairBox() {
    type.init();
}

MSABox::MSABox() {
    type.init();
}