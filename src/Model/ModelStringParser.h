#pragma once

#define LSYS_STRING_PARSE_FUNC_DECL unsigned int parse_model_string(const QString& curve);

/*
 * Use of this macro needs include of QString in the target class
 * This exists to allow for inlining of the submethods implemented in the classes that use this parser
 * XXX: Obviously dirty. As this motehod is crucial to program runtime and inlining of the submethods is necessary,
 * this rules out a template/composite approach with virtual methods, since those are not inlined (at least by gcc)
 * on -O2
 */
#define LSYS_STRING_PARSE_FUNC_DEF(CLASSNAME)                        \
    unsigned int CLASSNAME::parse_model_string(const QString& curve) \
    {                                                                \
        unsigned int segcount = 0;                                   \
        for (const QChar& c : curve) {                               \
            if (c.isNull())                                          \
                break;                                               \
                                                                     \
            if (c.isLetter()) {                                      \
                add_segment();                                       \
                segcount++;                                          \
                continue;                                            \
            }                                                        \
            if (c != '0' && c.isDigit()) {                           \
                qCritical("direct strokes not implemented");         \
            }                                                        \
                                                                     \
            switch (c.toLatin1()) {                                  \
            case '+':                                                \
                incAngle();                                          \
                continue;                                            \
            case '-':                                                \
                decAngle();                                          \
                continue;                                            \
            case '0':                                                \
                continue;                                            \
            case '[':                                                \
                stackPush();                                         \
                continue;                                            \
            case ']':                                                \
                stackPop();                                          \
                continue;                                            \
            case '_':                                                \
                next_color();                                        \
                continue;                                            \
            case '~':                                                \
                prev_color();                                        \
                continue;                                            \
            default:                                                 \
                qCritical(QString("not recognized symbol ")          \
                              .append(c)                             \
                              .append(" present in model")           \
                              .toLatin1());                          \
                break;                                               \
            }                                                        \
        }                                                            \
        if (segcount == 0) {                                         \
            qFatal("Model String contained no segment chars");       \
        }                                                            \
        return segcount;                                             \
    }
