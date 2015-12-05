#!/bin/bash

#----------------------------------------------------------------------------
# command > file, command >> file
# command < file
# FileDescriptor > file
# FD >> file    # FD: 0, 1, 2
# FD1 >& FD2
# FD1 <& FD2
#----------------------------------------------------------------------------

# command > file 2>&1
# command < fileA > fileB

# command << delimiter
#     document
# delimiter
#
# TAG is a user-defined delimiter.
# 结尾的TAG要顶格写，且前后无任何字符 
wc -l << TAG
    line1
    line2
TAG

# /dev/null file
# redirect to /dev/null so as to not display on screen
