# PaoProject - ZOO

## UML
![Schema UML](https://github.com/DavidePicc/PaoProject/blob/main/prova.drawio.svg)

Animale (virtual):  
- name:
- age:
- weight:
- type:AnimalType

## Come compilare
- Clonare la repository
- Posizionarsi in "PaoProject/ZOO"
- Eseguire il comando "qmake -project"
- Aggiungere alla fine del file ZOO.pro
    - QT += widgets
    - QT += gui
- Eseguire il comando "make"
- Eseguire il comando "./ZOO"

### Leone:
M - C
-Ruggito: Misura in boh
-Criniera: Si/No


### Coccodrillo:
R - C
-Lunghezza:
-Dentatura: numero denti

### Pavone:
U - O
-Apertura Ruota: raggio


### Giraffa:
M - E
-LunghezzaCollo:
-Altezza:


### TartarugaGigante:
R - E
-MisuraGuscio: lunghezza …


### Struzzo:
U - O
Velocità=km/h

## AnimalType:
Bool erbivoro=
bool carnivoro=false
ClasseAnimale: Mammifero / Rettile / Uccello

## Gabbia (container)
ZOO vettore ridefinito
## ZooAppPage:

## Idee: 
- Ridefinire cout<< per finestra caratteristiche
- Ridefinire il + per riprodurre animali
- Classe animalType (per non fare il diamante)

Contenitore gabbia: mappa o vector


# Mail Zanella
![image](https://github.com/DavidePicc/PaoProject/assets/119404292/abe76a90-d797-452e-a342-e836a7666a11)

