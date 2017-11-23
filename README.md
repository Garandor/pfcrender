PFCRender v0.5.0
=========================================================

|                                                                     | Linux/Mac                                                                                                                       | Windows  |
|:-:|---|---|
| __[master](https://github.com/Garandor/pfcrender/tree/master)__     | [![Linux Build Status](https://travis-ci.org/Garandor/pfcrender.svg?branch=master)](https://travis-ci.org/Garandor/pfcrender)   | [![Windows Build status](https://ci.appveyor.com/api/projects/status/sj2a1l3akbe4v2pt/branch/master?svg=true)](https://ci.appveyor.com/project/Garandor/pfcrender/branch/master)|
| __[testing](https://github.com/Garandor/pfcrender/tree/testing)__   | [![Linux Build Status](https://travis-ci.org/Garandor/pfcrender.svg?branch=testing)](https://travis-ci.org/Garandor/pfcrender)  | [![Windows Build Status](https://ci.appveyor.com/api/projects/status/sj2a1l3akbe4v2pt/branch/testing?svg=true)](https://ci.appveyor.com/project/Garandor/pfcrender/branch/testing) |

[![Coverage Status](https://coveralls.io/repos/github/Garandor/pfcrender/badge.svg?branch=feat%2Fcommon%2FCodeCoverage)](https://coveralls.io/github/Garandor/pfcrender)

# Commands for testing (Curve generation per CLI only atm)
[bindir]/src/pfcrender lsys --it 5 --rules "F_+F_+F_+F_ F F+F+F-F-F + + - - _ _"

Scrolling in UI via Drag&Drop, zoom via Ctrl+Mousewheel

# Documentation
The documentation for this project is hosted on [GitHub Pages](https://garandor.github.io/pfcrender/)  and re-generated by doxygen on every master branch commit build on Travis CI

# Planned features
- Rendering of user-specified lsys computed until a user-specified iterate to screen
- Generation of beveled turns for better visualzation of non-intersection of a PFC
- export of the above to several formats, including pdf, svg, tikz-picture for latex import, rasterization to some bitmapped image format e.g. jpg, png
- Commandline access to all non-interactive features of the GUI
- Operation on Linux, OSX and Windows systems

# Credits
- This project uses the [fxtlib](http://jjj.de/fxt/fxtpage.html) written by Joerg Arndt and released under GPLv3
