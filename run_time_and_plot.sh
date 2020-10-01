#!/bin/bash


echo $FECHA
SEARCHTIME="./text_search_time"
DATA="data_"
PREF_RAND="randomtxt_"
FILE_RAND="random_text"
PREF_DNA="dnatxt_"
FILE_DNA="_dna_text"

make
./_textoaleatorio 10000000 > ${FILE_RAND}

./_generar_archivos_prueba ${FILE_RAND} ${PREF_RAND} 10 10000000 1000 30 L
./_generar_archivos_prueba ${FILE_DNA} ${PREF_DNA} 10 10000000 1000 30 L

RAND_DATA_YES=${DATA}"rand_n_yes"
RAND_DATA_NO=${DATA}"rand_n_no"
RAND_DATA_YESNO=${DATA}"rand_n_yesno"

DNA_DATA_YES=${DATA}"dna_n_yes"
DNA_DATA_NO=${DATA}"dna_n_no"
DNA_DATA_YESNO=${DATA}"dna_n_yesno"

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



RAND_DATA_YES=${DATA}"rand_m_yes"
RAND_DATA_NO=${DATA}"rand_m_no"
RAND_DATA_YESNO=${DATA}"rand_m_yesno"

DNA_DATA_YES=${DATA}"dna_m_yes"
DNA_DATA_NO=${DATA}"dna_m_no"
DNA_DATA_YESNO=${DATA}"dna_m_yesno"

echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_YES}
echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_NO}
echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${RAND_DATA_YESNO}

echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_YES}
echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_NO}
echo '%n(text) m(patron) t_fuerzabruta t_boyermoore t_rabinkarp' > ${DNA_DATA_YESNO}

for i in 100 200 300 400 500 600 700 800 900 1000; do
	${SEARCHTIME} ${PREF_RAND}"tx_10000000.txt" ${PREF_RAND}"pt_yes_"${i}".txt" >> ${RAND_DATA_YES}
	${SEARCHTIME} ${PREF_RAND}"tx_10000000.txt" ${PREF_RAND}"pt_no_"${i}".txt" >> ${RAND_DATA_NO}
	${SEARCHTIME} ${PREF_RAND}"tx_10000000.txt" ${PREF_RAND}"pt_yn_"${i}".txt" >> ${RAND_DATA_YESNO}

	${SEARCHTIME} ${PREF_DNA}"tx_10000000.txt" ${PREF_DNA}"pt_yes_"${i}".txt" >> ${DNA_DATA_YES}
	${SEARCHTIME} ${PREF_DNA}"tx_10000000.txt" ${PREF_DNA}"pt_no_"${i}".txt" >> ${DNA_DATA_NO}
	${SEARCHTIME} ${PREF_DNA}"tx_10000000.txt" ${PREF_DNA}"pt_yn_"${i}".txt" >> ${DNA_DATA_YESNO}
done

./run_time_and_plot_eng.sh

gnuplot < plot

rm ${PREF_RAND}* ${PREF_DNA}* ${FILE_RAND}*
make clean
