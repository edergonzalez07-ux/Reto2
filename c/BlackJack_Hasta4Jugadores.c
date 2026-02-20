#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //Para poder usar rand()
#include <time.h> //Usado para generar una semilla para el campo [s]rand() "aleatorio"
#include <locale.h>


//Creación de la funcion que genera cartas (variablles globales, se pueden creaar fuera del programa porque no van a variar) 
int sacarCarta() {
    int carta = (rand() % 13) + 1;
    return carta;
}
	
//Cracion de la funcion que guarda el valor numerico de la carta
int valorCarta(int carta) {
	int valor = 0;
	if (carta == 1)
		valor = 11;
	else if (carta >= 11 && carta <= 13)
		valor = 10;
	else
		valor = carta;
	return valor;
}
	
//Creacion de funcion para mostrar las cartas
void mostrarCarta(int carta) {
    if (carta == 1)
        printf("A");
    else if (carta == 11)
        printf("J");
    else if (carta == 12)
        printf("Q");
    else if (carta == 13)
        printf("K");
    else
        printf("%d", carta);
}

//Funcion mostrar segunda carta CPU1
void mostrarCarta2CPU1(int carta2CPU1) {
    if (carta2CPU1 == 1)
        printf("A");
    else if (carta2CPU1 == 11)
        printf("J");
    else if (carta2CPU1 == 12)
        printf("Q");
    else if (carta2CPU1 == 13)
        printf("K");
    else
        printf("%d", carta2CPU1);
}

//Funcion mostrar segunda carta CPU2
void mostrarCarta2CPU2(int carta2CPU2) {
    if (carta2CPU2 == 1)
        printf("A");
    else if (carta2CPU2 == 11)
        printf("J");
    else if (carta2CPU2 == 12)
        printf("Q");
    else if (carta2CPU2 == 13)
        printf("K");
    else
        printf("%d", carta2CPU2);
}

//Funcion mostrar segunda carta CPU3
void mostrarCarta2CPU3(int carta2CPU3) {
    if (carta2CPU3 == 1)
        printf("A");
    else if (carta2CPU3 == 11)
        printf("J");
    else if (carta2CPU3 == 12)
        printf("Q");
    else if (carta2CPU3 == 13)
        printf("K");
    else
        printf("%d", carta2CPU3);
}

	
//Inicio del programa
void main() {
	
	//Inicializa una nueva semilla aleatoria según la hora del sistema
	srand(time(NULL));
	
	//Idioma español
	setlocale(LC_CTYPE, "Spanish");
	
	//Creación de variables
	int carta, valor, contrincantes, sumaJugador = 0, sumaCPU1 = 0, sumaCPU2 = 0, sumaCPU3 = 0, asJugador = 0, asCPU1 = 0, asCPU2 = 0, asCPU3 = 0, carta2CPU1 = 0, carta2CPU2 = 0, carta2CPU3 = 0, jugadores21 = 0, jugadoresPasados=0;
	char opcion;
	
	//Inicio de juego
	system("cls");
	printf("-- JUEGO BLACKJACK --\n");
	printf("¿Cuantos contrincantes quieres?\nInserta 1 - 2 - 3: ");
	contrincantes = getche();
	switch(contrincantes){
		case '1':
			contrincantes = 1;
			break;
    	case '2':
    		contrincantes = 2;
			break;
    	case '3':
    		contrincantes = 3;
			break;
    	default:
    		printf("\nEse no es un caracter válido");
			break;
	}
	
	
	//Primera carta jugador
	carta = sacarCarta();
	valor = valorCarta(carta);
	sumaJugador += valor;
	if (carta == 1) {
		asJugador++;
	}
	while (sumaJugador > 21 && asJugador > 0) {
    	sumaJugador -= 10;
    	asJugador--;
	}
	printf("\n\nTu primera carta: ");
	mostrarCarta(carta);
	
	//Segunda carta jugador
	carta = sacarCarta();
	valor = valorCarta(carta);
	sumaJugador += valor;
	if (carta == 1) {
		asJugador++;
	}
	while (sumaJugador > 21 && asJugador > 0) {
    	sumaJugador -= 10;
    	asJugador--;
	}
	printf("\nTu segunda carta: ");
	mostrarCarta(carta);
	
	
	//Primera carta CPU1
	carta = sacarCarta();
	valor = valorCarta(carta);
	sumaCPU1 += valor;
	if (carta == 1) {
		asCPU1++;
	}
	while (sumaCPU1 > 21 && asCPU1 > 0) {
    	sumaCPU1 -= 10;
    	asCPU1--;
	}
	printf("\n\nPrimera carta de CPU1: ");
	mostrarCarta(carta);
	
	
	//Primera carta CPU2 (opcional)
	if(contrincantes >= 2) {
		carta = sacarCarta();
		valor = valorCarta(carta);
		sumaCPU2 += valor;
		if (carta == 1) {
			asCPU2++;
		}
		while (sumaCPU2 > 21 && asCPU2 > 0) {
    		sumaCPU2 -= 10;
    		asCPU2--;
		}
		printf("\nPrimera carta de CPU2: ");
		mostrarCarta(carta);
	}
	
	
	//Primera carta CPU3 (opcional)
	if(contrincantes >= 3) {
		carta = sacarCarta();
		valor = valorCarta(carta);
		sumaCPU3 += valor;
		if (carta == 1) {
			asCPU3++;
		}
		while (sumaCPU3 > 21 && asCPU3 > 0) {
    		sumaCPU3 -= 10;
    		asCPU3--;
		}
		printf("\nPrimera carta de CPU3: ");
		mostrarCarta(carta);
	}
	
	
	//Segundo turno de CPU1 (oculto)
	carta = sacarCarta();
	valor = valorCarta(carta);
	sumaCPU1 += valor;
	if (carta == 1) {
	asCPU1++;
	}
	while (sumaCPU1 > 21 && asCPU1 > 0) {
    	sumaCPU1 -= 10;
    	asCPU1--;
	}
	carta2CPU1 = carta;
	//printf("\n\nSegunda carta de CPU1: ");
	//mostrarCarta(carta);
	
	
	//Segundo turno de CPU2 (oculto) (opcional)
	if(contrincantes >= 2) {
		carta = sacarCarta();
		valor = valorCarta(carta);
		sumaCPU2 += valor;
		if (carta == 1) {
		asCPU2++;
		}
		while (sumaCPU2 > 21 && asCPU2 > 0) {
    		sumaCPU2 -= 10;
    		asCPU2--;
		}
		carta2CPU2 = carta;
		//printf("\nSegunda carta de CPU2: ");
		//mostrarCarta(carta);
	}
	
	
	//Segundo turno de CPU3 (oculto) (opcional)
	if(contrincantes >= 3) {
		carta = sacarCarta();
		valor = valorCarta(carta);
		sumaCPU3 += valor;
		if (carta == 1) {
		asCPU3++;
		}
		while (sumaCPU3 > 21 && asCPU3 > 0) {
    		sumaCPU3 -= 10;
    		asCPU3--;
		}
		carta2CPU3 = carta;
		//printf("\nSegunda carta de CPU3: ");
		//mostrarCarta(carta);
	}
	
	
	//Resultado segundo turno == 21
	if (sumaJugador == 21 || sumaCPU1 == 21 || sumaCPU2 == 21 || sumaCPU3 == 21) {
		
		//Mostrar segundo turno de CPU1
		printf("\n\nSegunda carta de CPU1: ");
		mostrarCarta2CPU1(carta2CPU1);
		
		//Segundo turno de CPU2
		if(contrincantes >= 2) {
			printf("\nSegunda carta de CPU2: ");
			mostrarCarta2CPU2(carta2CPU2);
		}
		
		//Segundo turno de CPU3
		if(contrincantes >= 3) {
			printf("\nSegunda carta de CPU3: ");
			mostrarCarta2CPU3(carta2CPU3);
		}
			
		if(sumaJugador == 21)
			jugadores21++;
		if(sumaCPU1 == 21)
			jugadores21++;
		if(sumaCPU2 == 21)
			jugadores21++;
		if(sumaCPU3 == 21)
			jugadores21++;
		
		if(jugadores21 == 1) {
			if(sumaJugador == 21)
				printf("\n\n¡Has ganado con 21!");
			else if(sumaCPU1 == 21)
				printf("\n\n¡CPU1 ha ganado con 21!");
			else if(sumaCPU2 == 21)
				printf("\n\n¡CPU2 ha ganado con 21!");
			else if(sumaCPU3 == 21)
				printf("\n\n¡CPU3 ha ganado con 21!");
		}
			
		if(jugadores21 == 2) {
			if(sumaJugador == sumaCPU1)
				printf("\n\n¡Empate! Han ganado Jugador y CPU1");
			if(sumaJugador == sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador y CPU2");
			if(sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador y CPU3");
			if(sumaCPU1 == sumaCPU2)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
			if(sumaCPU1 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
			if(sumaCPU2 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
			}
		
		if(jugadores21 == 3) {
			if(sumaJugador == sumaCPU1 && sumaJugador == sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			if(sumaJugador == sumaCPU1 && sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			if(sumaJugador == sumaCPU2 && sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			if(sumaCPU1 == sumaCPU2 && sumaCPU1 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
		}
		
		if(jugadores21 == 4){
			printf("\n\n¡Empate! Todos han sumado 21");
		}
		
		printf("\nResultados: Jugador %d  - CPU1 %d", sumaJugador, sumaCPU1);
		if(contrincantes >= 2) {
			printf(" - CPU2 %d", sumaCPU2);
		}
		if(contrincantes >= 3) {
			printf(" - CPU3 %d", sumaCPU3);
		}
		printf("\nFin del juego.\n");
		return;
	}
	
	
	//Bucle para pedir mas cartas jugador
	if (sumaJugador >= 21) {
	}else {
		do {
        	printf("\n\nQuieres otra carta? (s/n): ");
        	opcion = getche();
        	if (opcion == 's' || opcion == 'S') {
            	carta = sacarCarta();
            	valor = valorCarta(carta);
				sumaJugador += valor;
            	if (carta == 1) {
					asJugador++;
				}
				while (sumaJugador > 21 && asJugador > 0) {
    				sumaJugador -= 10;
    				asJugador--;
				}
            	printf("\nHas sacado: ");
            	mostrarCarta(carta);
        	}
    	} while ((opcion == 's' || opcion == 'S') && sumaJugador < 21);
	}    
	
	
	//Mostrar segundo turno de CPU1
	printf("\n\nSegunda carta de CPU1: ");
	mostrarCarta2CPU1(carta2CPU1);
	
	
	//Segundo turno de CPU2
	if(contrincantes >= 2) {
		printf("\nSegunda carta de CPU2: ");
		mostrarCarta2CPU2(carta2CPU2);
	}
	
	
	//Segundo turno de CPU3
	if(contrincantes >= 3) {
		printf("\nSegunda carta de CPU3: ");
		mostrarCarta2CPU3(carta2CPU3);
	}
	
	//Estética
	printf("\n");
	
	//Bucle sacar cartas CPU1
	while (sumaCPU1 < 17) {
    	carta = sacarCarta();
		valor = valorCarta(carta);
		sumaCPU1 += valor;
    	if (carta == 1) {
			asCPU1++;
		}
		while (sumaCPU1 > 21 && asCPU1 > 0) {
    		sumaCPU1 -= 10;
    		asCPU1--;
		}
		printf("\nCPU1 ha sacado: ");
		mostrarCarta(carta);
    }
    
    
    //Bucle sacar cartas CPU2
	if(contrincantes >= 2) {
		while (sumaCPU2 < 17) {
    		carta = sacarCarta();
			valor = valorCarta(carta);
			sumaCPU2 += valor;
    		if (carta == 1) {
				asCPU2++;
			}
			while (sumaCPU2 > 21 && asCPU2 > 0) {
    			sumaCPU2 -= 10;
    			asCPU2--;
			}
			printf("\nCPU2 ha sacado: ");
			mostrarCarta(carta);
    	}
    }
    
    
    //Bucle sacar cartas CPU3
	if(contrincantes >= 3) {
		while (sumaCPU3 < 17) {
    		carta = sacarCarta();
			valor = valorCarta(carta);
			sumaCPU3 += valor;
    		if (carta == 1) {
				asCPU3++;
			}
			while (sumaCPU3 > 21 && asCPU3 > 0) {
    			sumaCPU3 -= 10;
    			asCPU3--;
			}
			printf("\nCPU3 ha sacado: ");
			mostrarCarta(carta);
    	}
    }
	
	
	//Resultado final == 21
	if (sumaJugador == 21 || sumaCPU1 == 21 || sumaCPU2 == 21 || sumaCPU3 == 21) {
		if(sumaJugador == 21)
			jugadores21++;
		if(sumaCPU1 == 21)
			jugadores21++;
		if(sumaCPU2 == 21)
			jugadores21++;
		if(sumaCPU3 == 21)
			jugadores21++;
		
		if(jugadores21 == 1) {
			if(sumaJugador == 21)
				printf("\n\n¡Has ganado con 21!");
			else if(sumaCPU1 == 21)
				printf("\n\n¡CPU1 ha ganado con 21!");
			else if(sumaCPU2 == 21)
				printf("\n\n¡CPU2 ha ganado con 21!");
			else if(sumaCPU3 == 21)
				printf("\n\n¡CPU3 ha ganado con 21!");
		}
			
		if(jugadores21 == 2) {
			if(sumaJugador == sumaCPU1)
				printf("\n\n¡Empate! Han ganado Jugador y CPU1");
			if(sumaJugador == sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador y CPU2");
			if(sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador y CPU3");
			if(sumaCPU1 == sumaCPU2)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
			if(sumaCPU1 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
			if(sumaCPU2 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
			}
		
		if(jugadores21 == 3) {
			if(sumaJugador == sumaCPU1 && sumaJugador == sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			if(sumaJugador == sumaCPU1 && sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU3");
			if(sumaJugador == sumaCPU2 && sumaJugador == sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU2 y CPU3");
			if(sumaCPU1 == sumaCPU2 && sumaCPU1 == sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU1, CPU2 y CPU3");
		}
		
		if(jugadores21 == 4){
			printf("\n\n¡Empate! Todos han sumado 21");
		}
		
		printf("\nResultados: Jugador %d  - CPU1 %d", sumaJugador, sumaCPU1);
		if(contrincantes >= 2) {
			printf(" - CPU2 %d", sumaCPU2);
		}
		if(contrincantes >= 3) {
			printf(" - CPU3 %d", sumaCPU3);
		}
		printf("\nFin del juego.\n");
		return;
	}
	
	
	
	
	
	//Resultado final != 21
	if(contrincantes == 1) {
		if(sumaJugador > 21 && sumaCPU1 > 21) {
			printf("\n\n¡Empate! Ambos se han pasado");
		}else if (sumaCPU1 > 21) {
        	printf("\n\nCPU1 se ha pasado. ¡Has ganado!");
    	}else if (sumaJugador > 21) {
    	    printf("\n\nTe has pasado. ¡Has perdido!");
    	}else if (sumaJugador == sumaCPU1) {
    	    printf("\n\n¡Empate!");
    	}else if(sumaJugador > sumaCPU1) {
    	    printf("\n\n¡Has ganado!");
    	}else{
    		printf("\n\n¡Has perdido!");
    	}
	}
	
	if(contrincantes == 2)
	if(sumaJugador > 21)
			jugadoresPasados++;
		if(sumaCPU1 > 21)
			jugadoresPasados++;
		if(sumaCPU2 > 21)
			jugadoresPasados++;
		
		if(jugadoresPasados == 3) {
			printf("\n\n¡Empate! Todos se han pasado de 21");
		}
		
		if(jugadoresPasados == 2) {
			if(sumaJugador < 21)
				printf("\n\n¡Has ganado!");
			else if(sumaCPU1 < 21)
				printf("\n\n¡CPU1 ha ganado!");
			else if(sumaCPU2 < 21)
				printf("\n\n¡CPU2 ha ganado!");
		}
		
		if(jugadoresPasados == 1) {
			if(sumaJugador < 21 && sumaCPU1 < 21) {
				if(sumaJugador > sumaCPU1)
					printf("\n\n¡Has ganado!");
				else if(sumaJugador < sumaCPU1)
					printf("\n\n¡CPU1 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado Jugador y CPU1");
			}
			if(sumaJugador < 21 && sumaCPU2 < 21) {
				if(sumaJugador > sumaCPU2)
					printf("\n\n¡Has ganado!");
				else if(sumaJugador < sumaCPU2)
					printf("\n\n¡CPU2 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado Jugador y CPU2");
			}
			if(sumaCPU1 < 21 && sumaCPU2 < 21) {
				if(sumaCPU1 > sumaCPU2)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU1 < sumaCPU2)
					printf("\n\n¡CPU2 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
			}
		}
	
	
	if(contrincantes == 3) {
		if(sumaJugador > 21)
			jugadoresPasados++;
		if(sumaCPU1 > 21)
			jugadoresPasados++;
		if(sumaCPU2 > 21)
			jugadoresPasados++;
		if(sumaCPU3 > 21)
			jugadoresPasados++;
		
		if(jugadoresPasados == 4) {
			printf("\n\n¡Empate! Todos se han pasado de 21");
		}
		
		if(jugadoresPasados == 3) {
			if(sumaJugador < 21)
				printf("\n\n¡Has ganado!");
			else if(sumaCPU1 < 21)
				printf("\n\n¡CPU1 ha ganado!");
			else if(sumaCPU2 < 21)
				printf("\n\n¡CPU2 ha ganado!");
			else if(sumaCPU3 < 21)
				printf("\n\n¡CPU3 ha ganado!");
		}
				
		if(jugadoresPasados == 2) {
			if(sumaJugador < 21 && sumaCPU1 < 21) {
				if(sumaJugador > sumaCPU1)
					printf("\n\n¡Has ganado!");
				else if(sumaJugador < sumaCPU1)
					printf("\n\n¡CPU1 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado Jugador y CPU1");
			}
			if(sumaJugador < 21 && sumaCPU2 < 21) {
				if(sumaJugador > sumaCPU2)
					printf("\n\n¡Has ganado!");
				else if(sumaJugador < sumaCPU2)
					printf("\n\n¡CPU2 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado Jugador y CPU2");
			}
			if(sumaJugador < 21 && sumaCPU3 < 21) {
				if(sumaJugador > sumaCPU3)
					printf("\n\n¡Has ganado!");
				else if(sumaJugador < sumaCPU3)
					printf("\n\n¡CPU3 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado Jugador y CPU3");
			}
			if(sumaCPU1 < 21 && sumaCPU2 < 21) {
				if(sumaCPU1 > sumaCPU2)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU1 < sumaCPU2)
					printf("\n\n¡CPU2 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
			}
			if(sumaCPU1 < 21 && sumaCPU3 < 21) {
				if(sumaCPU1 > sumaCPU3)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU1 < sumaCPU3)
					printf("\n\n¡CPU3 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
			}
			if(sumaCPU2 < 21 && sumaCPU3 < 21) {
				if(sumaCPU2 > sumaCPU3)
					printf("\n\n¡CPU2 ha ganado!");
				else if(sumaCPU2 < sumaCPU3)
					printf("\n\n¡CPU3 ha ganado!");
				else
					printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
			}
		}
		
		if(jugadoresPasados == 1) {
			if(sumaJugador < 21 && sumaCPU1 < 21 && sumaCPU2 < 21) {
				if(sumaJugador > sumaCPU1 && sumaJugador > sumaCPU2)
					printf("\n\n¡Has ganado!");
				else if(sumaCPU1 > sumaJugador && sumaCPU1 > sumaCPU2)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU1)
					printf("\n\n¡CPU2 ha ganado!");
				else if(sumaJugador > sumaCPU2 && sumaCPU1 > sumaCPU2)
					printf("\n\n¡Empate! Han ganado Jugador y CPU1");
				else if(sumaJugador > sumaCPU1 && sumaCPU2 > sumaCPU1)
					printf("\n\n¡Empate! Han ganado Jugador y CPU2");
				else if(sumaCPU1 > sumaJugador && sumaCPU2 > sumaJugador)
					printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
				else
					printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			}
			if(sumaJugador < 21 && sumaCPU1 < 21 && sumaCPU3 < 21) {
				if(sumaJugador > sumaCPU1 && sumaJugador > sumaCPU3)
					printf("\n\n¡Has ganado!");
				else if(sumaCPU1 > sumaJugador && sumaCPU1 > sumaCPU3)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU3 > sumaJugador && sumaCPU3 > sumaCPU1)
					printf("\n\n¡CPU3 ha ganado!");
				else if(sumaJugador > sumaCPU3 && sumaCPU1 > sumaCPU3)
					printf("\n\n¡Empate! Han ganado Jugador y CPU1");
				else if(sumaJugador > sumaCPU1 && sumaCPU3 > sumaCPU1)
					printf("\n\n¡Empate! Han ganado Jugador y CPU3");
				else if(sumaCPU1 > sumaJugador && sumaCPU3 > sumaJugador)
					printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
				else
					printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU3");
			}
			if(sumaJugador < 21 && sumaCPU2 < 21 && sumaCPU3 < 21) {
				if(sumaJugador > sumaCPU2 && sumaJugador > sumaCPU3)
					printf("\n\n¡Has ganado!");
				else if(sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU3)
					printf("\n\n¡CPU2 ha ganado!");
				else if(sumaCPU3 > sumaJugador && sumaCPU3 > sumaCPU2)
					printf("\n\n¡CPU3 ha ganado!");
				else if(sumaJugador > sumaCPU3 && sumaCPU2 > sumaCPU3)
					printf("\n\n¡Empate! Han ganado Jugador y CPU2");
				else if(sumaJugador > sumaCPU2 && sumaCPU3 > sumaCPU2)
					printf("\n\n¡Empate! Han ganado Jugador y CPU3");
				else if(sumaCPU2 > sumaJugador && sumaCPU3 > sumaJugador)
					printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
				else
					printf("\n\n¡Empate! Han ganado Jugador, CPU2 y CPU3");
			}
			if(sumaCPU1 < 21 && sumaCPU2 < 21 && sumaCPU3 < 21) {
				if(sumaCPU1 > sumaCPU2 && sumaCPU1 > sumaCPU3)
					printf("\n\n¡CPU1 ha ganado!");
				else if(sumaCPU2 > sumaCPU1 && sumaCPU2 > sumaCPU3)
					printf("\n\n¡CPU2 ha ganado!");
				else if(sumaCPU3 > sumaCPU1 && sumaCPU3 > sumaCPU2)
					printf("\n\n¡CPU3 ha ganado!");
				else if(sumaCPU1 > sumaCPU3 && sumaCPU2 > sumaCPU3)
					printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
				else if(sumaCPU1 > sumaCPU2 && sumaCPU3 > sumaCPU2)
					printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
				else if(sumaCPU2 > sumaCPU1 && sumaCPU3 > sumaCPU1)
					printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
				else
					printf("\n\n¡Empate! Han ganado CPU1, CPU2 y CPU3");
			}
		}
		
		if(jugadoresPasados == 0) {
			//1 ganador
			if(sumaJugador > sumaCPU1 && sumaJugador > sumaCPU2 && sumaJugador > sumaCPU3)
				printf("\n\n¡Has ganado!");
			else if(sumaCPU1 > sumaJugador && sumaCPU1 > sumaCPU2 && sumaCPU1 > sumaCPU3)
				printf("\n\n¡CPU1 ha ganado!");
			else if(sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU1 && sumaCPU2 > sumaCPU3)
				printf("\n\n¡CPU2 ha ganado!");
			else if(sumaCPU3 > sumaJugador && sumaCPU3 > sumaCPU1 && sumaCPU3 > sumaCPU2)
				printf("\n\n¡CPU3 ha ganado!");
			//2 ganadores
			else if(sumaJugador > sumaCPU2 && sumaJugador > sumaCPU3 && sumaCPU1 > sumaCPU2 && sumaCPU1 > sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador y CPU1");
			else if(sumaJugador > sumaCPU1 && sumaJugador > sumaCPU3 && sumaCPU2 > sumaCPU1 && sumaCPU2 > sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador y CPU2");
			else if(sumaJugador > sumaCPU1 && sumaJugador > sumaCPU2 && sumaCPU3 > sumaCPU1 && sumaCPU3 > sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador y CPU3");
			else if(sumaCPU1 > sumaJugador && sumaCPU1 > sumaCPU3 && sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU3)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU2");
			else if(sumaCPU1 > sumaJugador && sumaCPU1 > sumaCPU2 && sumaCPU3 > sumaJugador && sumaCPU3 > sumaCPU2)
				printf("\n\n¡Empate! Han ganado CPU1 y CPU3");
			else if(sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU1 && sumaCPU2 > sumaJugador && sumaCPU2 > sumaCPU1)
				printf("\n\n¡Empate! Han ganado CPU2 y CPU3");
			//3 ganadores
			else if(sumaJugador > sumaCPU3 && sumaCPU1 > sumaCPU3 && sumaCPU2 > sumaCPU3)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU2");
			else if(sumaJugador > sumaCPU2 && sumaCPU1 > sumaCPU2 && sumaCPU3 > sumaCPU2)
				printf("\n\n¡Empate! Han ganado Jugador, CPU1 y CPU3");
			else if(sumaJugador > sumaCPU1 && sumaCPU2 > sumaCPU1 && sumaCPU3 > sumaCPU1)
				printf("\n\n¡Empate! Han ganado Jugador, CPU2 y CPU3");
			else if(sumaCPU1 > sumaJugador && sumaCPU2 > sumaJugador && sumaCPU3 > sumaJugador)
				printf("\n\n¡Empate! Han ganado CPU1, CPU2 y CPU3");
			//4 ganadores
			else
				printf("\n\n¡Empate! Todos han sumado %d", sumaJugador);
		}
	}
	
	printf("\nResultados: Jugador %d  - CPU1 %d", sumaJugador, sumaCPU1);
	if(contrincantes >= 2) {
		printf(" - CPU2 %d", sumaCPU2);
	}
	if(contrincantes >= 3) {
		printf(" - CPU3 %d", sumaCPU3);
	}
	printf("\nFin del juego.\n");
}
