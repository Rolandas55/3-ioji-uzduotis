# 3-ioji-uzduotis

**1.**

reserve() - patikrinna ar pasirinktas dydis yra didesnis už esamą ir atlaisvina pasirinktą vietą.

clear() - atlaisvina reikšmių vietą.

at() - gražina objekto adresą ir patikrna ar jis yra Vector ribose.

rbegin() - parado Vector pradžią jei Vector būtų apsuktas iš kito galo.

back() - gražina paskutinę Vector reikšmė.

**2.**

Vector 10000 laikas: 0.003

std::vector 10000 laikas: 0.004

Vector 100000 laikas: 0.009

std::vector 100000 laikas: 0.015

Vector 1000000 laikas: 0.048

std::vector 1000000 laikas: 0.098

Vector 10000000 laikas: 0.461

std::vector 10000000 laikas: 0.784

Vector 100000000 laikas: 3.288

std::vector 100000000 laikas: 6.032

Vector užsipildo beveik dvigubai greičiau.



Kolkas daugiau nepadariau.
