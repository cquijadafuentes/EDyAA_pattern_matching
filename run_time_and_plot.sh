#!/bin/bash

FECHA=$(date '+%A %d-%B, %Y - %T')
echo $FECHA > $ARCHIVO_SALIDA
PREF="miarray_time_"
PRED="data_"

make

for i in aleatorio inicio medio fin; do
	echo "n		linear		binary		doubling" > $PRED$i
	echo $PREF$i
	for g in 100000 200000 300000 400000 500000 600000 700000 800000 900000 1000000; do
		./$PREF$i $g 100 >> $PRED$i
	done
	echo '' >> $PRED$i
done

gnuplot < plot