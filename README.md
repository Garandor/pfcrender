PFCRender v0.8.0
=========================================================

|                                                                     | Linux/Mac                                                                                                                       | Windows  |
|:-:|---|---|
| __[master](https://github.com/Garandor/pfcrender/tree/master)__     | [![Linux Build Status](https://travis-ci.org/Garandor/pfcrender.svg?branch=master)](https://travis-ci.org/Garandor/pfcrender)   | [![Windows Build status](https://ci.appveyor.com/api/projects/status/sj2a1l3akbe4v2pt/branch/master?svg=true)](https://ci.appveyor.com/project/Garandor/pfcrender/branch/master)|
| __[develop](https://github.com/Garandor/pfcrender/tree/develop)__   | [![Linux Build Status](https://travis-ci.org/Garandor/pfcrender.svg?branch=deveop)](https://travis-ci.org/Garandor/pfcrender)  | [![Windows Build Status](https://ci.appveyor.com/api/projects/status/sj2a1l3akbe4v2pt/branch/develop?svg=true)](https://ci.appveyor.com/project/Garandor/pfcrender/branch/develop) |

[![Coverage Status](https://codecov.io/gh/Garandor/pfcrender/branch/master/graph/badge.svg)](https://codecov.io/gh/Garandor/pfcrender)

# Commandline interface (Curve generation via CLI only atm)
[bindir]/src/pfcrender lsys --it 5 --rules "F_+F_+F_+F_ F F+F+F-F-F + + - - _ _"


When compiled with GUI support, the curve is always rendered 

Actions are listed as positional arguments and executed in order. Names correspond to the plugins that get executed.
Currently available:
- lsys : Generate a model string from an iterated lindenmeyer system. Runs JJ's stringsubst tool as backedn
- stdout : Dump model string to console
- svg : Export model to a SVG file

Plugins bring switches (syntax --opname optvalue) for configuration, execute pfcrender -h for info on what is available.

All switches are cached and re-read on the next execution so they have to be provided only on changes.


Scrolling in UI via Drag&Drop, zoom via Ctrl+Mousewheel

# Documentation
The documentation for this project is hosted on [GitHub Pages](https://garandor.github.io/pfcrender/)  and re-generated by doxygen on every master branch commit build on Travis CI

# TBI
- Generation of beveled turns on screen (implemented for SVG)
- pdf, bitmap export plugin

# Credits
- The [fxtlib](http://jjj.de/fxt/fxtpage.html)'s stringsubst module written by Joerg Arndt and released under GPLv3 is used for import of Lindenmeyer systems
