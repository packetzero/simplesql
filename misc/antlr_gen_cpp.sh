#!/bin/bash
DIR=`dirname $0`
cd $DIR
antlr -Dlanguage=Cpp -lib .. -o ../gencpp -no-listener -visitor ./SQLite.g4
