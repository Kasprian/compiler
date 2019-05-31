# Kompilator

*Autor: Piotr Kasprowicz*

## Pliki
- parser.y - plik Bizona
- lexer.l - plik Flexa
- functions.cpp - dodatkowe funkcje użyte w parserze
- functions.h - plik nagłówkowy functions.cpp
- Makefile - służy do skompilownaia programu

## Użyte narzędzia
- `gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0`
- `g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0`
- `flex 2.6.4`
- `bison (GNU Bison) 3.0.4`

## Sposób uruchomienia
W celu skompilowania projektu należy wykonać polecenie make.
Kompilator uruchamia się komendą `./kompilator. Jako pierwszy argument program przyjmuje nazwę programu. Drugi argument 

Przykładowy sposób wywołania dla pliku wejśiowego `program0.imp` i pliku wynikowego `wynik` :

```./kompilator program0.imp wynik```

Następnie należy przy pomocy maszyny rejestrowej skompilować kodu pośredni z pliku 'wynik'.
