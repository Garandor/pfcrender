#ifndef CLI_C_L_I_PARSER_H
#define CLI_C_L_I_PARSER_H

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QString>
#include <QVector>

namespace Common {
/**
 * @brief The CLIParser class
 * This class gathers commandline options from all plugins and executes on the
 * This happens during construction of CLIParser
 */
class CLIParser {
private:
    QCommandLineParser m_parser;
    QHash<QString, QCommandLineOption> m_optlist;

public:
    CLIParser();

public:
    void addOption(const QString& optName, const QCommandLineOption& option);
    void addOption(const QPair<QString, QCommandLineOption>&);
    void parse();
    const QCommandLineParser& getParser() const;
    const QHash<QString, QCommandLineOption>& getOptlist() const;
};

} // namespace Common
#endif
