#!/bin/bash

read -p "File name: " file_name

echo "#include <${file_name}.h>" > "./src/${file_name}.cpp" 

echo "#pragma once
namespace Takka {
    class ${file_name}
    {
    };
}" > "./include/${file_name}.h"