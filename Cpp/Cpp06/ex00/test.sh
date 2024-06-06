#!/bin/sh

# ANSI color codes
GREEN='\033[0;32m'
NC='\033[0m'

./Conversion_of_scalar_types lorem
./Conversion_of_scalar_types c a
./Conversion_of_scalar_types 0 -42 42
./Conversion_of_scalar_types 332 111 114.2 -155.3 109.00
./Conversion_of_scalar_types 0.0f -4.2f 4.2f
./Conversion_of_scalar_types -inff +inff nanf
./Conversion_of_scalar_types -inf +inf nan
./Conversion_of_scalar_types 0 nan 42.0f
echo "${GREEN}test with int max ${NC}"
./Conversion_of_scalar_types 2147483647 2147483648 -2147483648 -2147483649 #int max
echo "${GREEN}test with float max ${NC}"
./Conversion_of_scalar_types 3.40282e+38 1.17550e-38 3.40283e+38 1.17549e-38 #float max
echo "${GREEN}test with double max ${NC}"
./Conversion_of_scalar_types 1.79769e+308 2.22508e-308 1.79770e+308 2.22507e-308 #double max