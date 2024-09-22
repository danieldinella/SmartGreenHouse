### Guida all'Utilizzo del Software "Smart GreenHouse" ###

1. **Creazione del Database:**

Assicurati di avere i diritti sulla cartella, poi procedi eseguendo lo script di creazione del database. Vai alla directory Implementazione/Components/db-scripts e lancia il comando:
    ./create.sh

2. **Compilazione dei Componenti:**

Utilizza make per compilare ogni componente del software. Vai alla directory Implementazione/Components e, per ciascun componente, esegui:
    make

3. **Avvio del Software:**

Avvia il software utilizzando tre terminali separati:

Terminale 1:

Vai alla directory Implementazione/Components.
Esegui lo script esegui_main.sh:
    ./esegui_main.sh

Terminale 2:

Vai alla directory Implementazione/Components/Software/bin.
Esegui il binario main:
    ./main

Terminale 3:

Vai alla directory Implementazione/Components/Command/bin.
Esegui il binario main:
    ./main

4. **Interazione e Monitoraggio:**

Attendi le interazioni tra le tre componenti che avverranno in modo automatico.

5. **Accesso al Database:**

Per visualizzare e analizzare il database della "Smart GreenHouse", segui questi passi:

Connettiti al database utilizzando il comando psql:

    psql -h localhost -p 5433 -U smartgreenhouse -d logdb_smartgreenhouse

6. **Visualizzazione delle Tabelle:**

Per vedere tutte le tabelle nel database, esegui:

    \dt

7. **Accesso ai Dati:**

Per accedere ai dati della tabella con i log, utilizza il comando SELECT:

    SELECT * FROM logdb;

Il database contiene una tabella per ciascun componente e una tabella generale con tutte le componenti eseguite in quel ciclo.