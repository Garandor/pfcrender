#include "CLIParser.h"
#include <QDebug>

namespace Common {
CLIParser* CLIParser::instance = NULL;

CLIParser::CLIParser()
    : m_parser{}
    , m_optlist{}
{
    m_parser.setApplicationDescription("pfcrender"); //TODO: Append version string
    m_parser.addHelpOption();
    m_parser.addVersionOption();
    //    m_parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    //    m_parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    // A boolean option with a single name (-p)
    //    QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));

    // A boolean option with multiple names (-f, --force)
    //    QCommandLineOption forceOption(QStringList() << "f" << "force",
    //            QCoreApplication::translate("main", "Overwrite existing files."));
    //    m_parser.addOption(forceOption);

    // An option with a value
    //    QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
    //            QCoreApplication::translate("main", "Copy all source files into <directory>."),
    //            QCoreApplication::translate("main", "directory"));
    //    m_parser.addOption(targetDirectoryOption);
}

CLIParser* CLIParser::getInstance()
{
    if (instance == NULL)
        instance = new CLIParser;
    return instance;
}

void CLIParser::addOption(const QString& optName, const QCommandLineOption& option)
{
    m_parser.addOption(option);
    m_optlist.insert(optName, option);

    qDebug() << "Added option " << optName << " : " << o.description();
}

void CLIParser::addOption(const QPair<QString, QCommandLineOption>& p)
{
    CLIParser::addOption(p.first, p.second);
}

void CLIParser::parse()
{
    m_parser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
    // Process the actual command line arguments given by the user
    m_parser.process(*(qApp->instance()));

    //    const QStringList args = m_parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)

    //    bool showProgress = m_parser.isSet(showProgressOption);
    //    bool force = m_parser.isSet(forceOption);
    //    QString targetDir = m_parser.value(targetDirectoryOption);
}

const QCommandLineParser& CLIParser::getParser() const
{
    return m_parser;
}

} // namespace Common
