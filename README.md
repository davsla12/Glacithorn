# Glacithorn
18 – Glacithorn – 
Popis: Ledový obr, který zpomaluje čas a pohyb.

Každý lichý tah sníží rychlost hráče: hráčova akce příští kolo má 25% šanci selhat.

Každé 3. kolo vytvoří ledový štít, který absorbuje veškeré poškození.

Pokud štít nebyl prolomen, Glacithorn přidá 5 HP sobě.

Každé 6. kolo provede „Ledovou ránu“, která hráče zmrazí (ztrácí příští tah).

Hláška při zmrazení: „Glacithorn udeřil přímo do srdce zimou věků!“

## Dependencies
pro kompilaci je potřeba knihovna ncurses

Ubuntu:
```Bash
sudo apt install libncurses-dev
```
MacOS(s Homebrew):
```Bash
brew install ncurses
```

Poté stačí dát
```Bash
mkdir build
cd build
cmake ..
make
```
## Dokumentace
funkce které jsme se neučili

Základní initializace ncurses
```C
initscr();
noecho();
curs_set();
keypad();
nodelay();
```
Získání velikosti terminálu
```C
getmaxyx();
```
Initializace pro podporu českých znaků
```C
setlocale();
```
Inicializace pro barvy
```C
start_color();
init_pair(1,COLOR_RED,COLOR_BLACK);
```
Ukončení
```C
endwin();
```
Vytvoření podokna v ncurses
```C
newwin();
```
Získání velikosti okna/podokna
```C
getmaxy()
getmaxx()
```
Získání zmáčknuté klávesy
```C
getch()
```
Smazání buffur okna v ncurses
```C
werase();
```
Zobrazí box okolo okna/podokna
```C
box();
```
Zapnutí/vypnutí atributu pro render v určitém okně
```C
wattron());
wattroff();
```
Výpis textu do určitého okna podle printf formátování
```C
mvwprintw();
```
Obnovení okna terminálu
```C
wnoutrefresh(p->window);
doupdate();
```
