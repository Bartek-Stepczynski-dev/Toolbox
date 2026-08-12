const int RememberedSize = 5; // definiuje ile odczytów chce żeby zapamiętał.
float readings[RememberedSize]; // tablica z pomiarami zarezerowowanymi na pięć miejsc (0-4).
int currentIndex = 0; // obecny indeks w tablicy, do którego wejdzie nowsza wartość.
float total = 0; // suma wartosci.

void setup() {

Serial.begin(9600);

for (int i = 0; i < RememberedSize; i++){ //  jednorazowa pętla czyszcząca przed startem.
  readings[i] = 0.0; // zeruje wszystkie 5 miejsc w tablicy(od 0 do 4 jest 5 miejsc).
  }
}

void loop() {
/* Generowanie losowych odczytów, zastępujących realne fizyczne odczyty czujnika.Symulacja działania
prawdziwego czujnika z wartosciami wyników podlegającymi szumowi*/
float rawSensorValue = 10.0 + (random(-50,50) / 10.0); /*baza = 10 + losowa liczba 
od -50 do 50 podzielona przez 10, aby była mniejsze wahania i liczby, bardziej naturalne*/ 
if (random(0,10) > 7){
  rawSensorValue = 25.0; /* Symulacja błędu/skoku odczytu, anomali na czujniku  z szansą  20%
co spowoduje wrzuceniu do tablicy liczby 25, ktora podniesie srednia.*/
}
total = total - readings[currentIndex];// odejmujem najstarsza wartość.
readings[currentIndex] = rawSensorValue;// nadpisuje stare miejsce nowym odczytem.
total = total + readings[currentIndex];// dodajemy nowa wartosc do  sumy

currentIndex = (currentIndex + 1) % RememberedSize; /* przesuwa pozycje dalej i pilnuje, żeby nie
wyszło poza tablicę dzieki modulo( dzieleniu z resztą), bo dla 0-4 bedzie normalna reszta, a dla 5: 0
lub dla liczb wiekszych jest pewnosc ze bedziemy w przedzile 0-4*/


float smoothedValue = total / RememberedSize ; 

Serial.print("Surowy_odczyt:");
Serial.print(rawSensorValue);
Serial.print("\t");
Serial.print("Wygladzony_odczyt:");
Serial.println(smoothedValue);


delay(500); //pół sekundy przed kolejnym pomiarem
}
