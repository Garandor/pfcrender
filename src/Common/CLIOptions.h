/**
 * @file CLIOptions.h
 * This file is the central storage of all commandline options used by built-in classes - i.e. anything that's not a plugin.
 * \sa https://github.com/Garandor/pfcrender/issues/14 for why this is needed
 * This map is created when the CLIParser runs and extended by options exported from plugins
 */
#ifndef CLIOPTS_H
#define CLIOPTS_H

#include <QCommandLineOption>
#include <QPair>

namespace Common {

const std::vector<QPair<QString, QCommandLineOption>> builtin_opts{

    //Options for rendering the ViewModel
    { "ViewModel.InitialAngle", QCommandLineOption("ia", "initial angle of first curve segment (0 = right)", "0 - 360") },
    { "ViewModel.Angle", QCommandLineOption("a", "angle of turns for each segment", "0 - 360") },
    { "ViewModel.SegmentLength", QCommandLineOption("sl", "length of segment in pixels", "360") },
    { "ViewModel.SegmentWidth", QCommandLineOption("sw", "stroke width for segment rendering in pixels", "integer") }
};
}

#endif
