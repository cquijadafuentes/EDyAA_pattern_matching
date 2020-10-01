reset

set terminal png size 800,600
set grid
set key out horiz

set yrange [1:200000]
set ylabel "Tiempo [us]" font ",18"

set key font ",16"
set tics font ",12"

set style line 1 linecolor rgb "blue" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 2 linecolor rgb "red" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 1 linecolor rgb "blue" dashtype 8 linewidth 1.5 pointtype 6 pointsize 1.5



set xtics 100
set xrange [50:1050]
set xlabel "Tamaño del patrón (m)" font ",18"

set output 'data_dna_m_no.png'
plot 'data_dna_m_no' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3
set output 'data_dna_m_yes.png'
plot 'data_dna_m_yes' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3
set output 'data_dna_m_yesno.png'
plot 'data_dna_m_yesno' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3


set output 'data_rand_m_no.png'
plot 'data_rand_m_no' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3
set output 'data_rand_m_yes.png'
plot 'data_rand_m_yes' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3
set output 'data_rand_m_yesno.png'
plot 'data_rand_m_yesno' u 2:3 w lp t 'FuerzaBruta' ls 1, '' u 2:4 w lp t 'BooyerMoore' ls 2, '' u 2:5 w lp t 'RabinKarp' ls 3



set xtics ("1x10^5" 1000000, "2x10^5" 2000000, "3x10^5" 3000000, "4x10^5" 4000000, "5x10^5" 5000000, "6x10^5" 6000000, "7x10^5" 7000000, "8x10^5" 8000000, "9x10^5" 9000000, "10x10^5" 10000000)
set xrange [500000:10500000]
set xlabel "Tamaño del texto (n)" font ",18"

set output 'data_dna_n_no.png'
plot 'data_dna_n_no' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3
set output 'data_dna_n_yes.png'
plot 'data_dna_n_yes' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3
set output 'data_dna_n_yesno.png'
plot 'data_dna_n_yesno' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3


set output 'data_rand_n_no.png'
plot 'data_rand_n_no' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3
set output 'data_rand_n_yes.png'
plot 'data_rand_n_yes' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3
set output 'data_rand_n_yesno.png'
plot 'data_rand_n_yesno' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3


set output 'data_eng.png'
plot 'data_eng' u 1:3 w lp t 'FuerzaBruta' ls 1, '' u 1:4 w lp t 'BooyerMoore' ls 2, '' u 1:5 w lp t 'RabinKarp' ls 3
