// quick vfd tube driver test - version 4b - 12.08.2016
// weather station & clock with calendar (english indications)
// MAX6921 -> datasheet: http://datasheets.maximintegrated.com/en/ds/MAX6921-MAX6931.pdf
// original sketch from https://github.com/echox/arduino-test/blob/master/max6921.ino
// current sketch by Nicu FLORICA (aka niq_ro): http://www.tehnic.go.ro
// & http://www.arduinotehniq.com/


#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

#include <DHT.h>
#define DHTPIN 8     // what pin we're connected DHT11 or DHT22
#define DHTTYPE DHT22   // or DHT 11 
DHT dht(DHTPIN, DHTTYPE);


int clk = 3;
int load = 5;
int din = 4;
int led = 13;
int blank = 7;

int pauza = 0;


byte zero[20]=
{1,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
1,
1,
1};



byte unu[20] = {1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
1,
0};

byte doi[20] =
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
1,
1,
0,
1,
1};

byte trei[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
0,
0,
1,
1};

byte patru[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
1,
1,
1,
0};

byte cinci[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
0,
1};

byte cincim[20]=
{0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
1,
1,
0,
1};

byte sase[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
0,
1};

byte sapte[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
1,
1};

byte opt[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1};

byte noua[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
1,
1};

byte literaA[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1};

byte literaB[20]=
{0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
0,
0,
1,
1};

byte literaC[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
0,
0,
1,
0,
1};

byte literaD[20]=
{0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
0,
0,
1,
1};

byte literaE[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
0,
1,
1,
0,
1};

byte literaF[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
1,
0,
1};

byte literaG[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
0,
1,
0,
1};

byte literaH[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
0};

byte literaI[20]=
{0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
1};

byte literaJ[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
0,
1,
0};

byte literaK[20]=
{1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
1,
0,
0};

byte literaL[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
0,
0,
1,
0,
0};

byte literaM[20]=
{1,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
1,
1,
0};

byte literaN[20]=
{0,
0,
1,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
1,
1,
0};

byte literaO[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
1,
1,
1};

byte literaP[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1};

byte literaQ[20]=
{0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
1,
1,
1};

byte literaR[20]=
{0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1};

byte literaS[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
0,
1};

byte literaT[20]=
{0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1};

byte literaU[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
1,
1,
0};

byte literaV[20]=
{1,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
1,
0,
0};

byte literaW[20]=
{0,
0,
0,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
1,
1,
0};

byte literaX[20]=
{1,
0,
1,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

byte literaY[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
1,
0};


byte litezaZ[20]=
{1,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
1};


byte gol[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

byte minus[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
0};

byte plus[20]=
{0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
0,
0};

byte grad[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1};

byte arond[20]=
{0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
1,
1,
0,
1,
1,
1};

byte egal[20]=
{0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
1,
1,
0,
0,
0};

byte per[20]=
{1,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

int timpceas = 50;
byte repet1 = 20;
int timpzi = 300;
int k;

byte ora, oraz, orau;
byte minut, minutz, minutu;
byte secunda, secundaz, secundau;
float temperatura, temperatura1;
int temperaturaz, temperaturau, temperaturas;
byte umiditate, umiditatez, umiditateu;
byte zil, zilz, zilu, zis, luna,lunaz, lunau;
byte an, anz, anu;


byte limba = 0;

void setup() {                
  pinMode(din, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(clk, OUTPUT);  
  pinMode(led, OUTPUT);
  
  pinMode(blank, OUTPUT);
  digitalWrite(blank, HIGH);
  delay(500); 
  digitalWrite(blank, LOW);
  
  digitalWrite(clk, LOW);
  digitalWrite(load, LOW);
  digitalWrite(din, LOW);
  
   // Serial.begin(9600);
    Wire.begin();

/*  
// part code from http://tronixstuff.wordpress.com/
Wire.beginTransmission(0x68);
Wire.write(0x07); // move pointer to SQW address
Wire.write(0x10); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave
Wire.endTransmission();
// end part code from http://tronixstuff.wordpress.com/
*/

    RTC.begin();
  if (! RTC.isrunning()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

}

// the loop routine runs over and over again forever:
void loop() {

digitalWrite(blank, HIGH);
umiditate = dht.readHumidity();
temperatura = 10*dht.readTemperature();
delay(500);  
digitalWrite(blank, LOW);   
  
//ora = random(24);
//minut = random(60);
//secunda = random(60);

//temperatura = random(400);
//umiditate = random(80);

//zis = random(7) + 1;

//luna = random(12) + 1;
//zil = random(30) + 1;
//an = random(16,40);


for(byte k1=0; k1 < repet1; k1++) {
digitalWrite(blank, HIGH);
DateTime now = RTC.now();
ora = now.hour();
minut = now.minute();
secunda = now.second();
digitalWrite(blank, LOW);  
  // compute each digit value
// hour
oraz = ora/10;
orau = ora - 10*oraz;
// minute
minutz = minut/10;
minutu = minut - 10*minutz;
// seconds
secundaz = secunda/10;
secundau = secunda - 10*secundaz;
// temperature
temperaturaz = temperatura/100;
temperatura1 = temperatura - 100*temperaturaz;
temperaturau = temperatura1/10;
temperaturas = temperatura1 - 10*temperaturau;
// humidity
umiditatez = umiditate/10;
umiditateu = umiditate - 10*umiditatez;

  
for(k=0; k < timpceas; k++) {
// clock -> 13-48-56

// put hour
// tens figure
//if (oraz == 0) afisare0(19, zero);
if (oraz == 0) afisare0(19, gol);
if (oraz == 1) afisare0(19, unu);
if (oraz == 2) afisare0(19, doi);
// put character of units
if (orau == 0) afisare0(18, zero);
if (orau == 1) afisare0(18, unu);
if (orau == 2) afisare0(18, doi);
if (orau == 3) afisare0(18, trei);
if (orau == 4) afisare0(18, patru);
//if (orau == 5) afisare0(18, cinci);
if (orau == 5) afisare0(18, cincim);
if (orau == 6) afisare0(18, sase);
if (orau == 7) afisare0(18, sapte);
if (orau == 8) afisare0(18, opt);
if (orau == 9) afisare0(18, noua);

// put separator
afisare0(17, minus);

// minutes 
// tens figure
if (minutz == 0) afisare0(16, zero);
if (minutz == 1) afisare0(16, unu);
if (minutz == 2) afisare0(16, doi);
if (minutz == 3) afisare0(16, trei);
if (minutz == 4) afisare0(16, patru);
//if (minutz == 5) afisare0(16, cinci);
if (minutz == 5) afisare0(16, cincim);
// put character of units
if (minutu == 0) afisare0(15, zero);
if (minutu == 1) afisare0(15, unu);
if (minutu == 2) afisare0(15, doi);
if (minutu == 3) afisare0(15, trei);
if (minutu == 4) afisare0(15, patru);
//if (minutu == 5) afisare0(15, cinci);
if (minutu == 5) afisare0(15, cincim);
if (minutu == 6) afisare0(15, sase);
if (minutu == 7) afisare0(15, sapte);
if (minutu == 8) afisare0(15, opt);
if (minutu == 9) afisare0(15, noua);

// put separator
afisare0(14, minus);

// seconds 
// tens figure
if (secundaz == 0) afisare0(13, zero);
if (secundaz == 1) afisare0(13, unu);
if (secundaz == 2) afisare0(13, doi);
if (secundaz == 3) afisare0(13, trei);
if (secundaz == 4) afisare0(13, patru);
//if (secundaz == 5) afisare0(13, cinci);
if (secundaz == 5) afisare0(13, cincim);
// put character of units
if (secundau == 0) afisare0(12, zero);
if (secundau == 1) afisare0(12, unu);
if (secundau == 2) afisare0(12, doi);
if (secundau == 3) afisare0(12, trei);
if (secundau == 4) afisare0(12, patru);
//if (secundau == 5) afisare0(12, cinci);
if (secundau == 5) afisare0(12, cincim);
if (secundau == 6) afisare0(12, sase);
if (secundau == 7) afisare0(12, sapte);
if (secundau == 8) afisare0(12, opt);
if (secundau == 9) afisare0(12, noua);

// free space
afisare0(11, gol);
afisare0(10, gol);

// temperature 20,5 gr.C
// tens figure
//if (temperaturaz == 0) afisare0(9, zero);
if (temperaturaz == 0) afisare0(9, gol);
if (temperaturaz == 1) afisare0(9, unu);
if (temperaturaz == 2) afisare0(9, doi);
if (temperaturaz == 3) afisare0(9, trei);
if (temperaturaz == 4) afisare0(9, patru);
//if (temperaturaz == 5) afisare0(9, cinci);
if (temperaturaz == 5) afisare0(9, cincim);
if (temperaturaz == 6) afisare0(9, sase);
if (temperaturaz == 7) afisare0(9, sapte);
if (temperaturaz == 8) afisare0(9, opt);
if (temperaturaz == 9) afisare0(9, noua);
// put character of units
if (temperaturau == 0) afisare1(8, zero);
if (temperaturau == 1) afisare1(8, unu);
if (temperaturau == 2) afisare1(8, doi);
if (temperaturau == 3) afisare1(8, trei);
if (temperaturau == 4) afisare1(8, patru);
//if (temperaturau == 5) afisare1(8, cinci);
if (temperaturau == 5) afisare1(8, cincim);
if (temperaturau == 6) afisare1(8, sase);
if (temperaturau == 7) afisare1(8, sapte);
if (temperaturau == 8) afisare1(8, opt);
if (temperaturau == 9) afisare1(8, noua);
// number after point (comma)
if (temperaturas == 0) afisare0(7, zero);
if (temperaturas == 1) afisare0(7, unu);
if (temperaturas == 2) afisare0(7, doi);
if (temperaturas == 3) afisare0(7, trei);
if (temperaturas == 4) afisare0(7, patru);
//if (temperaturas == 5) afisare0(7, cinci);
if (temperaturas == 5) afisare0(7, cincim);
if (temperaturas == 6) afisare0(7, sase);
if (temperaturas == 7) afisare0(7, sapte);
if (temperaturas == 8) afisare0(7, opt);
if (temperaturas == 9) afisare0(7, noua);

// putdegree symbol
afisare0(6, grad);
// put C letter (for Celsius)
afisare0(5, literaC);

// free space
afisare0(4, gol);

// relative humidity
// tens figure
//if (temperaturaz == 0) afisare0(3, zero);
if (umiditatez == 0) afisare0(3, gol);
if (umiditatez == 1) afisare0(3, unu);
if (umiditatez == 2) afisare0(3, doi);
if (umiditatez == 3) afisare0(3, trei);
if (umiditatez == 4) afisare0(3, patru);
//if (umiditatez == 5) afisare0(3, cinci);
if (umiditatez == 5) afisare0(3, cincim);
if (umiditatez == 6) afisare0(3, sase);
if (umiditatez == 7) afisare0(3, sapte);
if (umiditatez == 8) afisare0(3, opt);
if (umiditatez == 9) afisare0(3, noua);
// put character of units
if (umiditateu == 0) afisare0(2, zero);
if (umiditateu == 1) afisare0(2, unu);
if (umiditateu == 2) afisare0(2, doi);
if (umiditateu == 3) afisare0(2, trei);
if (umiditateu == 4) afisare0(2, patru);
//if (umiditateu == 5) afisare0(2, cinci);
if (umiditateu == 5) afisare0(2, cincim);
if (umiditateu == 6) afisare0(2, sase);
if (umiditateu == 7) afisare0(2, sapte);
if (umiditateu == 8) afisare0(2, opt);
if (umiditateu == 9) afisare0(2, noua);

// put letters R, H
afisare0(1, literaR);
afisare0(0, literaH);
}
}

digitalWrite(blank, HIGH);
DateTime now = RTC.now();
zil = now.day();
luna = now.month();
an = now.year()-2000;
zis = now.dayOfWeek();
digitalWrite(blank, LOW);
// day in mounth
zilz = zil/10;
zilu = zil - 10*zilz;
// month
lunaz = luna/10;
lunau = luna - 10*lunaz;
// year
anz = an/10;
anu = an - 10*anz;


for(k=0; k < timpzi; k++) {

for(k=0; k < timpzi; k++) {
// monday
if (zis == 1) {
afisare0(19, literaM);
afisare0(18, literaO);
afisare0(17, literaN);
afisare0(16, literaD);
afisare0(15, literaA);
afisare0(14, literaY);
afisare0(13, gol);
afisare0(12, gol);
afisare0(11, gol);
}

// tuestaday
if (zis == 2) {
afisare0(19, literaT);
afisare0(18, literaH);
afisare0(17, literaU);
afisare0(16, literaE);
afisare0(15, literaS);
afisare0(14, literaD);
afisare0(13, literaA);
afisare0(12, literaY);
afisare0(11, gol);
}

// wednestay
if (zis == 3) {
afisare0(19, literaW);
afisare0(18, literaE);
afisare0(17, literaD);
afisare0(16, literaN);
afisare0(15, literaE);
afisare0(14, literaS);
afisare0(13, literaD);
afisare0(12, literaA);
afisare0(11, literaY);
}

// thursday
if (zis == 4) {
afisare0(19, literaT);
afisare0(18, literaH);
afisare0(17, literaU);
afisare0(16, literaR);
afisare0(15, literaS);
afisare0(14, literaD);
afisare0(13, literaA);
afisare0(12, literaY);
afisare0(11, gol);
}

// friday
if (zis == 5) {
afisare0(19, literaF);
afisare0(18, literaR);
afisare0(17, literaI);
afisare0(16, literaD);
afisare0(15, literaA);
afisare0(14, literaY);
afisare0(13, gol);
afisare0(12, gol);
afisare0(11, gol);
}

// saturday
if (zis == 6) {
afisare0(19, literaS);
afisare0(18, literaA);
afisare0(17, literaT);
afisare0(16, literaU);
afisare0(15, literaR);
afisare0(14, literaD);
afisare1(13, literaA);
afisare0(12, literaY);
afisare0(11, gol);
}

// sunday
if (zis == 7) {
afisare0(19, literaS);
afisare0(18, literaU);
afisare0(17, literaN);
afisare0(16, literaD);
afisare0(15, literaA);
afisare0(14, literaY);
afisare0(13, gol);
afisare1(12, gol);
afisare0(11, gol);
}

// one space
afisare0(10, gol);

// data (mounth)
// tens figure
if (lunaz == 0) afisare0(9, zero);
//if (lunaz == 0) afisare0(9, gol);
if (lunaz == 1) afisare0(9, unu);
// put character of units
if (lunau == 0) afisare0(8, zero);
if (lunau == 1) afisare0(8, unu);
if (lunau == 2) afisare0(8, doi);
if (lunau == 3) afisare0(8, trei);
if (lunau == 4) afisare0(8, patru);
//if (lunau == 5) afisare0(8, cinci);
if (lunau == 5) afisare0(8, cincim);
if (lunau == 6) afisare0(8, sase);
if (lunau == 7) afisare0(8, sapte);
if (lunau == 8) afisare0(8, opt);
if (lunau == 9) afisare0(8, noua);

// one "-"
afisare0(7, per);

// data (days in mounth)
// tens figure
if (zilz == 0) afisare0(6, zero);
//if (zilz == 0) afisare0(6, gol);
if (zilz == 1) afisare0(6, unu);
if (zilz == 2) afisare0(6, doi);
if (zilz == 3) afisare0(6, trei);
// put character of units
if (zilu == 0) afisare0(5, zero);
if (zilu == 1) afisare0(5, unu);
if (zilu == 2) afisare0(5, doi);
if (zilu == 3) afisare0(5, trei);
if (zilu == 4) afisare0(5, patru);
//if (zilu == 5) afisare0(5, cinci);
if (zilu == 5) afisare0(5, cincim);
if (zilu == 6) afisare0(5, sase);
if (zilu == 7) afisare0(5, sapte);
if (zilu == 8) afisare0(5, opt);
if (zilu == 9) afisare0(5, noua);

// one "-"
afisare0(4, per);

// put year
afisare0(3, doi);
afisare0(2, zero);

// tens figure
if (anz == 0) afisare0(1, zero);
if (anz == 1) afisare0(1, unu);
if (anz == 2) afisare0(1, doi);
if (anz == 3) afisare0(1, trei);
// put character of units
if (anu == 0) afisare0(0, zero);
if (anu == 1) afisare0(0, unu);
if (anu == 2) afisare0(0, doi);
if (anu == 3) afisare0(0, trei);
if (anu == 4) afisare0(0, patru);
//if (anu == 5) afisare0(0, cinci);
if (anu == 5) afisare0(0, cincim);
if (anu == 6) afisare0(0, sase);
if (anu == 7) afisare0(0, sapte);
if (anu == 8) afisare0(0, opt);
if (anu == 9) afisare0(0, noua);
}
}

} // end main loop

void afisare0 (byte pozitie, byte caracter[20]) {
   // first put position of character
    for(int i=0;i<20;i++) {
    if (i == pozitie) digitalWrite(din, 1);
    else  digitalWrite(din, 0);
     digitalWrite(clk, HIGH);
     digitalWrite(clk, LOW);
    }
 //   digitalWrite(clk, LOW);

// second put letter/character
  for(int i=19;i>=0;i--) {
     digitalWrite(din, caracter[i]); 
     digitalWrite(clk, HIGH);
     digitalWrite(clk, LOW);
    }
 //   digitalWrite(clk, LOW);

  // load the changes
    digitalWrite(load, HIGH);
    digitalWrite(load, LOW);
}

void afisare1 (byte pozitie, byte caracter[20]) {
   // first put position of character
    for(int i=0;i<20;i++) {
    if (i == pozitie) digitalWrite(din, 1);
    else  digitalWrite(din, 0);
     digitalWrite(clk, HIGH);
     digitalWrite(clk, LOW);
    }
//    digitalWrite(clk, LOW);

// second put letter/character
  for(int i=19;i>=0;i--) {
     if (i == 7) digitalWrite(din, 1);    
     else 
     digitalWrite(din, caracter[i]); 
     digitalWrite(clk, HIGH);
     digitalWrite(clk, LOW);
    }
 //   digitalWrite(clk, LOW);

  // load the changes
    digitalWrite(load, HIGH);
    digitalWrite(load, LOW);
}
