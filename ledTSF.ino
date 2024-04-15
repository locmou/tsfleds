#include <Arduino.h>
#include <RGB_LED.h>

RGB_LED LED1(9,10,11);
RGB_LED LED2(5,3,6);
const int sensorsound = A3;    // select the input pin for the potentiometer
const int sensorp1= A2;    // select the input pin for the potentiometer
const int sensorp2 = A1;    // select the input pin for the potentiometer
const int allb=2;
const int turnb=4;
const int soundfb=7;
const int cols=8;
const int colsnet=12;
// int sensorsoundValue = 0;  // variable to store the value coming from the sensor
int r1=0,g1=0,b1=0,r2=0,g2=0,b2=0,x,t=1,t2,p1,p2,e[25];
float s;

void setup() {
// Serial.begin(9600); // pour étudier les sorties
pinMode(allb, INPUT);
pinMode(turnb, INPUT);
pinMode(soundfb, INPUT);
pinMode(cols, INPUT);
pinMode(colsnet, INPUT);
}

void loop() {
   // read the value from the sensor: 
  p1 = 1024-analogRead(sensorp1);
  p2 = analogRead(sensorp2);
//controle()  ;
  if (digitalRead(allb)==HIGH) allcolours();
  if (digitalRead(turnb)==HIGH) turncolour();
  if (digitalRead(soundfb)==HIGH) soundflash();
  if (digitalRead(cols)==HIGH) coloursound();
  if (digitalRead(colsnet)==HIGH) coloursoundnet();
  
  LED1.set(r1,g1,b1);
  LED2.set(r2,g2,b2);
}


/*
void controle() {
//pour étudier les sorties
  Serial.print("r1 : ");Serial.print(r1);
  Serial.print("   g1 : ");Serial.print(g1);
  Serial.print("   b1 : ");Serial.print(b1);
  Serial.print("   p1 : ");Serial.print(p1);
  Serial.print("   r2 : ");Serial.print(r2);
  Serial.print("   g2 : ");Serial.print(g2);
  Serial.print("   b2 : ");Serial.print(b2);
  Serial.print("   p2 : ");Serial.print(p2);
  Serial.print("   s : ");Serial.print(s);
  Serial.print("   t : ");Serial.print(t);
  Serial.print("   microo : ");Serial.println(analogRead(sensorsound));
}
*/

void ecarttype(){
  t=10;t2=0;
  for (int x=1; x<=t; x++) { e[x]=analogRead(sensorsound);}
  for (int x=1; x<=t; x++) { t2=t2+e[x];}
  t2=t2/t;
  for (int x=1; x<=t; x++) { e[x]=e[x]-t2;}
  for (int x=1; x<=t; x++) { e[x]=e[x]*e[x];}
  t2=0;
  for (int x=1;x<=t;x++) { t2=t2+e[x];}
  t2=t2/(t-1);
  t2=sqrt(t2); 
}

void allcolours(){
  // LED1
if (p1<46)  {  r1=255;  g1=0;  b1=255-(p1*5.54);}
if (p1>=46 and p1<92) {  r1=255;  g1=(p1-46)*5.54;  b1=0;}
if (p1>=92 and p1<138) {  r1=255-(p1-92)*5.54;  g1=255;  b1=0;}
if (p1>=138 and p1<184) {  r1=(p1-138)*5.54;  g1=255;  b1=(p1-138)*5.54;}
if (p1>=184 and p1<230) {  r1=255-(p1-184)*5.54;  g1=255;  b1=255;}
if (p1>=230 and p1<276) {  r1=0;  g1=255-(p1-230)*5.54;  b1=255;}
if (p1>=276 and p1<322) {  r1=(p1-276)*5.54;  g1=0;  b1=255;}
if (p1>=322 and p1<368) {  r1=255;  g1=(p1-322)*5.54;  b1=255-(p1-322)*5.54;}
if (p1>=368 and p1<414) {  r1=255;  g1=255;  b1=(p1-368)*5.54;}
if (p1>=414 and p1<460) {  r1=255-(p1-414)*5.54;  g1=255-(p1-414)*5.54;  b1=255;}
if (p1>=460 and p1<506) {  r1=(p1-460)*5.54;  g1=0;  b1=255-(p1-460)*5.54;}
if (p1>=506 and p1<552) {  r1=255-(p1-506)*5.54;  g1=(p1-506)*5.54;  b1=0;}
if (p1>=552 and p1<598) {  r1=0;  g1=255;  b1=(p1-552)*5.54;}
if (p1>=598 and p1<644) {  r1=(p1-598)*5.54;  g1=255-(p1-598)*5.54;  b1=255;}
if (p1>=644 and p1<690) {  r1=255-(p1-644)*5.54;  g1=(p1-644)*5.54;  b1=255-(p1-644)*5.54;}
if (p1>=690 and p1<736) {  r1=0;  g1=255-(p1-690)*5.54;  b1=(p1-690)*5.54;}
if (p1>=736 and p1<782) {  r1=(p1-736)*5.54;  g1=(p1-736)*5.54;  b1=255-(p1-736)*5.54;}
if (p1>=782 and p1<828) {  r1=255-(p1-782)*5.54;  g1=255;  b1=(p1-782)*5.54;}
if (p1>=828 and p1<874) {  r1=(p1-828)*5.54;  g1=255-(p1-828)*5.54;  b1=255-(p1-828)*5.54;}
if (p1>=874 and p1<920) {  r1=255;  g1=0;  b1=(p1-874)*5.54;}
if (p1>=920 and p1<966) {  r1=255;  g1=(p1-920)*5.54;  b1=255;}
if (p1>=966) {  r1=255;  g1=255-(p1-966)*5.54;  b1=255-(p1-966)*5.54;}
// LED2
if (p2<46)  {  r2=255;  g2=0;  b2=255-(p2*5.54);}
if (p2>=46 and p2<92) {  r2=255;  g2=(p2-46)*5.54;  b2=0;}
if (p2>=92 and p2<138) {  r2=255-(p2-92)*5.54;  g2=255;  b2=0;}
if (p2>=138 and p2<184) {  r2=(p2-138)*5.54;  g2=255;  b2=(p2-138)*5.54;}
if (p2>=184 and p2<230) {  r2=255-(p2-184)*5.54;  g2=255;  b2=255;}
if (p2>=230 and p2<276) {  r2=0;  g2=255-(p2-230)*5.54;  b2=255;}
if (p2>=276 and p2<322) {  r2=(p2-276)*5.54;  g2=0;  b2=255;}
if (p2>=322 and p2<368) {  r2=255;  g2=(p2-322)*5.54;  b2=255-(p2-322)*5.54;}
if (p2>=368 and p2<414) {  r2=255;  g2=255;  b2=(p2-368)*5.54;}
if (p2>=414 and p2<460) {  r2=255-(p2-414)*5.54;  g2=255-(p2-414)*5.54;  b2=255;}
if (p2>=460 and p2<506) {  r2=(p2-460)*5.54;  g2=0;  b2=255-(p2-460)*5.54;}
if (p2>=506 and p2<552) {  r2=255-(p2-506)*5.54;  g2=(p2-506)*5.54;  b2=0;}
if (p2>=552 and p2<598) {  r2=0;  g2=255;  b2=(p2-552)*5.54;}
if (p2>=598 and p2<644) {  r2=(p2-598)*5.54;  g2=255-(p2-598)*5.54;  b2=255;}
if (p2>=644 and p2<690) {  r2=255-(p2-644)*5.54;  g2=(p2-644)*5.54;  b2=255-(p2-644)*5.54;}
if (p2>=690 and p2<736) {  r2=0;  g2=255-(p2-690)*5.54;  b2=(p2-690)*5.54;}
if (p2>=736 and p2<782) {  r2=(p2-736)*5.54;  g2=(p2-736)*5.54;  b2=255-(p2-736)*5.54;}
if (p2>=782 and p2<828) {  r2=255-(p2-782)*5.54;  g2=255;  b2=(p2-782)*5.54;}
if (p2>=828 and p2<874) {  r2=(p2-828)*5.54;  g2=255-(p2-828)*5.54;  b2=255-(p2-828)*5.54;}
if (p2>=874 and p2<920) {  r2=255;  g2=0;  b2=(p2-874)*5.54;}
if (p2>=920 and p2<966) {  r2=255;  g2=(p2-920)*5.54;  b2=255;}
if (p2>=966) {  r2=255;  g2=255-(p2-966)*5.54;  b2=255-(p2-966)*5.54;}
}

void turncolour(){
  // Calcul des intervals : p1=> rapidité de changement p2=>Ecart entre led1 et led 2
delay(2*p1);
t=t+1;
if (t>400) {t=0;}
//LED1
if (t<50)  {  r1=255;  g1=255-(t*5.1);  b1=(t*5.1);}
if (t>=50 and t<100) {  r1=255-(t-50)*5.1;  g1=(t-50)*5.1;  b1=255;}
if (t>=100 and t<150) {  r1=0;  g1=255-(t-100)*5.1;  b1=255;}
if (t>=150 and t<200) {  r1=0;  g1=(t-150)*5.1;;  b1=255-(t-150)*5.1;}
if (t>=200 and t<250) {  r1=(t-200)*5.1;  g1=255-(t-200)*5.1;  b1=0;}
if (t>=250 and t<300) {  r1=255-(t-250)*5.1;  g1=(t-250)*5.1;  b1=0;}
if (t>=300 and t<350) {  r1=0;  g1=255;  b1=(t-300)*5.1;}
if (t>=350 ) {  r1=(t-350)*5.1;  g1=255;  b1=255-(t-350)*5.1;}
//LED2
x=t+0.25*(p2);
t2=x;
if (t2>400) t2=t2-400;
if (t2<50)  {  r2=255;  g2=255-(t2*5.1);  b2=(t2*5.1);}
if (t2>=50 and t2<100) {  r2=255-(t2-50)*5.1;  g2=(t2-50)*5.1;  b2=255;}
if (t2>=100 and t2<150) {  r2=0;  g2=255-(t2-100)*5.1;  b2=255;}
if (t2>=150 and t2<200) {  r2=0;  g2=(t2-150)*5.1;;  b2=255-(t2-150)*5.1;}
if (t2>=200 and t2<250) {  r2=(t2-200)*5.1;  g2=255-(t2-200)*5.1;  b2=0;}
if (t2>=250 and t2<300) {  r2=255-(t2-250)*5.1;  g2=(t2-250)*5.1;  b2=0;}
if (t2>=300 and t2<350) {  r2=0;  g2=255;  b2=(t2-300)*5.1;}
if (t2>=350 ) {  r2=(t2-350)*5.1;  g2=255;  b2=255-(t2-350)*5.1;}
}

void soundflash() {
//p1 augmente la sensibilité
ecarttype();
s=map(t2,0,80,0,100);
if (s>p1/80) {
r1=255;
g1=255;
b1=255;
r2=255;
g2=255;
b2=255;}
else {r1=g1=b1=r2=b2=g2=0;}
}

void coloursound(){
//p1 choix de la couleur p2 sensibilité du son
//sensorsoundValue = analogRead(sensorsound);
if (p1<46)  {  r1=255;  g1=0;  b1=255-(p1*5.54);}
if (p1>=46 and p1<92) {  r1=255;  g1=(p1-46)*5.54;  b1=0;}
if (p1>=92 and p1<138) {  r1=255-(p1-92)*5.54;  g1=255;  b1=0;}
if (p1>=138 and p1<184) {  r1=(p1-138)*5.54;  g1=255;  b1=(p1-138)*5.54;}
if (p1>=184 and p1<230) {  r1=255-(p1-184)*5.54;  g1=255;  b1=255;}
if (p1>=230 and p1<276) {  r1=0;  g1=255-(p1-230)*5.54;  b1=255;}
if (p1>=276 and p1<322) {  r1=(p1-276)*5.54;  g1=0;  b1=255;}
if (p1>=322 and p1<368) {  r1=255;  g1=(p1-322)*5.54;  b1=255-(p1-322)*5.54;}
if (p1>=368 and p1<414) {  r1=255;  g1=255;  b1=(p1-368)*5.54;}
if (p1>=414 and p1<460) {  r1=255-(p1-414)*5.54;  g1=255-(p1-414)*5.54;  b1=255;}
if (p1>=460 and p1<506) {  r1=(p1-460)*5.54;  g1=0;  b1=255-(p1-460)*5.54;}
if (p1>=506 and p1<552) {  r1=255-(p1-506)*5.54;  g1=(p1-506)*5.54;  b1=0;}
if (p1>=552 and p1<598) {  r1=0;  g1=255;  b1=(p1-552)*5.54;}
if (p1>=598 and p1<644) {  r1=(p1-598)*5.54;  g1=255-(p1-598)*5.54;  b1=255;}
if (p1>=644 and p1<690) {  r1=255-(p1-644)*5.54;  g1=(p1-644)*5.54;  b1=255-(p1-644)*5.54;}
if (p1>=690 and p1<736) {  r1=0;  g1=255-(p1-690)*5.54;  b1=(p1-690)*5.54;}
if (p1>=736 and p1<782) {  r1=(p1-736)*5.54;  g1=(p1-736)*5.54;  b1=255-(p1-736)*5.54;}
if (p1>=782 and p1<828) {  r1=255-(p1-782)*5.54;  g1=255;  b1=(p1-782)*5.54;}
if (p1>=828 and p1<874) {  r1=(p1-828)*5.54;  g1=255-(p1-828)*5.54;  b1=255-(p1-828)*5.54;}
if (p1>=874 and p1<920) {  r1=255;  g1=0;  b1=(p1-874)*5.54;}
if (p1>=920 and p1<966) {  r1=255;  g1=(p1-920)*5.54;  b1=255;}
if (p1>=966) {  r1=255;  g1=255-(p1-966)*5.54;  b1=255-(p1-966)*5.54;}
ecarttype();
s=map(t2,0,p2/10,20,100);
if (s>100) {s=100;}
r1=r1*s/100;b1=b1*s/100;g1=g1*s/100;r2=r1;g2=g1;b2=b1;
}

void coloursoundnet(){
 // Effet de changement de couleur basé sur l'intensité sonore
 //p1 désynchronise devant et derrière, p2 sensibilité au son
  ecarttype();
  s= map(t2,0, p2/10, 0, 255); if (s>255) {s=255;} 
  r1 = s ;      // Rouge reste allumé à pleine intensité
  g1 = map(s, 0, 255, 0, 100);      // Vert varie de 0 à 100
  b1 = 255-s;      // Bleu varie de 255 à 0
  r2=r1;g2=g1;b2=b1;
 delay(p1/5);
}
