#! /bin/bash

sqlite_name="sqlite-autoconf-3510100"

if [ ! -f ${sqlite_name}.tar.gz ]; then
    rm -rf ${sqlite_name}
    wget https://sqlite.org/2025/${sqlite_name}.tar.gz
fi

if [ ! -d ${sqlite_name} ]; then
    tar zxvf ${sqlite_name}.tar.gz
    cd ${sqlite_name}
    ./configure
    make -j $(ps -eLf | wc -l)
fi

echo "sqlite build done"