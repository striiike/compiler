//
// Created by hiccup on 2023/9/27.
//

#ifndef COMPILER_COMPUNIT_HPP
#define COMPILER_COMPUNIT_HPP


#include <utility>
#include <vector>
#include "define.hpp"

class CompUnit {
public:
    explicit CompUnit(std::vector<DeclPtr> declPtrs, std::vector<FuncDefPtr> funcDefPtrs,
                      MainFuncDefPtr mainFuncDefPtr)
            : declPtrs(std::move(declPtrs)), funcDefPtrs(std::move(funcDefPtrs)),
              mainFuncDefPtr(std::move(mainFuncDefPtr)) {}

private:
    std::vector<DeclPtr> declPtrs;
    std::vector<FuncDefPtr> funcDefPtrs;
    MainFuncDefPtr mainFuncDefPtr;
};


#endif //COMPILER_COMPUNIT_HPP