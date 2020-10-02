#!/bin/bash


echo $FECHA
SEARCHTIME="./text_search_rk_time_colissions"
DATA="data_collission_"
TEXT_RAND="_rand_text"
TEXT_DNA="_dna_text"
TEXT_ENG="_english_text"
PAT_RAND="_rand_pt_yn_1000.txt"
PAT_DNA="_dna_pt_yn_1000.txt"
PAT_ENG="_english_commonwords.txt"
RAND_DATA=${DATA}"rand"
DNA_DATA=${DATA}"dna"
ENG_DATA=${DATA}"eng"

make

CABECERA="%n(text) n(patron) q t_rabinkarp colisionesRK"

echo ${CABECERA} > ${RAND_DATA}
echo ${CABECERA} > ${DNA_DATA}
echo ${CABECERA} > ${ENG_DATA}

echo 'Iniciando pruebas'
for i in 101 1009 10007 100003 1000003; do
	echo "Probando q=${i} ..."
	${SEARCHTIME} ${TEXT_RAND} ${PAT_RAND} ${i} >> ${RAND_DATA}
	${SEARCHTIME} ${TEXT_DNA} ${PAT_DNA} ${i} >> ${DNA_DATA}
	${SEARCHTIME} ${TEXT_ENG} ${PAT_ENG} ${i} >> ${ENG_DATA}
done

gnuplot < plot_colissions

make clean
