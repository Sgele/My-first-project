## Projekto dalys
* v0.1
1. Sukurta strukrūta "Studentas", joje bus įrašoma informacija apie kiekvieną studentą (pvz.: vardas, pavardė, galutinis balas).
2. Panaudotos dvi funkcijos: spausdinimo, pildymo
3. Sukurtas sąrašas "studentai"

* v0.1 su vidurkiu ir mediana
1. Viskas analogiška kaip ir "v0.1", tik pridėta medianos radimas programoje.
2. Papildomai struktūroje "Studentas" pridėtas dar vienas double tipo kintamasis "mediana", į kurį įrašysime gautą rezultatą apskaičiavus medianą.
3. Medianos skaičiavimas parašytas f-joje "void pild(studentas& kint)"

* v0.1 kai nezinom nd skaicius is anksto
1. Buvo sukurtas dar vienas ciklas, kuriame aprašyta sąlyga kaip programa turi elgtis, kai yra nežinomas nd skaičius iš anksto.

* v0.1 su atsitiktiniu skaiciu generavimu
1. Sukurta dar viena 'if' salyga, kurioje vartotojas irases '-2' gaus atsitiktinai sugeneruotus skaicius
2. Naudota vektoriai
3. Atsitiktinai sugeneruoti pazymiai isvedami i ekrana, kadangi kitaip ju nezinosime (praeitose versijose vartotojas pats jas irase, todel viska mateme)

* v0.2
1. Paliktas budas tik su vektoriumi.
2. Dabar vartotojas turi pasirinkima: ar failai bus ivedineti ranka ar skaitomi is failo
3. Yra tikrinimas ar failas nera tuscias
4. Skaiciu patikrinimas idetas

* v0.3
1. Funkcijos išskirtytos į header ir cpp failus.
2. Kur tikslinga, panaudota išimtys

* v0.4
1. Paliktas vartotojui pasirinkimas ar jis nori pats duomenis įvesti, ar kad būtų kiekvieną kartą sugeneruojamas .txt failas su pageidaujamu kiekiu įrašų.
2. Atlikta spartos analizė su sugeneruotais .txt failais (su 10000000 visos spartos analizės atlikti nepavyko).
![image]<img width="400" alt="Screenshot 2021-10-15 140954" src="https://user-images.githubusercontent.com/90323260/137480410-43b488e4-90e8-438f-a4cf-48d732f38380.png">
3. Pridėtas studentų rūšiavimas į dvi grupes: `Kietiakai` (studento vidurkis >= 5) ir `Nuskriaustukai` (studento vidurkis < 5). `Kietiakai` ir `Nuskriaustukai` išvedami į du atskirus failus: `Kietiakai.txt` ir `Nuskriaustukai.txt`

* v0.5
1. Sukurtas programos spartos lyginimas naudojant std::list ir std::vector 
<img width="300" alt="pavye=kes su 10000000  tik list-copy1" src="https://user-images.githubusercontent.com/90323260/141202079-5c263f6a-d6c2-4d1d-aeee-80268c94a308.png">
p.s. su vektoriumi ir 10000000 studentų duomenų failu nepavyko atlikti dalijimo į du sąrašus, laukiau 30min ir tada programą nutraukiau. (dešinėje pusėje matomas laikas)
<img width="876" alt="10000000 failo dalijimas, nepavykes copy" src="https://user-images.githubusercontent.com/90323260/141202801-dbb2c170-3dc4-4c6c-9c2c-2848354f95ed.png">


Kompiuterio su kuriuo daryti testai parametrai : Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz   2.70 GHz, 8,00 GB RAM, SSD 237 GB dydžio
