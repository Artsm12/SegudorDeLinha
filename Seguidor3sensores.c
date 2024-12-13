#pragma config(Sensor, S1,     SensorDireito,  sensorLightActive)
#pragma config(Sensor, S2,     SensorCentro,   sensorLightActive)
#pragma config(Sensor, S3,     SensorEsquerdo, sensorLightActive)
#pragma config(Motor,  motorA,          MotorDireito,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          MotorEsquerdo, tmotorNXT, PIDControl, encoder)

//Velocidade base do robo
#define VelocidadeBase 50

//Leitura do sensor quando ele ver a linha branca (possivelmente vai ser alterado)
#define LeituraSensor 45

task main(){

	while(true){
		
		//Se o sensor do meio estiver vendo a linha branca, entao o robo seve seguir em frente
		if(SensorValue[SensorCentro] >= LeituraSensor){
			motor[motorA] = VelocidadeBase;
			motor[motorB] = VelocidadeBase;
		}
		
		//Caso contrario
		else{

			//Se o sensor da direita estiver vendo a linha branca, entao o robo deve fazer curva para a direita
			if(SensorValue[SensorDireito] >= LeituraSensor && SensorValue[SensorEsquerdo] < LeituraSensor){
				motor[motorA] = VelocidadeBase - 40;
				motor[motorB] = VelocidadeBase;
			}
			
			//Se o sensor da esquerda estiver vendo a linha branca, entao o robo deve fazer curva para a esquerda
			else if(SensorValue[SensorEsquerdo] >= LeituraSensor && SensorValue[SensorDireito] < LeituraSensor){
				motor[motorA] = VelocidadeBase;
				motor[motorB] = VelocidadeBase - 40;
			}
		}
		
		//Tempo de espera para evitar sobrecarga
		wait1Msec(1);
	}
}