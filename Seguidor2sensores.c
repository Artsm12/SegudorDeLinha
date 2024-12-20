#pragma config(Sensor, S1,     SensorDireito,  sensorLightActive)
#pragma config(Sensor, S2,     SensorEsquerdo, sensorLightActive)
#pragma config(Motor,  motorA,          MotorDireito,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          MotorEsquerdo, tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Velocidade base do robo
#define VelocidadeBase 50

//Leitura do sensor quando ele estiver vendo a linha branca (possivelmente vai ser mudado)
#define LeituraSensor 45

task main(){

	while(true){

		//Se ambos os sensores verem a cor preta, isso quer dizer que o robo esta em cima da linha branca, portanto, deve seguir reto
		if(SensorValue[SensorDireito] < LeituraSensor && SensorValue[SensorEsquerdo] < LeituraSensor){
			motor[motorA] = VelocidadeBase;
			motor[motorB] = VelocidadeBase;
		}

		//Caso contrario
		else{

			//Se ele estiver vendo a cor preta na esquerda e a cor branca na direita, ele deve virar a direita
			if(SensorValue[SensorDireito] >= LeituraSensor && SensorValue[SensorEsquerdo] < LeituraSensor){
				motor[motorA] = VelocidadeBase - 40;
				motor[motorB] = VelocidadeBase;
			}

			//Se ele estiver vendo a cor preta na direita e a cor branca na esquerda, ele deve virar a esquerda
			else if(SensorValue[SensorEsquerdo] >= LeituraSensor && SensorValue[SensorDireito] < LeituraSensor){
				motor[motorA] = VelocidadeBase;
				motor[motorB] = VelocidadeBase - 40;
			}

			//Se ele estiver vendo a cor branca dos dois lados, ele deve seguir reto
			else{
				motor[motorA] = VelocidadeBase;
				motor[motorB] = VelocidadeBase;
			}

		}
		//Tempo de espera para evitar sobrecarga
		wait1Msec(1);
	}
}
