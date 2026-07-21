 //
// Created by User on 03.12.2025.
//

#ifndef PROJECTFM_INTERFACE_HPP
#define PROJECTFM_INTERFACE_HPP

#include "globalConsts.hpp"
#include "sequences_files_format_descriptions.h"
#include "manager.hpp"

struct Interface{
    std::string urlUlt = "start https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRl5YY7s_PlmkasZD-YlWSGj-kvQW2UIg3aFA&s";
    std::string urlGit = "start https://github.com/jackobturboc/file-converter-for-bioinformatics";
    void MakeWorldRed();
    void getGit();
    Manager that;
};

#endif //PROJECTFM_INTERFACE_HPP
