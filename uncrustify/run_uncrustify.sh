#!/bin/bash

find .. -maxdepth 1 -name "*.c" > uncrustify_file_list.txt
find .. -maxdepth 1 -name "*.h" >> uncrustify_file_list.txt

uncrustify --no-backup -c uncrustify.cfg -F uncrustify_file_list.txt
