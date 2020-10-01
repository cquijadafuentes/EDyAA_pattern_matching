#!/bin/bash


echo $FECHA
SEARCHTIME="./text_search_time"
DATA="data_eng"
FILETEXTO="_english_text"
PREFIJO="eng_text"

./_generar_archivos_prueba ${FILETEXTO} ${PREFIJO} 10 10000000 0 0 L
echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DATA}

for i in 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000; do
	${SEARCHTIME} ${PREFIJO}"tx_"${i}".txt" "_english_commonwords.txt" >> ${DATA}
done

gnuplot < plot

rm ${PREFIJO}*
