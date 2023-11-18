//
// Created by hiccup on 2023/10/7.
//

#include "../nodes-include/PrimaryExp.h"
#include "../nodes-include/Exp.h"
#include "../nodes-include/LVal.h"

PrimaryExp::PrimaryExp(ExpPtr exp, LValPtr lVal, NumberPtr number)
	: expPtr(std::move(exp)), lValPtr(std::move(lVal)),
	  numberPtr(std::move(number)) {
	name = "<PrimaryExp>";
	print();
}

LValPtr PrimaryExp::getLValPtr() { return lValPtr; }

NumberPtr PrimaryExp::getNumberPtr() { return numberPtr; }

ExpPtr PrimaryExp::getExpPtr() { return expPtr; }

void PrimaryExp::checkError(ErrorCtxPtr ctx, ErrorRetPtr ret) {
	auto _ret = make_shared<ErrorRet>();

	if (expPtr)
		expPtr->checkError(ctx, _ret);
	else if (lValPtr)
		lValPtr->checkError(ctx, _ret);
	else if (numberPtr)
		numberPtr->checkError(ctx, _ret);

	ret->dim = _ret->dim;
}

int PrimaryExp::evaluate() {
	if (expPtr)
		return expPtr->evaluate();
	else if (lValPtr)
		return lValPtr->evaluate();
	else if (numberPtr)
		return numberPtr->evaluate();
	return 0;
}

Value *PrimaryExp::llvmIr() {
	if (expPtr)
		return expPtr->llvmIr();
	else if (lValPtr)
		return lValPtr->llvmIr();
	else if (numberPtr)
		return numberPtr->llvmIr();
	return nullptr;
}