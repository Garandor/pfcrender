#include "ModelStringParser.h"

namespace ViewModel {

void ModelStringParser::parse_model_string(const QString& curve)
{
    for (const QChar& c : curve) {
        if (c.isNull()) // String is \0 terminated, end loop
            break;

        if (c.isLetter()) // Denotes drawing a line segment
        {
            add_segment();
            continue;
        }
        if (c != '0' && c.isDigit()) {
            // Direct strokes, e.g., for terdragon:
            // stringsubst 3 1 1 121 2 232 3 313 | tail -1 | ./bin 3 2 1 1 0.15 >
            // tmp-pic.tex && make dotex #
            // TODO: bin mir nicht sicher, ob und wie wir diesen hack unterstuetzen
            // wollen
            qCritical("direct strokes not implemented");
        }

        switch (c.toLatin1()) {
        case '+': // change dir clockwise
            incAngle();
            continue;
        case '-': // change dir counterclockwise
            decAngle();
            continue;
        case '0': // ignored (as symbol for "no turn")
            continue;
        case '[': // push position and direction on stack
            stackPush();
            continue;
        case ']': // pop position and direction from stack
            stackPop();
            continue;
        case '_': // special command:  next color
            next_color();
            continue;
        case '~': // special command:  previous color
            prev_color();
            continue;
        default:
            qCritical(QString("not recognized symbol ")
                          .append(c)
                          .append(" present in model")
                          .toLatin1());
            break;
        }
    }
}
}
