title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Sudoku  (数独)
class: segue dark

---
title: Sudoku
figure: images/corda/Sudoku.svg

- Il sudoku ( 数独 ) è un gioco di logica nel quale al giocatore viene proposta una griglia di 9×9 celle, ciascuna delle quali può contenere un numero da 1 a 9, oppure essere vuota
- La griglia è suddivisa in 9 righe orizzontali, nove colonne verticali e, da bordi in neretto, in 9 "sottogriglie", chiamate regioni, di 3×3 celle contigue.
- Le griglie proposte al giocatore hanno da 20 a 35 celle contenenti un numero.
- Scopo del gioco è quello di riempire le caselle bianche con numeri da 1 a 9, in modo tale che in ogni riga, colonna e regione siano presenti tutte le cifre da 1 a 9 e, pertanto, senza ripetizioni.
 
---

title: Gioco risolto
class: large-image

![](images/corda/Sudoku_solution.svg)
 
---

title: Soluzione ingenua (G&T) Generate and Test 

- Si inserisce un numero *in ogni cella vuota*
- Si *verifica* che le regole del gioco siano rispettate
- Se qualche regola non è rispettata si *prova* con altri numeri
- Complessità
    - Il numero totale di celle è 81
    - supponendo riempite 31 celle ne rimangono 50
    - il numero di combinazioni possibili da provare è 9<sup>50</sup> (circa 5*10<sup>47</sup>)
    - supponendo 1 nanosecondo per formulare una combinazione il tempo previsto è circa . . .
 
---

title: ... calcoliamo
class: big
build_lists: true

- 1 anno = 365 giorni
- 1 anno = 8760 ore
- 1 anno = 525600 minuti
- 1 anno = 3.154 x 10<sup>7</sup> secondi
- 1 anno = 3.154 x 10<sup>16</sup> nanosecondi
- 5 x 10<sup>47</sup> / 3.154 x 10<sup>16</sup> = 10<sup>31</sup> anni
- Età dell'universo ... 10<sup>10</sup> anni :(
 
