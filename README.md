# Kolekcja Algorytmów w C++

Repozytorium zawiera zbiór algorytmów i implementacji różnych struktur danych w C++. Każdy plik źródłowy reprezentuje osobny program, który demonstruje wykorzystanie koncepcji programowania i algorytmiki. 

## Lista Programów

### 1. `Robot.cpp`
- **Opis**: Symulacja przemieszczania robota w przestrzeni 2D.
- **Funkcje**: Przemieszczanie na podstawie kierunku i odległości.

### 2. `Analiza leksykalna.cpp`
- **Opis**: Program do analizy leksykalnej i obliczania wyrażeń matematycznych.
- **Funkcje**: Obsługa podstawowych działań arytmetycznych.

### 3. `Bankomat zachłanny.cpp`
- **Opis**: Algorytm zachłanny dla problemu wydawania reszty przez bankomat.
- **Funkcje**: Wybór minimalnej liczby banknotów do wydania określonej kwoty.

### 4. `Drzewo poszukiwan binarnych (BFS).cpp`
- **Opis**: Implementacja drzewa poszukiwań binarnych (BFS - Breadth-First Search).
- **Funkcje**: Wstawianie, przechodzenie inorder, preorder, postorder.

### 5. `Ile składowych spójności.cpp`
- **Opis**: Algorytm znajdujący ilość składowych spójności w grafie.
- **Funkcje**: DFS (Depth-First Search) do analizy spójności.

### 6. `Ilosc nieszachujacych sie hetmanow (1).cpp` oraz `Ilosc nieszachujacych sie hetmanow (2).cpp`
- **Opis**: Programy do obliczania liczby ustawień hetmanów na szachownicy, gdzie nie atakują się wzajemnie.
- **Funkcje**: Sprawdzanie poprawności położenia hetmanów.

### 7. `Labirynt.cpp`
- **Opis**: Algorytm znajdowania drogi w labiryncie.
- **Funkcje**: DFS do szukania najkrótszej ścieżki.

### 8. `Najkrotsza droga w grafie niezorientowanym.cpp`
- **Opis**: Algorytm wyszukiwania najkrótszej drogi w grafie niezorientowanym.
- **Funkcje**: BFS (Breadth-First Search) do znajdowania ścieżki.

### 9. `Proste zadanie na implementacje klas.cpp`
- **Opis**: Implementacja klas w C++, demonstrująca operacje na wektorach.
- **Funkcje**: Obliczanie długości wektora, mnożenie wektorów.

## Wymagania

- Kompilator C++ obsługujący standard C++11 lub nowszy.
- Podstawowa znajomość struktur danych i algorytmów.

## Kompilacja i Uruchomienie

Aby skompilować każdy program, użyj poniższej komendy (zastępując `nazwa_pliku.cpp` odpowiednią nazwą pliku):
```bash
g++ nazwa_pliku.cpp -o nazwa_pliku
```

Następnie możesz uruchomić program za pomocą:
```bash
./nazwa_pliku
```
