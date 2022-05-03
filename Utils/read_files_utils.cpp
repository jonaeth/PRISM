//
// Created by jonathan on 03/05/2022.
//

#include "read_files_utils.h"

Relation parse_line_info(std::string line) {
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end()); //Strip White Space
    size_t pos = 0;
    Relation relation;
    while ((pos = line.find_first_of(",()")) != std::string::npos) { //Split the line by ',' or '(' or ')'
        if (relation.predicate.empty()){
            relation.predicate = line.substr(0, pos);
        }else{
            relation.arguments.push_back(line.substr(0, pos));
        }
        line.erase(0, pos + 1);
    }
    return relation;
}

GroundRelation parse_line_db(std::string line) {
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end()); //Strip White Space
    size_t pos = 0;
    GroundRelation relation;
    relation.weight = 1.0;
    while ((pos = line.find_first_of(",():")) != std::string::npos) { //Split the line by ',' or '(' or ')'
        if (relation.predicate.empty()){
            relation.predicate = line.substr(0, pos);
        }else if(line[pos] == ':'){
            std::string weight_string = line.substr(pos+1, std::string::npos);
            if(!weight_string.empty()){
                relation.weight = stod(weight_string);
            }
        }else{
            relation.arguments.push_back(line.substr(0, pos));
        }
        line.erase(0, pos + 1);
    }
    return relation;
}