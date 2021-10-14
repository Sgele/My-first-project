#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <istream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Is_empty.h"

bool Is_empty(std::ifstream& pFile)
{
    return pFile.peek() != std::ifstream::traits_type::eof();
}