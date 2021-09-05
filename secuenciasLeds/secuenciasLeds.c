/* author: Luis López
 * Programa que realiza distintas secuencias de leds 
 * estados de leds 
 *led/bit pinwpi  pinGPIORasp
 * led1---wpi 22-----6---On-HIGH, Off-LOW  mas significativo
 * led2---wpi 23-----13---On-HIGH, Off-LOW
 * led3---wpi 24-----19---On-HIGH, Off-LOW
 * led4---wpi 25-----26---On-HIGH, Off-LOW menos significativo
 */
  
/*Bibliotecas */
#include <stdio.h>
#include <wiringPi.h> //nos permite manipular pines de raspberry

//constantes leds
#define led1 22
#define led2 23
#define led3 24
#define led4 25
//constantes de tiempo
#define tLed 200//0.2 segundos 
#define tSecuencia 5000 // 5 segundos

#define tOrden 30000//30 s
#define tOrdenInverso 90000 //90 s
//variables para control de tiempo
//variables de control tiempo de 0.2 segundos
double timeNow;
double timeLast;
//varibales de control tiempo 30 segundos
double timeNow30;
double timeLast30;
//varibales de control tiempo 90 segundos
double timeNow90;
double timeLast90;
//varibales para control tiempo exclusivo ascendente 5 seg
double timeNowExAsc;
double timeLastExAsc;
//variables para control tiempo exclusivo descendente 5 seg
double timeNowExDesc;
double timeLastExDesc;
//varibales para control tiempo aditivo ascendente 5 seg
double timeNowAdAsc;
double timeLastAdAsc;
//variables para control tiempo aditivo descendente 5 seg
double timeNowAdDesc;
double timeLastAdDesc;
//declaracion funciones
void apagar();
void encender();
void tiempoLeds();
void exAscendente();
void exDescendente();
void adAscendente();
void adDescendente();

//programa Principal
int main (void){
	//inicio Wiring Pi
	wiringPiSetup();
	//todos los leds como salida
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	//llamado a funciones	
	//repeticion por 30 segundos
	printf("SECUENCIAS EN ORDEN\n");
	timeLast30=millis();
	timeNow30=millis();
	while (timeNow30-timeLast30<tOrden){
		exAscendente();
		exDescendente();
		timeNow30=millis();
		if(timeNow30-timeLast30>tOrden){
			break;
		}
		adAscendente();
		timeNow30=millis();
		if(timeNow30-timeLast30>tOrden){
			break;
		}
		adDescendente();
		timeNow30=millis();
	}
	printf("\nSECUENCIAS EN ORDEN INVERSO\n");
	timeLast90=millis();
	timeNow90=millis();
	while (timeNow90-timeLast90<tOrdenInverso){
		adDescendente();
		adAscendente();
		timeNow90=millis();
		if(timeNow90-timeLast90>tOrdenInverso){
			break;
		}
		exDescendente();
		timeNow90=millis();
		if(timeNow90-timeLast90>tOrdenInverso){
			break;
		}
		exAscendente();
		timeNow90=millis();
	}
	return 0;
}

/*funcion que apaga todos los leds*/
void apagar(){
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);
}
void encender(){
	digitalWrite(led1, HIGH);
	digitalWrite(led2, HIGH);
	digitalWrite(led3, HIGH);
	digitalWrite(led4, HIGH);
}
/*funcion que hace la espera de 0.2 segundos para cambiar
 * estado de cada led
 */ 
void tiempoLeds(){
	timeLast=millis();
	timeNow=millis();
	while(timeNow-timeLast<tLed){
		timeNow=millis();	
	}
}
/*secuencia exclusiva ascendente
 */
void exAscendente(){
	printf("Secuencia exclusiva ascendente\n");
	timeLastExAsc=millis();
	timeNowExAsc=millis();
	//int vuelta=0;
	while(timeNowExAsc-timeLastExAsc<tSecuencia){
		//todos apagados
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		tiempoLeds();
		//resto secuencia
		digitalWrite(led1,HIGH);
		tiempoLeds();
		digitalWrite(led2,HIGH);
		digitalWrite(led1,LOW);
		tiempoLeds();
		digitalWrite(led3,HIGH);
		digitalWrite(led2,LOW);
		tiempoLeds();
		digitalWrite(led4,HIGH);
		digitalWrite(led3,LOW);
		tiempoLeds();
		digitalWrite(led4,LOW);
		tiempoLeds();
		timeNowExAsc=millis();
	}
}
/*secuencia exclusiva descendente
 */ 
void exDescendente(){
	printf("Secuencia exclusiva descendente\n");
	timeLastExDesc=millis();
	timeNowExDesc=millis();
	while(timeNowExDesc-timeLastExDesc<tSecuencia){
		//todos apagados
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		tiempoLeds();
		//secuencia
		digitalWrite(led4,HIGH);
		tiempoLeds();
		digitalWrite(led3,HIGH);
		digitalWrite(led4,LOW);
		tiempoLeds();
		digitalWrite(led2,HIGH);
		digitalWrite(led3,LOW);
		tiempoLeds();
		digitalWrite(led1,HIGH);
		digitalWrite(led2,LOW);
		tiempoLeds();
		digitalWrite(led1,LOW);
		tiempoLeds();
		timeNowExDesc=millis();
	}	
}
/*secuencia aditiva ascendente
 */ 
void adAscendente(){
	printf("Secuencia aditiva ascendente\n");
	timeLastAdAsc=millis();
	timeNowAdAsc=millis();
	while(timeNowAdAsc-timeLastAdAsc<tSecuencia){
		//todos apagados
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		tiempoLeds();
		//secuencia
		digitalWrite(led1,HIGH);
		tiempoLeds();
		digitalWrite(led2,HIGH);
		tiempoLeds();
		digitalWrite(led3,HIGH);
		tiempoLeds();
		digitalWrite(led4,HIGH);
		tiempoLeds();
		timeNowAdAsc=millis();
	}
}
/*secuencia aditiva descendente
 */ 
void adDescendente(){
	printf("Secuencia aditiva descendente\n");
	timeLastAdDesc=millis();
	timeNowAdDesc=millis();
	while(timeNowAdDesc-timeLastAdDesc<tSecuencia){
		//todos apagados
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		tiempoLeds();
		//secuencia
		digitalWrite(led1,HIGH);
		digitalWrite(led2,HIGH);
		digitalWrite(led3,HIGH);
		digitalWrite(led4,HIGH);
		tiempoLeds();
		digitalWrite(led4,LOW);
		tiempoLeds();
		digitalWrite(led3,LOW);
		tiempoLeds();
		digitalWrite(led2,LOW);
		tiempoLeds();
		digitalWrite(led1,LOW);
		tiempoLeds();
		timeNowAdDesc=millis();
	}
}
	



