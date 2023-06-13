# Progetto Air Quality

## Descrizione del progetto
Il progetto Air Quality si propone di monitorare la qualità dell'aria utilizzando Arduino e una serie di sensori. L'obiettivo è raccogliere dati sulle principali componenti dell'aria, come la presenza di gas inquinanti e le particelle sospese, al fine di valutare la qualità complessiva dell'ambiente circostante.

## Componenti del progetto
Il progetto fa uso dei seguenti componenti e sensori:

1. Arduino Nano 33 IoT: Una piattaforma open-source di prototipazione elettronica che viene utilizzata come base per il progetto.
2. Sensori aggiuntivi:
   - CCS811 Adafruit: Un sensore di gas che rileva la presenza di anidride carbonica (CO2) e composti organici volatili (VOC) nell'aria.
   - PMS 5003: Un sensore di particelle sospese nel PM2.5 e PM10, che misura la quantità di particelle fini nell'aria.
   - Multichannel Gas Sensor della Groove Seed: Un sensore che rileva la presenza di vari gas inquinanti come monossido di carbonio (CO), ammoniaca (NH3) e benzene (C6H6).
   - Sensore di temperatura DHT11: Un sensore che misura la temperatura e l'umidità ambiente.

## Linguaggio di programmazione
Il progetto Air Quality viene implementato utilizzando il linguaggio di programmazione C/C++ con l'IDE di Arduino.

## Arduino Cloud e file thingProperties.h
Arduino Cloud è una piattaforma basata su cloud che offre un'interfaccia web per monitorare e controllare i dispositivi Arduino. Nel contesto del progetto Air Quality, è possibile utilizzare Arduino Cloud per visualizzare i dati raccolti dai sensori e controllare eventuali azioni associate.

Il file "thingProperties.h" contiene le variabili che devono essere utilizzate nell'interfaccia web di Arduino Cloud per monitorare i sensori e visualizzare i dati corrispondenti. Questo file definisce le proprietà del dispositivo che devono essere registrate sulla piattaforma. Le variabili incluse possono essere personalizzate in base alle specifiche del progetto.

## File Gerber per la creazione del PCB
Per coloro che desiderano creare il proprio PCB per il progetto Air Quality, è disponibile un file Gerber. I file Gerber contengono le informazioni necessarie per la produzione dei circuiti stampati. Utilizzando il file Gerber, è possibile inviare i dati a un produttore di PCB per ottenere il proprio circuito stampato personalizzato.

## Contenuti del repository
Il repository del progetto contiene i seguenti file:

- `AirQuality.ino`: Il file principale del codice Arduino che gestisce la lettura dei sensori e l'invio dei dati a Arduino Cloud.
- `thingProperties.h`: Il file che definisce le variabili e le proprietà del dispositivo per l'interfaccia web di Arduino Cloud.
- `Gerber.zip`: L'archivio ZIP contenente il file Gerber per la creazione del PCB.

## Guida all'installazione e all'utilizzo
Per installare e utilizzare il progetto Air Quality, seguire i seguenti passaggi:

1. Collegare i sensori al dispositivo Arduino secondo lo schema di collegamento fornito.
2. Aprire il file `AirQuality.ino` con l'IDE di Arduino.
3. Caricare il codice sul dispositivo Arduino.
4. Modificare il file `thingProperties.h` per adattarlo alle specifiche del proprio progetto e all'interfaccia web di Arduino Cloud.
5. Configurare e registrare il dispositivo su Arduino Cloud seguendo le istruzioni fornite dalla piattaforma.
6. Utilizzare l'interfaccia web di Arduino Cloud per monitorare i sensori e visualizzare i dati raccolti.

## Contributi e supporto
Sono benvenuti contributi e suggerimenti per migliorare il progetto Air Quality. 

## Licenza
Il progetto Air Quality è rilasciato sotto la licenza [MIT License](https://opensource.org/licenses/MIT). Fare riferimento al file LICENSE per ulteriori informazioni.