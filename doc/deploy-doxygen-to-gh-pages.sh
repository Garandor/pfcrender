#!/bin/bash

set -o errexit
set -o nounset

# config
git config --global user.email "nobody@nobody.org"
git config --global user.name "Travis CI"

pwd

cd ../bin

make doc

# deploy
cd doc/doc/html
git init
git add .
git commit -m "Deploy to Github Pages"
git push --force --quiet "https://garandor:${GITHUB_TOKEN}@github.com/garandor/${GITHUB_REPO}.git" master:gh-pages > /dev/null 2>&1
