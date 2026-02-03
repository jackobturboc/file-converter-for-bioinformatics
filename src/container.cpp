#include "container.hpp"

void SequencesBox::show(bool tit, bool seq, bool com, bool qua){ //debug only
    for (auto that:sequences) {
        if (tit) { std::cout << "title:" << that.title << "\n"; }
        if (seq) { std::cout << "sequence:" << that.sequence << "\n"; }
        if (com) { std::cout << "comment:" << that.comments << "\n"; }
        if (qua) { std::cout << "quality:" << that.quality << "\n";
                   std::cout << "title_quality:" << that.title_quality << "\n";}
        std::cout << '\n';
    }
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