# ContoCorrenteCheckCredito
### **Programma C++ dove si analizzano le informazioni sui movimenti di un conto corrente bancario.**


Le informazioni sui movimenti di un conto corrente bancario
(in euro) sono inserite in un array utilizzando una struttura Movimento. Ogni movimento
del conto è specificato secondo il seguente formato:
• data: nel formato gg/mm/aaaa
• importo del movimento espresso come numero reale positivo
• dal segno + (entrata) o - (uscita).

Un esempio di tale formato è riportato di seguito:

```{r class.source="bg-danger", class.output="bg-warning"}
01/01/2020 1200.00 +
20/01/2020 100.50 -
05/02/2020 523.10 +
10/02/2020 3000.00 -
14/02/2020 1430.23 -
20/03/2020 1555.55 +
01/04/2020 56.00 +
```

Questi movimenti sono memorizzati come campo di una struttura ContoCorrente
che, oltre all’array di movimenti mov con il relativo numero di movimenti n_mov contiene
anche il numero del conto cc ed il saldo iniziale saldo_i.
Si scriva una funzione check_credito che abbia come parametri un conto corrente e
un limite di credito c (con c < 0), e restituisca la posizione del movimento alla cui data il
saldo è sceso sotto il valore limite c. Nel caso in cui il saldo non scenda mai sotto tale
valore, la funzione deve restituire la posizione dell’ultimo movimento più uno.
Nell’esempio precedente se il saldo iniziale è di 2000.00 euro e c = −500.00, la
funzione restituisce la posizione 4. Se invece c = −1000.00, la funzione restituisce la
posizione 7.
Si scriva anche un main che verifichi il funzionamento della function stampando la
data in cui il credito ha superato il limite oppure segnalare che il conto non ha superato il
limite di credito.

***Tratto da: http://www.diegm.uniud.it/schaerf/Fondamenti/***

> ## **TO-DO:**
>-) Correggere errore su calcolo del saldo totale finale.
