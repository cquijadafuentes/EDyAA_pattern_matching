#!/bin/bash


echo $FECHA
SEARCHTIME="./text_search_time"
DATA="data_"
PREF_RAND="randomtxt_"
FILE_RAND="random_text"
PREF_DNA="dnatxt_"
FILE_DNA="_dna_text"

./_textoaleatorio 10000000 > ${FILE_RAND}

./_generar_archivos_prueba ${FILE_RAND} ${PREF_RAND} 10 10000000 1000 30 L
./_generar_archivos_prueba ${FILE_DNA} ${PREF_DNA} 10 10000000 1000 30 L

RAND_DATA_YES=${DATA}${PREF_RAND}"_n_yes"
RAND_DATA_NO=${DATA}${PREF_RAND}"_n_no"
RAND_DATA_YESNO=${DATA}${PREF_RAND}"_n_yesno"

DNA_DATA_YES=${DATA}${PREF_DNA}"_n_yes"
DNA_DATA_NO=${DATA}${PREF_DNA}"_n_no"
DNA_DATA_YESNO=${DATA}${PREF_DNA}"_n_yesno"

echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_YES}
echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_NO}
echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_YESNO}

echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_YES}
echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_NO}
echo '%n(text) n(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_YESNO}

for i in 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000; do
	${SEARCHTIME} ${PREF_RAND}"tx_"${i}".txt" ${PREF_RAND}"pt_yes_1000.txt" >> ${RAND_DATA_YES}
	${SEARCHTIME} ${PREF_RAND}"tx_"${i}".txt" ${PREF_RAND}"pt_no_1000.txt" >> ${RAND_DATA_NO}
	${SEARCHTIME} ${PREF_RAND}"tx_"${i}".txt" ${PREF_RAND}"pt_yn_1000.txt" >> ${RAND_DATA_YESNO}

	${SEARCHTIME} ${PREF_DNA}"tx_"${i}".txt" ${PREF_DNA}"pt_yes_1000.txt" >> ${DNA_DATA_YES}
	${SEARCHTIME} ${PREF_DNA}"tx_"${i}".txt" ${PREF_DNA}"pt_no_1000.txt" >> ${DNA_DATA_NO}
	${SEARCHTIME} ${PREF_DNA}"tx_"${i}".txt" ${PREF_DNA}"pt_yn_1000.txt" >> ${DNA_DATA_YESNO}
done


rm ${PREF_RAND}* ${PREF_DNA} ${FILE_RAND}
