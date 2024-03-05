(🇮🇹 version below)  
Report in both 🇬🇧 and 🇮🇹 in "_Project report_" files

# Object Oriented Programming project

### Introduction

The aim of the project is to develop a C++ application on a freely chosen theme subject to mandatory constraints, equipped with a graphical user interface (GUI) implemented using the Qt framework. The project can be developed by a single student or by a pair of students and should require approximately 50 hours of individual work. The GUI can freely draw inspiration from both desktop and mobile system applications. Architectural design of the GUI can adhere to either the Model-View-Controller or Model-View design patterns. Qt includes a set of view classes that use a Model/View architecture to manage the relationship between the logical data of the GUI and how it is presented to the GUI user. The Qt framework is equipped with comprehensive and precise documentation that will be the main reference guide in GUI development, in addition to offering the QtCreator IDE and QtDesigner tool. The application may also apply commonly used design patterns in C++.


### Constraints

The project must satisfy the following mandatory constraints:
1. Be an original work of the student or group of students
2. Be entirely written in C++
3. Include a graphical interface implemented in Qt
4. Compile without errors on the provided virtual machine (warnings during compilation are tolerated, although generally penalized)
5. Implement a class hierarchy with at least three concrete classes for individually completed projects, or at least five concrete classes for group projects
6. Allow creation, modification, and deletion of objects in the hierarchy
7. Natively implement at least one container for objects of the hierarchy, which should expose at least one method for insertion, one for reading, one for deletion, and one for searching based on some criterion; illustratively, a container can be a singly linked list, a doubly linked list, a blockchain, a set, or a tree
8. Realize data persistence in any form for individually completed projects, or in a structured format (JSON, XML, ...) for group projects
9. Maintain a clear separation between the logical model and the graphical interface, meaning that the model code must be reusable without depending on the interface; it is permissible for model code to use Qt tools not related to the interface, such as I/O functions or classes for JSON management
10. Implement the principles of encapsulation and information hiding of object-oriented programming: a class must abstract a single concept and include all the attributes and methods it needs with appropriate visibility levels
11. Use polymorphism in a non-trivial manner; some examples of trivial usage are virtual destructors, getter methods that return slightly different information depending on the invoking object, getType methods that return a string containing the type of the object; conversely, non-trivial usage of polymorphism can be achieved with methods that perform different operations depending on the concrete type of the object, such as constructing a different graphical widget depending on the object to be displayed; many design patterns require non-trivial usage of polymorphism and can therefore provide excellent suggestions
12. Execute efficiently and robustly, without runtime errors
13. Be accompanied by a report, in Italian or English, of up to 8 pages with 10pt text that includes:  
(a) name, surname, and student ID number of all group members (or the single author in the case of individually completed projects)  
(b) a brief introduction explaining the chosen theme  
(c) description of the logical model  
(d) description of non-trivial usage of polymorphism  
(e) description of the method used for data persistence  
(f) description of the implemented functionalities  
(g) reporting of the expected and actual hours worked  
(h) only for group projects: task division  
(i) only for resubmitted projects: a section detailing the changes made; in case of resubmission without changes, it is preferable to still include this section indicating that there were no changes

### Evaluation Criteria

The project is evaluated based on the mandatory constraints and implemented functionalities. Specifically, if one or more mandatory constraints are not met, the project will be considered insufficient, and a resubmission in one of the subsequent appeals will be required. Conversely, if all mandatory constraints are satisfied, the project is considered (at least) sufficient, and the evaluation will increase based on the quality of the developed functionalities and, to a lesser extent, based on the quality of the report.

A functionality is evaluated positively based on its relevance to the chosen theme, utility, usability, complexity, and quality of the code through which it is implemented. Simpler or generic functionalities improve the evaluation, although not as much as more complex or articulated ideas.

Keyboard shortcuts, for example, are simple generic improvements that can be obtained with a few lines of code in Qt, as well as window resizing management or icon usage. On the other hand, integration with an API system or the use of databases such as SQL or MongoDB for persistence are significantly more complex and require the writing of dedicated classes.

The quality of the report, while having a minor impact, will be evaluated based on completeness, clarity, and cohesion. Obvious linguistic errors such as systematic lack of punctuation or frequent typographical errors will be penalized. The report can be written in Italian or English, at the author's discretion. The choice of language will not affect the evaluation.

Since the course does not cover GUI usability or aesthetic rendering, their absence will not be penalized as long as it does not affect the correct functioning of the program. However, if the project is developed with attention to these themes, a bonus will be recognized as if it were an additional functionality.

<br><br>
---
<br><br>

# Progetto programmazione ad oggetti
### Introduzione

Lo scopo del progetto è lo sviluppo in C++ di un’applicazione a tema libero soggetta a vincoli obbligatori dotata di un’interfaccia grafica (GUI) realizzata mediante il framework Qt. Il progetto potrà essere sviluppato da un singolo studente oppure da una coppia di studenti e dovrà richiedere approssimativamente 50 ore di lavoro complessivo individuale. La GUI può liberamente trarre ispirazione sia da applicazioni per sistemi desktop che app per sistemi mobile. Si potrà aderire ai design pattern Model-View-Controller o Model-View per la progettazione architetturale della GUI. Qt include un insieme di classi view che usano una architettura Model/View per gestire la relazione tra i dati logici della GUI ed il modo in cui essi sono presentati all’utente della GUI. Il framework Qt è dotato di una documentazione completa e precisa che sarà la principale guida di riferimento nello sviluppo della GUI, oltre ad offrire l’IDE QtCreator ed il tool QtDesigner. L’applicazione potrà anche applicare design pattern comunemente utilizzati in C++.


### Vincoli

Il progetto deve obbligatoriamente soddisfare i seguenti vincoli:
1. Essere un lavoro originale dello studente o del gruppo di studenti
2. Essere interamente scritto in C++
3. Prevedere un’interfaccia grafica realizzata in Qt
4. Compilare senza errori sulla macchina virtuale fornita (sono tollerati, sebbene generalmente penalizzati, i warning durante la compilazione)
5. Implementare una gerarchia di classi con almeno tre classi concrete per i progetti svolti singolarmente, o almeno cinque classi concrete per i progetti svolti in gruppo
6. Consentire la creazione, la modifica e la cancellazione degli oggetti della gerarchia
7. Implementare nativamente almeno un contenitore per oggetti della gerarchia, il quale dovrà esporre almeno un metodo per l’inserimento, uno per la lettura, uno per la cancellazione e uno per la ricerca in base a qualche criterio; a titolo esemplificativo e non esaustivo un contenitore può essere una lista singolarmente collegata, doppiamente collegata, una blockchain, un insieme o un albero
8. Realizzare la persistenza dei dati in una qualsiasi forma per i progetti svolti singolarmente, o in un formato strutturato (JSON, XML, . . . ) per i progetti svolti in gruppo
9. Mantenere una separazione netta tra il modello logico e l’interfaccia grafica, ovvero il codice del modello deve poter essere riutilizzabile senza dipendere dall’interfaccia; nulla vieta che il codice del modello utilizzi strumenti di Qt non legati all’interfaccia, come le funzioni di I/O o le classi per la gestione di JSON
10. Realizzare i principi di incapsulamento e information hiding della programmazione a oggetti: una classe deve astrarre un singolo concetto e includere tutti gli attributi e metodi di cui ha bisogno con opportuni livelli di visibilità
11. Utilizzare il polimorfismo in maniera non banale; alcuni esempi di utilizzo banale sono i distruttori virtuali, metodi getter che restituiscono informazioni leggermente diverse a seconda dell’oggetto di invocazione, metodi getType che restituiscono una stringa contenente il tipo dell’oggetto; per contro un utilizzo non banale del polimorfismo si può ottenere con metodi che svolgono operazioni diverse a seconda del tipo concreto dell’oggetto, come costruire un widget grafico diverso a seconda dell’oggetto da mostrare; molti design pattern richiedono un utilizzo del polimorfismo non banale e possono pertanto fornire ottimi spunti
12. Eseguire in maniera efficiente e robusta, senza errori a runtime
13. Essere corredato di una relazione, in lingua italiana o inglese, di massimo 8 pagine con testo a 10pt che riporti:  
(a) nome, cognome e numero di matricola di tutti i componenti del gruppo (o del singolo autore in caso di progetto svolto singolarmente)  
(b) una breve introduzione che spieghi il tema scelto  
(c) la descrizione del modello logico  
(d) la descrizione dell’utilizzo non banale del polimorfismo  
(e) la descrizione del metodo utilizzato per la persistenza dei dati  
(f) la descrizione delle funzionalità implementate  
(g) la rendicontazione delle ore previste e di quelle effettivamente svolte  
(h) solo per progetti svolti in gruppo: la suddivisione delle attività  
(i) solo per progetti riconsegnati: una sezione che riporta le modifiche apportate; in caso di riconsegna senza modifiche è preferibile aggiungere comunque questa sezione indicando che non ci sono state modifiche

### Criteri di valutazione

Il progetto viene valutato sulla base dei vincoli obbligatori e delle funzionalità implementate. Più precisamente, se uno o più vincoli obbligatori non risultano soddisfatti il progetto verrà considerato insufficiente e sarà necessaria una riconsegna in uno degli appelli successivi. Viceversa, se tutti i vincoli obbligatori sono soddisfatti il progetto è considerato (almeno) sufficiente e la valutazione aumenterà in base alla qualità delle funzionalità sviluppate e, in misura minore, in base alla qualità della relazione.

Una funzionalità viene valutata positivamente in base alla sua pertinenza al tema scelto, all’utilità, all’usabilità, alla complessità e alla qualità del codice attraverso cui è implementata. Funzionalità più semplici o generiche migliorano la valutazione, sebbene non tanto quanto idee più complesse o articolate.

Le scorciatoie da tastiera, per esempio, sono migliorie generiche semplici da ottenere con poche righe di codice in Qt, così come la gestione del ridimensionamento delle finestre o l’uso di icone. Per contro l’integrazione con un sistema di API o l’uso di basi di dati come SQL o MongoDB per la persistenza sono significativamente più complessi e richiedono la scrittura di classi apposite.

La qualità della relazione, pur avendo un’incidenza minore, verrà valutata sulla base della completezza della chiarezza e della coesione. Errori linguistici evidenti come sistematica mancanza di punteggiatura o errori di battitura frequenti verranno penalizzati. È possibile redigere la relazione in Italiano o Inglese, a propria discrezione. La scelta della lingua non avrà effetti sulla valutazione.

Poiché il corso non tratta di usabilità o resa estetica della GUI la loro mancanza non verrà penalizzata, purché questo non pregiudichi il corretto funzionamento del programma. Tuttavia, se il progetto viene sviluppato ponendo attenzione a questi temi, verrà riconosciuto un bonus come se si trattasse di una funzionalità aggiuntiva.