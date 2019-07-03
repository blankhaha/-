#include "Morse.h"
#define dot morse.dot()
#define dash morse.dash()
char MORSE[][4]={
  {'.','-','*','*'},//a
  {'-','.','.','.'},//b
  {'-','.','-','.'},//c
  {'-','.','.','*'},//d
  {'.','*','*','*'},//e
  {'.','.','-','.'},//f
  {'-','-','.','*'},//g
  {'.','.','.','.'},//h
  {'.','.','*','*'},//i
  {'.','-','-','-'},//j
  {'-','.','-','*'},//k
  {'.','-','.','.'},//l
  {'-','-','*','*'},//m
  {'-','.','*','*'},//n
  {'-','-','-','*'},//o
  {'.','-','-','.'},//p
  {'-','-','.','-'},//q
  {'.','-','.','*'},//r
  {'.','.','.','*'},//s
  {'-','*','*','*'},//t
  {'.','.','-','*'},//u
  {'.','.','.','-'},//v
  {'.','-','-','*'},//w
  {'-','.','.','-'},//x
  {'-','.','-','-'},//y
  {'-','-','.','.'},//z  
};


void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
}

void loop() {
  String str="";
  String morse="";
  int i,t,temp=0,n=0; 
  while(Serial.available()>0){
    temp=1;
    str=str+char(Serial.read());
    delay(2);
    n++;
  }
  if(temp){
    for(i=0;i<n;i++)
    {
      for(t=0;t<4;t++)
      {
        if(str[i]>+97&&str[i]<=122)
        {
          morse=morse+MORSE[int(str[i]-97)][t];
        }
      }
      morse=morse+' ';
    }
    Serial.println(morse);
  }
  delay(2);
}
