#pragma config(Sensor, S1,     SensorDeLuz,    sensorLightActive)
#pragma config(Motor,  motorA,          MotorEsquerdo, tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorB,          MotorDireito,  tmotorNXT, PIDControl, driveRight, encoder)

//Quantidade de luz captada pelo sensor (possivelmente vai ser alterado)
#define ReflexoLuz 30

task main(){

	while(true){

		//Quando o sensor ver a parte preta da percurso, ele vai fazer curva para a direita
		if(SensorValue[SensorDeLuz] < ReflexoLuz){
			motor[MotorEsquerdo] = 50;
			motor[MotorDireito] = 0;
		}

		//Quando o sensor ver a parte branca do percurso, ele vai fazer curva para a esquerda
		else{
			motor[MotorEsquerdo] = 0;
			motor[MotorDireito] = 50;
		}

	//Tempo de espera para nao sobrecarregar o robo
	wait1Msec(1);
	}
}