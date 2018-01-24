#define LSYS_STRING_PARSE_FUNC_DECL void parse_model_string(const QString& curve);

#define LSYS_STRING_PARSE_FUNC_DEF(CLASSNAME)                \
    void CLASSNAME::parse_model_string(const QString& curve) \
    {                                                        \
        for (const QChar& c : curve) {                       \
            if (c.isNull())                                  \
                break;                                       \
                                                             \
            if (c.isLetter()) {                              \
                add_segment();                               \
                continue;                                    \
            }                                                \
            if (c != '0' && c.isDigit()) {                   \
                qCritical("direct strokes not implemented"); \
            }                                                \
                                                             \
            switch (c.toLatin1()) {                          \
            case '+':                                        \
                incAngle();                                  \
                continue;                                    \
            case '-':                                        \
                decAngle();                                  \
                continue;                                    \
            case '0':                                        \
                continue;                                    \
            case '[':                                        \
                stackPush();                                 \
                continue;                                    \
            case ']':                                        \
                stackPop();                                  \
                continue;                                    \
            case '_':                                        \
                next_color();                                \
                continue;                                    \
            case '~':                                        \
                prev_color();                                \
                continue;                                    \
            default:                                         \
                qCritical(QString("not recognized symbol ")  \
                              .append(c)                     \
                              .append(" present in model")   \
                              .toLatin1());                  \
                break;                                       \
            }                                                \
        }                                                    \
    }
