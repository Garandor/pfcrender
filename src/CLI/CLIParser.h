#ifndef CLI_C_L_I_PARSER_H
#define CLI_C_L_I_PARSER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include<QCommandLineParser>

namespace CLI
{
/**
 * @brief The CLIParser class
 * This class gathers commandline options from all plugins and executes on the
 * This happens during construction of CLIParser
 */
class CLIParser
{
private:
    static CLIParser* instance;
    QCommandLineParser m_parser;

private:
    CLIParser();
    Q_DISABLE_COPY(CLIParser);

public:
    static CLIParser* const getInstance();
    void addOptions(const QList<QCommandLineOption>& );
    void parse();


};

}  // namespace CLI
#endif
