#pragma once
#include "Model/LSYSModel.h"

namespace ViewModel {

class ModelStringParser {
protected:
    //Commands to be implemented by format specific child class
    virtual void add_segment() = 0;
    virtual void next_color() = 0;
    virtual void prev_color() = 0;
    virtual void incAngle() = 0;
    virtual void decAngle() = 0;
    virtual void stackPush() = 0;
    virtual void stackPop() = 0;

    //common parsing code
    void parse_model_string(const QString&);

public:
    virtual ~ModelStringParser() {}
};
}
