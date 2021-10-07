#!/bin/bash

set -e
set -x

if [ $# -ne 1 ]
then
	echo "Expected one argument: <path-to-compiled-binary>"
	exit 1
fi

SSHPORT=10085
scp -P $SSHPORT $1 root@127.0.0.1:/root
ssh -p $SSHPORT root@127.0.0.1 -t "/root/$(basename $1)"
