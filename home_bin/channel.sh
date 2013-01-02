#!/bin/sh
for ((i=14;i<63;i++))
do
  echo recording channel $i
  /usr/local/bin/recpt1 --strip --b25 $i 30 test$i.ts &> /dev/null
done
