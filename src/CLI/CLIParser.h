#ifndef CLI_C_L_I_PARSER_H
#define CLI_C_L_I_PARSER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include<QCommandLineParser>
#include<QMultiMap>

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
    QMultiMap<QString,QCommandLineOption> m_registry;

private:
    CLIParser();
    Q_DISABLE_COPY(CLIParser);

public:
    static CLIParser* const getInstance();
    void addOptions(const QList<QCommandLineOption>&,QString pluginName );
    void parse();
    const QCommandLineParser& getParser() const;
    const QMultiMap<QString,QCommandLineOption>& getRegistry() const;




};

}  // namespace CLI
#endif
