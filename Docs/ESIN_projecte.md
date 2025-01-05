# Projecte d’ESIN

# Normativa i Enunciat

Tardor de 2024

Aquest document és llarg però és imprescindible que el llegiu íntegrament i amb
deteniment, àdhuc si sou repetidors, ja que es donen les instruccions i normes que heu
de seguir per a que el vostre projecte sigui avaluat positivament. El professorat de l’as-
signatura donarà per fet que tots els alumnes coneixen el contingut íntegre d’aquest
document.

## Continguts:

**1 Normativa 3**

**2 Enunciat del projecte 5**

**3 Disseny modular 7**

**4 El mòdulword_toolkit 9**

**5 La classediccionari 10**

**6 La classeanagrames 13**

**7 La classeiter_subset 15**

**8 El mòdulobte_paraules 17**

### 1


- 9 Errors
- 10 Documentació


## 1 Normativa

1. Tal i com s’explica a la Guia Docent, per a assolir els objectius de l’assignatura es
    considera imprescindible el desenvolupament per part de l’estudiant d’un projecte
    que requereix algunes hores addicionals de treball personal, apart de les classes de
    laboratori, on es fa el desenvolupament dels altres exercicis pràctics que permeten
    familiaritzar-vos amb l’entorn de treball i el llenguatge de programació C++.
2. El projecte es realitzarà en equips de dos estudiants. Si un d’ells abandona, un
    dels integrants ho haurà de notificar amb la màxima promptitud via e-mail a
    jordi.esteve@upc.edui, eventualment, continuar el projecte en solitari. D’al-
    tra banda, només es permetrà la formació d’equips individuals en casos excepcio-
    nals on sigui impossible reunir-se o comunicar-se amb altres estudiants, i s’haurà
    de justificar mitjançant algun tipus de document.
3. El suport que fareu servir per aquest projecte és el llenguatge de programació C++
    (específicament el compilador GNUg++-13.2.0) sobre l’entorn Linux del STIC.
    Això no és obstacle per al desenvolupament previ en PCs o similars. De fet, exis-
    teixen compiladors de C++per a tota classe de plataformes i hauria de ser senzill
    el trasllat des del vostre equip particular a l’entorn del STIC, especialment si tre-
    balleu amb GNU/Linux en el vostre PC.
    Atenció: Existeix la possibilitat de petites incompatibilitats entre alguns compila-
    dors de C++. En tot cas és imprescindible que feu almenys una comprovació final
    que el programa desenvolupat en PC o similar funciona correctament en l’entorn
    Linux del STIC (us podeu connectar remotament al servidorubiwan.epsevg.upc.edu).
4. El projecte serà avaluat mitjançant:
    - la seva execució en l’entorn Linux del STIC amb una sèrie dejocs de provai
    - la correcció del disseny, implementació i documentació: les decisions de dis-
       seny i la seva justificació, l’eficiència dels algorismes i estructures de dades,
       la legibilitat, robustesa i estil de programació, etc. Tota la documentació ha
       d’acompanyar el codi; no heu de lliurar cap documentació en paper.

```
Existeixen dos tipus de jocs de prova: públics i privats. Els jocs de prova públics
per a que podeu provar el vostre projecte estaran a la vostra disposició amb ante-
lació suficient al Campus Digital (https://atenea.upc.edu).
La nota del projecte es calcula a partir de la nota d’execució (E) i la nota de disseny
(D). La nota total és:
P= 0. 5 E+ 0. 5 D
si ambdues notes parcials (EiD) són majors que 0;P= 0si la nota de disseny és
0.
El capítol G delManual de laboratori d’ESINdescriu, entre altres coses, les situacions
que originen una qualificació de 0 en el disseny (i per tant una qualificació de 0 del
projecte). La nota d’execució (E) és 3 punts com a mínim si s’han superat els jocs
```

```
de prova públics; en cas contrari, la nota és 0. Els jocs de prova privats poden
aportar fins a 7 punts més, en cas que s’hagin superat els jocs de prova públics.
```
5. La data límit del lliurament final és el 12 de gener de 2025 a les 23h del vespre.
    Si un equip no ha lliurat el projecte llavors la nota serà 0. Al Campus Digital
    (https://atenea.upc.edu) es donaran tots els detalls sobre el procediment de
    lliurament del projecte.
6. No subestimeu el temps que haureu d’esmerçar a cadascun dels aspectes del pro-
    jecte: disseny, codificació, depuració d’errors, proves, documentació,...


## 2 Enunciat del projecte

Avui en dia els telèfons mòbils intel·ligents són un aparell més dins la nostra vida. I
els utilitzem no només per trucar o enviar missatges sinó també per navegar per internet,
com a càmera de fotos o per jugar. La clau de l’èxit dels telèfons intel·ligents radica
en les seves funcionalitats que es poden configurar al gust de l’usuari afegint petites
aplicacions (les anomenades apps).

L’objectiu d’aquest projecte és implementar un conjunt de classes i mòduls que per-
metin jugar a jocs de paraules com Apalabrados, Word twist, Word challenge, Scrabble,
Penjat i similars, que s’han tornat a posar de moda gràcies a les seves versions per a
telèfons intel·ligents. En aquests jocs hem de formar paraules usant les lletres que ens
proporcionen, normalment en un tauler dividit en caselles i amb algunes caselles espe-
cials amb puntuació extra.

En aquest tipus de jocs les estructures de dades juguen un paper fonamental doncs
cal evitar càlculs complexos durant l’execució del joc. En aquest projecte ens centrarem
justament en aquesta part, i no farem les parts corresponents a la interfície visual, con-
trol de temps, càlcul de la puntuació,... que també són molt interessants i per suposat
essencials per tenir un joc completament funcional.

El joc que implementarem en aquest projecte és elWord challenge. És un joc de pa-
raules l’objectiu del qual és que el jugador tracti de crear, en un temps limitat, el màxim
nombre de paraules vàlides possible (d’acord amb un diccionari) amb les lletres que ens
han donat. El conjunt de lletres inicial està col·locat en un faristol i pot haver lletres
repetides. Cada lletra del faristol només es pot emprar una vegada en cada paraula que
formem. En general, el faristol contéNlletres i la longitud de les paraules vàlides varia
entre 3 iN. Amb cada paraula formada s’atorguen punts i quant més llarga sigui la
paraula formada més punts s’obtenen.

El diccionari juga un paper primordial donat que és el que indica quines paraules
són vàlides i mitjançant aquest es determina quantes paraules es poden formar variant
la posició i el nombre de lletres que es prenen del faristol.

El projecte consistirà en implementar una sèrie de mòduls i classes amb les quals es
pugui resoldre eficientment el problema de trobar totes les paraules d’un diccionari que
es puguin formar prenent un cert nombre de lletres —com a mínim tres— i permutant-
les adequadament, d’entre les lletres d’un conjunt que se’ns dóna inicialment.

En una possible implementació del joc, el programa triaria secretament una paraula
de longitudNdel diccionari (per garantir que com a mínim es pot formar una paraula
amb totes les seves lletres!) i usaria el mòdul que implementareu per obtenir la llista de
totes les paraules que es poden formar amb les lletres de la paraula triada inicialment. A
continuació es mostraria al jugador lesNlletres de la paraula triada però desordenades
i, de manera més o menys gràfica, la informació relativa a quantes paraules hi ha en la
llista de cada longitud entre 3 iN. Llavors es posa en marxa el compte enrere: el jugador


ha de trobar tantes paraules com pugui en un temps limitat.

```
Òbviament, el resultat sempre dependrà del diccionari utilitzat.
```
```
Per acabar d’aclarir el joc us presentem dos exemples:
```
**Exemple 1** : Si en el faristol tenim les següents lletres:

### O C A O R R

i el diccionari contingués totes les paraules del castellà, podríem formar: 8 paraules de
tres lletres (ROA, OCA, ORA, ORO, ARO,... ), 13 paraules de quatre lletres (ROCA, CO-
RO, ORCA, ARCO, CARO,... ), 5 paraules de cinc lletres (CORRA, CORRO, CARRO,

... ) i 2 paraules amb les sis lletres (CORROA i ACORRO).

**Exemple 2** : Si el conjunt inicial de lletres en el faristol és:

### T S R A O C

i el diccionari contingués totes les paraules del castellà, el sistema ens permetrà obtenir
eficientment la següent llista de paraules (ordenades per longitud creixent, i a igual lon-
gitud, per ordre alfabètic creixent):
ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CA-
TO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO,
SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA,
CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSAS,
TOSCA, TROCA, CORTAS, COSTAR, COSTRA, TROCAS.


## 3 Disseny modular

```
Figura 1: Disseny modular del projecte.
```
En aquest projecte la vostra tasca serà la de dissenyar i implementar el mòdulword_toolkit,
les classesdiccionari,anagrames,iter_subset, i el mòdulobte_paraules.

S’han omès d’aquest diagrama (figura 1) la classeerrori el mòdulutilde la biblioteca
libesinper claredat, ja que moltes classes i mòduls del diagrama usen aquests mò-
duls. La classeerrorestà documentada en elManual de laboratori d’ESIN, i el mòdulutil
està documentat on-line en el fitxeresin/util. En algunes classes d’aquest projec-
te s’usa també la classestringiiostreamde la biblioteca estàndard de C++. Aquestes
relacions d’ús i les classes en qüestió tampoc es mostren a la figura.

També tindreu a la vostra disposició, més endavant, els jocs de proves públics i el
mòduldriver_joc_par. Aquest mòdul conté el programa principal i usa a totes les
classes que heu d’implementar, és a dir, permet invocar cada una de les operacions dels
diferents mòduls i classes.

Recordeu que no es pot utilitzar cap classe d’una biblioteca externa en les vostres
classes, exceptuant si en aquesta documentació s’indica el contrari.

En totes les classes s’han d’implementar els mètodes de construcció per còpia, as-
signació i destrucció davant la possibilitat que useu memòria dinàmica en la classe en


qüestió. Si no es fa ús de memòria dinàmica, la implementació d’aquests tres mètodes
és molt senzilla doncs n’hi haurà prou amb imitar el comportament del que serien els
corresponents mètodes d’ofici (el destructor no fa "res", i els altres fan còpies atribut per
atribut).

Així mateix us proporcionem tots els fitxers capçalera (.hpp) d’aquest disseny mo-
dular. No podeu crear els vostres propis fitxers capçalera ni modificar de cap manera els
que us donem. Tingueu present que heu de respectar escrupolosament l’especificació de
cada classe que apareix en el corresponent.hpp.

```
ATENCIÓ : És important que una cop hem implementat cadascuna de les classes,
les sotmeteu als vostres jocs de prova. A més, també és fonamental dissenyar
amb força detall la representació de cada classe i els seus algorismes sobre paper,
i prendre notes de tots els passos seguits abans de començar a codificar. Aquesta
informació serà vital de cara a la preparació de la documentació final.
```
En resum, en aquest projecte les tasques que heu de realitzar i l’ordre que heu de
seguir és el següent:

- Implementar el mòdulword_toolkit
- Implementar la classeiter_subset
- Implementar el mòdulobte_paraules
- Implementar la classediccionari
- Implementar la classeanagrames


## 4 El mòdulword_toolkit

```
Aquest mòdul ofereix funcions útils per les altres classes i mòduls.
```
```
Organització de la implementació:
```
```
La implementació d’aquest mòdul es trobarà en el fitxerword_toolkit.cpp.
```
Nota: En la implementació d’aquest mòdul es pot usar el mètode sort de la biblioteca
STL.

#ifndef _WORD_TOOLKIT_HPP
#define _WORD_TOOLKIT_HPP
#include <string>
#include <list>
#include <esin/error>

**using namespace** std;

**namespace** word_toolkit {

```
/* Pre : Cert
Post : R e t o r n a cert si i n o m é s si les l l e t r e s de l ’ s t r i n g s e s t a n
en o r d r e l e x i c o g r à f i c a s c e n d e n t. */
bool es_canonic( const string& s) throw ();
```
```
/* Pre : Cert
Post : R e t o r n a l ’ a n a g r a m a c a n ò n i c de l ’ s t r i n g s.
V e u r e la c l a s s e a n a g r a m e s per s a b e r la d e f i n i c i ó d ’ a n a g r a m a c a n ò n i c. */
string anagrama_canonic( const string& s) throw ();
```
/* Pre : L és una l l i s t a no b u i d a de p a r a u l e s f o r m a d e s e x c l u s i v a m e n t
amb l l e t r e s m a j ú s c u l e s de la ’ A ’ a la ’ Z ’ ( e x c l o s e s la ’ Ñ ’, ’ Ç ’,
m a j ú s c u l e s a c c e n t u a d e s ,... ).
Post : R e t o r n a el c a r à c t e r que no a p a r e i x a l ’ s t r i n g excl i és
el més f r e q ü e n t en la l l i s t a de p a r a u l e s L.
En cas d ’ empat , es r e t o r n a r i a el c a r à c t e r a l f a b è t i c a m e n t m e n o r.
Si l ’ s t r i n g excl i n c l o u t o t e s les l l e t r e s de la ’ A ’ a la ’ Z ’ es
r e t o r n a el c a r à c t e r ’\0 ’ , és a dir , el c a r à c t e r de codi A S C I I 0. */
**char** mes_frequent( **const** string& excl, **const** list<string>& L) **throw** ();
};
#endif


## 5 La classediccionari

Un objecte de la classe diccionari emmagatzema un conjunt de paraules (represen-
tades mitjançant strings) i ofereix operacions eficients per afegir noves paraules, deter-
minar si una paraula és present en el diccionari o no, per trobar totes les paraules que
compleixen un patró, etc.

```
Decisions sobre les dades:
```
Totes les paraules del diccionari estaran constituïdes exclusivament per lletres ma-
júscules^1 , de l’A a la Z. El nombre de paraules que emmagatzemarà un diccionari no
es coneix ni es pot fer cap estimació raonable sobre el seu valor. Pot haver diccionaris
petits, mitjans, grans i gegantins.

```
Comentaris i exemples sobre l’especificació:
```
L’especificació de les operacions constructores és senzilla i no semblen requerir més
explicacions. Malgrat això, és convenient fer alguns comentaris i donar exemples que
ajudin a aclarir l’especificació de les operacionsprefixisatisfan_patro.

prefix

Si la paraula donadapestà en el diccionari llavors l’operacióprefixens retorna
la paraula sencera. I a la inversa, siprefixno ens retorna la paraula donada, llavors
aquesta paraula no forma part del diccionari.

En canvi sipno és una paraula del diccionari ni tampoc ho és cap dels seus prefi-
xos, llavors l’operacióprefixretornarà l’string buit (que sempre és una paraula del
diccionari).

Suposem quep=PODARFOLGZ. Si el diccionari conté paraules vàlides en castellà
llavors l’operacióprefixretornaràPODAR, a menys que aquest verb no aparegués en
el diccionari, en aquest cas retornariaPODA. Si tampoc estigués aquesta última paraula
en el diccionari, el més probable és que es retornés l’string buit doncs, en principi, ni
POD, niPOniPsón paraules vàlides.

Ara bé, el diccionari pot contenir paraules qualsevols i el fet que aquestes parau-
les siguin o no vàlides en un cert idioma és completament irrellevant des del punt de
vista del disseny i implementació de la classediccionari. Si per qualsevol raó hagués-
sim afegit l’stringPODARFOen el nostrediccionari, llavorsprefix(“PODARFOLGZ”)
retornariaPODARFO. De manera anàloga si el diccionari contingués l’stringPOD(però

(^1) Sense incloure ni Ñ ni Ç ni vocals accentuades; en definitiva, només les lletres majúscules amb codis
ASCII entre 65 i 90.


no les paraulesPODAoPODARni cap string més llarg) llavorsprefix(“PODARFOLGZ”)
retornariaPOD.

satisfan_patro

L’operaciósatisfan_patrorep un patró a través d’un vector de strings i retorna
una llista ordenada amb les paraules del diccionari que satisfan aquest patró. En un
patró cada component és un string que indica quines lletres (de l’A a la Z) s’admeten en
la posició corresponent.

Per exemple, suposem que el patróqés ("ABC...Z","C","AEIOU","LRS"). Llavors
satisfan_patro(q)retornarà totes les paraules del diccionari de quatre lletres on la
primera lletra és una lletra qualsevol, la segona lletra és una C, la tercera és una vocal i
la quarta és L, R o S, p.e., entre altres, la paraulaECOS.

Per altra banda, amb el patró ("A...Z","A...Z","A...Z","A...Z","A...Z") re-
tornarà totes les paraules de longitud 5 i el patró ("A","S","O") retornarà una llista que
contindrà la paraulaASOsi aquesta paraula estigués present o una llista buida en cas
contrari. En general, l’operació retornarà una llista buida si en el diccionari no hi ha cap
paraula que satisfaci el patró donat.

```
Organització de la representació i implementació:
```
La representació d’aquesta classe es trobarà en el fitxerdiccionari.repi la im-
plementació en el fitxerdiccionari.cpp.

#ifndef _DICCIONARI_HPP
#define _DICCIONARI_HPP
#include <string>
#include <list>
#include <vector>
#include <esin/error>
#include <esin/util>

**using namespace** std;
**using** util::nat;

**class** diccionari {

**public** :
/* Pre : Cert
Post : C o n s t r u e i x un d i c c i o n a r i que c o n t é ú n i c a m e n t una p a r a u l a :
la p a r a u l a b u i d a. */
diccionari() **throw** (error);


```
/* Tres g r a n s. C o n s t r u c t o r per còpia , o p e r a d o r d ’ a s s i g n a c i ó i d e s t r u c t o r. */
diccionari( const diccionari& D) throw (error);
diccionari& operator =( const diccionari& D) throw (error);
~diccionari() throw ();
```
```
/* Pre : Cert
Post : A f e g e i x la p a r a u l a p al d i c c i o n a r i ; si la p a r a u l a p ja
f o r m a v a part del d i c c i o n a r i , l ’ o p e r a c i ó no té cap e f e c t e. */
void insereix( const string& p) throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a el p r e f i x més l l a r g de p que és una p a r a u l a que
p e r t a n y al d i c c i o n a r i , o dit d ’ una f o r m a més precisa , r e t o r n a la
p a r a u l a més l l a r g a del d i c c i o n a r i que és p r e f i x de p. */
string prefix( const string& p) const throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a la l l i s t a de p a r a u l e s del d i c c i o n a r i que s a t i s f a n
el p a t r ó e s p e c i f i c a t en el v e c t o r d ’ s t r i n g s q , en o r d r e
a l f a b è t i c a s c e n d e n t. */
void satisfan_patro( const vector<string>& q,
list<string>& L) const throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a una l l i s t a amb t o t e s les p a r a u l e s del d i c c i o n a r i
de l o n g i t u d m a j o r o i g u a l a k en o r d r e a l f a b è t i c a s c e n d e n t. */
void llista_paraules(nat k, list<string>& L) const throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a el n o m b r e de p a r a u l e s en el d i c c i o n a r i. */
nat num_pal() const throw ();
```
**private** :
#include "diccionari.rep"
};
#endif


## 6 La classe anagrames

Un objecte de la classeanagramesés un diccionari (per tant emmagatzema paraules
i té operacions eficients per afegir noves paraules, determinar si una paraula és present o
no, per trobar les paraules que compleixen un patró,... ), però a més a més permet que
sigui eficient trobar el subconjunt de totes les paraules que tenen un mateixanagrama
canònicdonat.

Donades dues paraulespiq d’un diccionari, es diu quepés un anagrama deq
(i viceversa) sipes pot obtenir permutant les lletres deq, p.e. ACCIONés un ana-
grama deCOCINA. Donada una paraula qualsevolp, anomenarem anagrama canònic
anagrama_canonic(p)a l’string que s’obté a l’ordenar les lletres depde menor a ma-
jor, p.e.,anagrama_canonic(COCINA)=ACCINO. És important observar que l’anagra-
ma canònic d’una paraulapno necessàriament és una paraula vàlida del diccionari —i
per tant, parlant amb propietat, no seria un anagrama.

Aquesta operació fonamental de la classeanagramesésmateix_anagrama_canonic(a),
que retorna totes les paraules que tenen com anagrama canònic a l’stringa. P.e. les pa-
raulesPERA,PAREiRAPEtenen com anagrama canònic l’stringAEPR. L’operació ha de
ser el més eficient possible; el seu cost ha de ser proporcional a la longitud de la llista de
paraules retornada com a resultat, més un cost addicionalO(logn)per trobar l’stringa.

```
Comentaris sobre la implementació:
```
Aprofitarem els mecanismes d’herència que proporciona el llenguatge C++i defini-
rem la classeanagramescom una herència pública de la la classediccionari; així dins de
la classeanagramesdisposarem de tots els mètodes de la la classediccionari. Redefini-
rem el mètodeinsereixper poder classificar la paraula segons el seuanagrama canònic
a més d’afegir-la al diccionari. I afegirem el mètodemateix_anagrama_canonicque
la classe basediccionarino tenia.

Es poden emprar les classesvector,listi els algorismes associats de la biblioteca
STL en la implementació d’aquesta classe (tant en la representació com en la imple-
mentació dels mètodes). Si s’utilitzen aquestes estructures també s’haurà de justificar el
perquè i calcular-ne l’eficiència en temps i espai que s’obtingui.

```
Organització de la representació i implementació:
```
La representació d’aquesta classe es trobarà en el fitxeranagrames.repi la imple-
mentació en el fitxeranagrames.cpp.

#ifndef _ANAGRAMES_HPP
#define _ANAGRAMES_HPP
#include <string>
#include <list>
#include <esin/error>
#include "diccionari.hpp"


**using namespace** std;

**class** anagrames : **public** diccionari {

**public** :
/* Pre : Cert
Post : C o n s t r u e i x un a n a g r a m a buit. */
anagrames() **throw** (error);

```
/* Tres g r a n s. C o n s t r u c t o r per còpia , o p e r a d o r d ’ a s s i g n a c i ó i d e s t r u c t o r. */
anagrames( const anagrames& A) throw (error);
anagrames& operator =( const anagrames& A) throw (error);
~anagrames() throw ();
```
```
/* Pre : Cert
Post : A f e g e i x la p a r a u l a p a l ’ a n a g r a m a ; si la p a r a u l a p ja
f o r m a v a part de l ’ anagrama , l ’ o p e r a c i ó no té cap e f e c t e. */
void insereix( const string& p) throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a la l l i s t a de p a r a u l e s p tals que a n a g r a m a _ c a n o n i c ( p )= a.
L l a n ç a un e r r o r si les l l e t r e s de a no e s t a n en o r d r e a s c e n d e n t. */
void mateix_anagrama_canonic( const string& a, list<string>& L) const throw (error);
```
```
/* G e s t i ó d ’ e r r o r s. */
static const int NoEsCanonic = 21;
```
**private** :
#include "anagrames.rep"
};
#endif


## 7 La classeiter_subset

Un objecte de la classeiter_subsetés un iterador sobre el conjunt dels subconjunts de
kelements presos de{ 1 ,... , n}. Un subconjunt es representarà mitjançant unvector<nat>.
Els subconjunts es recorren en ordre lexicogràfic ascendent. Per exemple

iter_subset C(4,2);
**while** (!C.end()) {
print(*C);
++C;
};

imprimeix tots els subconjunts de dos elements presos de{ 1 , 2 , 3 , 4 }; en concret s’impri-
meix{ 1 , 2 },{ 1 , 3 },{ 1 , 4 },{ 2 , 3 },{ 2 , 4 }y{ 3 , 4 }, per aquest ordre.

```
El cost de recórrer els
```
```

n
k
```
```

= k!(nn−!k)!subconjunts dekelements presos de{ 1 ,... , n}
```
ha de serΘ

```
n
k
```
```

.
```
```
Organització de la representació i implementació:
```
La representació d’aquesta classe es trobarà en el fitxeriter_subset.repi la seva
implementació en el fitxeriter_subset.cpp.

#ifndef _ITER_SUBSET_HPP
#define _ITER_SUBSET_HPP
#include <esin/error>
#include <esin/util>
#include <vector>

**using namespace** std;
**using** util::nat;

**typedef** vector<nat> subset;

**class** iter_subset {

**public** :
/* Pre : Cert
Post : C o n s t r u e i x un i t e r a d o r s o b r e els s u b c o n j u n t s de k e l e m e n t s
de {1 , ... , n }; si k > n no hi ha res a r e c ó r r e r. */
iter_subset(nat n, nat k) **throw** (error);

```
/* Tres g r a n s. C o n s t r u c t o r per còpia , o p e r a d o r d ’ a s s i g n a c i ó i d e s t r u c t o r. */
iter_subset( const iter_subset& its) throw (error);
iter_subset& operator =( const iter_subset& its) throw (error);
~iter_subset() throw ();
```

```
/* Pre : Cert
Post : R e t o r n a cert si l ’ i t e r a d o r ja ha v i s i t a t tots els s u b c o n j u n t s
de k e l e m e n t s p r e s o s d ’ e n t r e n ; o dit d ’ una a l t r a forma , r e t o r n a
cert quan l ’ i t e r a d o r a p u n t a a un s u b c o n j u n t s e n t i n e l l a f i c t i c i
que q u e d a a c o n t i n u a c i ó de l ’ ú l t i m s u b c o n j u n t v à l i d. */
bool end() const throw ();
```
```
/* O p e r a d o r de d e s r e f e r è n c i a.
Pre : Cert
Post : R e t o r n a el s u b c o n j u n t a p u n t a t per l ’ i t e r a d o r ;
l l a n ç a un e r r o r si l ’ i t e r a d o r a p u n t a al s e n t i n e l l a. */
subset operator *() const throw (error);
```
```
/* O p e r a d o r de p r e i n c r e m e n t.
Pre : Cert
Post : A v a n ç a l ’ i t e r a d o r al s e g ü e n t s u b c o n j u n t en la s e q ü è n c i a i el r e t o r n a ;
no es p r o d u e i x l ’ a v a n ç a m e n t si l ’ i t e r a d o r ja a p u n t a v a al s e n t i n e l l a. */
iter_subset& operator ++() throw ();
```
```
/* O p e r a d o r de p o s t i n c r e m e n t.
Pre : Cert
Post : A v a n ç a l ’ i t e r a d o r al s e g ü e n t s u b c o n j u n t en la s e q ü è n c i a i r e t o r n a el seu v a l o r
p r e v i ; no es p r o d u e i x l ’ a v a n ç a m e n t si l ’ i t e r a d o r ja a p u n t a v a al s e n t i n e l l a. */
iter_subset operator ++( int ) throw ();
```
```
/* O p e r a d o r s r e l a c i o n a l s. */
bool operator ==( const iter_subset& c) const throw ();
bool operator !=( const iter_subset& c) const throw ();
```
```
/* G e s t i ó d ’ e r r o r s. */
static const int IterSubsetIncorr = 31;
```
**private** :
#include "iter_subset.rep"
};
#endif


## 8 El mòdulobte_paraules

El mòdulobte_paraulesofereix dues operacions (amb el mateix nom); una d’elles
ens retorna totes les paraules que es poden formar usant un cert nombre de lletresk
preses d’un cert string; l’altra ens retorna totes les paraules que es poden formar usant
3 o més lletres preses d’un string donat.

```
Organització de la implementació:
```
```
La implementació d’aquest mòdul es trobarà en el fitxerobte_paraules.cpp.
```
#ifndef _OBTE_PARAULES_HPP
#define _OBTE_PARAULES_HPP
#include <list>
#include <string>
#include <esin/error>
#include <esin/util>
#include "anagrames.hpp"

**using namespace** std;
**using** util::nat;

**namespace** obte_paraules {

```
/* Pre : Cert
Post : R e t o r n a la l l i s t a de p a r a u l e s que es p o d e n f o r m a r u s a n t k l l e t r e s
de la p a r a u l a s. L l a n ç a e r r o r si k és m a j o r que la l o n g i t u d de
l ’ s t r i n g s o k < 3. */
void obte_paraules(nat k, const string& s, const anagrames& A,
list<string>& paraules) throw (error);
```
```
/* Pre : Cert
Post : R e t o r n a la l l i s t a de p a r a u l e s que es p o d e n f o r m a r u s a n t 3 o més l l e t r e s
de la p a r a u l a s. La l l i s t a e s t a r à o r d e n a d a de m e n y s a més l o n g i t u d ;
a i g u a l l o n g i t u d les p a r a u l e s e s t a n en o r d r e a l f a b è t i c c r e i x e n t.
L l a n ç a un e r r o r si l ’ s t r i n g s té m e n y s de tres l l e t r e s. */
void obte_paraules( const string& s, const anagrames& A,
list<string>& paraules) throw (error);
```
/* G e s t i ó d ’ e r r o r s. */
**static const int** LongitudInvalida = 41;
};
#endif


## 9 Errors

```
Aquest fitxer conté els missatges d’error usats en la gestió d’errors.
```
21 anagrames L’string no es un anagrama.
31 iter_subset Acces amb iterador de subconjunts invalid.
41 obte_paraules Longitud invalida.


## 10 Documentació

Els fitxers lliurats han d’estar degudament documentats. És molt important des-
criure amb detall i precisió la representació escollida en el fitxer.rep, justificant les
eleccions fetes, així com les operacions de cada classe. És especialment important ex-
plicar amb detall les representacions i els motius de la seva elecció enfront a possibles
alternatives, i els algorismes utilitzats.

El cost en temps i en espai és freqüentment el criteri determinant en l’elecció, per
la qual cosa s’hauran de detallar aquests costs en la justificació (sempre que això sigui
possible) per a cada alternativa considerada i per a l’opció finalment escollida. A més
caldrà detallar en el fitxer.cppel cost de cada mètode públic i privat.

```
En definitiva heu de:
```
- comentar adequadament el codi, evitant comentaris inútils i superflus
- indicar, en la mesura que sigui possible, el cost dels mètodes de les classes (tant
    públics com privats)
- descriure amb detall i precisió la representació escollida i justifiqueu l’elecció res-
    pecte d’altres.

Un cop enviats els fitxers per via electrònica, aquests seran impresos per a la seva
avaluació. No haureu d’imprimir-los vosaltres. No haureu de lliurar cap altra docu-
mentació. Per tal d’unificar l’aspecte visual del codi fem servir una eina deprettyprin-
tinganomenadaastyle. Podeu comprovar els resultats que produeix elprettyprinter
mitjançant la comanda

```
% astyle --style=kr -s2 < fitxer.cpp > fitxer.formatejat
```
```
i a continuació podeu convertir-lo en un PDF per visualitzar-lo o imprimir-lo
```
```
% a2ps fitxer.formatejat -o - | ps2pdf - fitxer.pdf
```