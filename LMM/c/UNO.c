#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //Para poder usar rand()
#include <time.h> //Usado para generar una semilla para el campo [s]rand() "aleatorio"
#include <locale.h>

//Función que genera cartas
int sacarCarta() {
	int carta = 15;
    do{
		carta = (rand() % 15);
    	if(carta == 0 || carta == 13 || carta == 14){
    		int prob = (rand() % 2);
    		if(prob == 0) {
    			return carta;
			}else continue;
		}else {
			return carta;
		}
    } while(carta == 15);
}

//Función que agrega color a las cartas
int sacarColor(int carta) {
	if(carta == 13  || carta == 14) {
		return 0;
	}else {
		int color = (rand() % 4) + 1;
		return color;
	}
}


//Función que mustra las cartas
void mostrarCarta(int carta, int color) {
    if(carta >= 0 && carta <= 9) {
        printf("%d", carta);
    }else if (carta == 10) {
        printf("Bloqueo");
    }else if (carta == 11) {
        printf("Cambio de sentido");
    }else if (carta == 12) {
        printf("+2");
    }else if (carta == 13) {
        printf("+4");
    }else if (carta == 14) {
        printf("Cambio de color");
    }
    
    if(color == 1) printf(" Rojo\n");
	else if(color == 2) printf(" Amarillo\n");
	else if(color == 3) printf(" Verde\n");
	else if(color == 4) printf(" Azul\n");
	else if(color == 0) printf("\n");
}


//Inicio del programa
void main(){
	
	//Inicializa una nueva semilla aleatoria según la hora del sistema
	srand(time(NULL));
	
	//Idioma español
	setlocale(LC_CTYPE, "Spanish");
	
	//Creación de variables
	int carta, color, i, j, partidaTerminada = 0;  //Variables básicas
	int cartasJugadorValor[50], cartasJugadorColor[50], contJugador = 0;  //Variables del jugador
	int cartasCPUValor[50], cartasCPUColor[50], contCPU = 0, juegoCPU, cartaValidaJugador, cartaValidaCPU;  //Variables de la CPU
	int cartaMesaValor, cartaMesaColor, turno = 0, eleccion, colorEspecial;  //Variables de turnos
	int bloqueoJugador = 0, cambioSentidoJugador = 0, suma2Jugador = 0, suma4Jugador = 0, cambioColorJugador = 0, valorJugador, colorJugador, especialJugador;  //Cartas especiales (que tira el) jugador
	int bloqueoCPU = 0, cambioSentidoCPU = 0, suma2CPU = 0, suma4CPU = 0, cambioColorCPU = 0, especialCPU;  //Cartas especiales (que tira la) CPU
	
	
//Inicio del juego
	//Limpiar pantalla
	system("cls");
	printf("-- UNO --\n\n");

	//Repartir cartas jugador
	for(i = 0; i < 7; i++) {
		cartasJugadorValor[contJugador] = sacarCarta();
		cartasJugadorColor[contJugador] = sacarColor(cartasJugadorValor[contJugador]);
		contJugador++;
	}
	//Repartir cartas CPU
	for(i = 0; i < 7; i++) {
		cartasCPUValor[contCPU] = sacarCarta();
		cartasCPUColor[contCPU] = sacarColor(cartasCPUValor[contCPU]);
		contCPU++;
	}
	
	//Sacar primera carta sobre la mesa
	cartaMesaValor = sacarCarta();
	cartaMesaColor = sacarColor(cartaMesaValor);
	if(cartaMesaValor == 13 || cartaMesaValor == 14){
		cartaMesaColor = (rand() % 4) + 1;
	}
	
	
	//Bucle turnos (juego principal)
	do{
		//Mostrar carta en la mesa
		printf("Carta sobre la mesa: ");
		mostrarCarta(cartaMesaValor, cartaMesaColor);
		
		
		//Efectos de cartas especiales (CPU a Jugador)
		if(bloqueoCPU == 1 || cambioSentidoCPU == 1 || suma2CPU == 1 || suma4CPU == 1) {
			turno = 1;
			if(bloqueoCPU == 1) {
				bloqueoCPU = 0;
			}
			if(cambioSentidoCPU == 1) {
				cambioSentidoCPU = 0;
			}
			if(suma2CPU == 1) {
				printf("Has robado 2 cartas.\n");
				for (i = 0; i < 2; i++) {
					cartasJugadorValor[contJugador] = sacarCarta();
					cartasJugadorColor[contJugador] = sacarColor(cartasJugadorValor[contJugador]);
					contJugador++;
				}
				suma2CPU = 0;
			}
			if(suma4CPU == 1) {
				printf("Has robado 4 cartas.\n");
				for (i = 0; i < 4; i++) {
					cartasJugadorValor[contJugador] = sacarCarta();
					cartasJugadorColor[contJugador] = sacarColor(cartasJugadorValor[contJugador]);
					contJugador++;
				}
				suma4CPU = 0;
			}
		}
		
		//Turno del jugador
		if(turno == 0) {
			printf("\nTus cartas:\n");
			for(i = 0; i < contJugador; i++) {
				printf("%d) ",i + 1);
				mostrarCarta(cartasJugadorValor[i], cartasJugadorColor[i]);
			}
			
			//Elige jugar o robar
			printf("Elige una carta 1-%d o pulsa 0 para robar: ", contJugador);
        	scanf("%d", &eleccion);
        	
        	//Limpiar pantalla
			system("cls");
			printf("-- UNO --\n");
        	
        	if(eleccion == 0){
        		//Robar carta
        		cartasJugadorValor[contJugador] = sacarCarta();
				cartasJugadorColor[contJugador] = sacarColor(cartasJugadorValor[contJugador]);
				contJugador++;
				printf("\nHas robado una carta: ");
				mostrarCarta(cartasJugadorValor[contJugador - 1], cartasJugadorColor[contJugador - 1]);
				turno = 1;
			}else {
				cartaValidaJugador = 0;
				//Guardar carta seleccionada
				valorJugador = cartasJugadorValor[eleccion - 1];
            	colorJugador = cartasJugadorColor[eleccion - 1];
            	
            	// Coincide valor o color
				if(valorJugador == cartaMesaValor || colorJugador == cartaMesaColor  || valorJugador == 13 || valorJugador == 14){
					cartaValidaJugador = 1;
				}
				
				//Jugar carta (carta valida)
				if(cartaValidaJugador == 1){
					printf("\nHas jugado: ");
					mostrarCarta(valorJugador, colorJugador);
					
					cartaMesaValor = valorJugador;
					cartaMesaColor = colorJugador;
				
					//Detecta carta especial de la CPU
					especialJugador = valorJugador;
					if(especialJugador == 10) {
						bloqueoJugador = 1;
						printf("Se ha saltado el turno de la CPU\n");
						}
					if(especialJugador == 11) {
						cambioSentidoJugador = 1;
						printf("Se ha saltado el turno de la CPU\n");
					}
					if(especialJugador == 12) {
						suma2Jugador = 1;
						printf("Se ha saltado el turno de la CPU");
					}
					if(especialJugador == 13) {
						suma4Jugador = 1;
						cambioColorJugador = 1;
						printf("Se ha saltado el turno de la CPU");
					}
					if(especialJugador == 14) {
						cambioColorJugador = 1;
					}
					
	            	// Eliminar carta del jugador
	            	for(i = eleccion - 1; i < contJugador - 1; i++) {
	            	    cartasJugadorValor[i] = cartasJugadorValor[i + 1];
	            	    cartasJugadorColor[i] = cartasJugadorColor[i + 1];
	            	}
            		contJugador--;
				
					//Si el jugador ha ganado
        			if(contJugador == 0) {
        			    printf("\n¡Has ganado!\n");
        			    partidaTerminada = 1;
        			}else {
        			    turno = 1;
        			}
				}
				
				
			}
		}
		
		
		//Efectos de cartas especiales (Jugador a CPU)
		if(bloqueoJugador == 1 || cambioSentidoJugador == 1 || suma2Jugador == 1 || suma4Jugador == 1) {
			turno = 0;
			if(bloqueoJugador == 1) {
				bloqueoJugador = 0;
			}
			if(cambioSentidoJugador == 1) {
				cambioSentidoJugador = 0;
			}
			if(suma2Jugador == 1) {
				for (i = 0; i < 2; i++) {
					cartasCPUValor[contCPU] = sacarCarta();
					cartasCPUColor[contCPU] = sacarColor(cartasCPUValor[contCPU]);
					contCPU++;
				}
				printf("La CPU ha robado %d cartas\n", i);
				suma2Jugador = 0;
			}
			if(suma4Jugador == 1) {
				for (i = 0; i < 4; i++) {
					cartasCPUValor[contCPU] = sacarCarta();
					cartasCPUColor[contCPU] = sacarColor(cartasCPUValor[contCPU]);
					contCPU++;
				}
				printf("La CPU ha robado %d cartas\n", i);
				suma4Jugador = 0;
			}
		}
		if(cambioColorJugador == 1) {
			printf("Elige un color: Rojo (1) - Amarillo (2) - Verde (3) - Azul (4): ");
			scanf("%d", &colorEspecial);
			switch(colorEspecial) {
				case 1:
					cartaMesaColor = 1;
					printf("Elegiste Rojo.\n");
					cambioColorJugador = 0;
					break;
				
				case 2:
					cartaMesaColor = 2;
    				printf("Elegiste Amarillo.\n");
					cambioColorJugador = 0;
					break;
				
				case 3:
					cartaMesaColor = 3;
					printf("Elegiste Verde.\n");
					cambioColorJugador = 0;
					break;
				
				case 4:
					cartaMesaColor = 4;
					printf("Elegiste Azul.\n");
					cambioColorJugador = 0;
					break;
				
				default:
					printf("Opción no válida.\n");
					cambioColorJugador = 1;
					turno = 2;
					break;
			}
		}
		
		//Turno CPU
		if (turno == 1) {
			/*Mostrar cartas CPU (prueba)
			printf("\nCartas CPU (prueba):\n");
			for(i = 0; i < contCPU; i++) {
				printf("%d) ",i + 1);
				mostrarCarta(cartasCPUValor[i], cartasCPUColor[i]);
			}*/
			
			
        	printf("\nTurno de la CPU: \n");
        	juegoCPU = 0;
			
        	//La CPU busca cartas disponibles para jugar
        	cartaValidaCPU = -1;
			for(i = 0; i < contCPU; i++) {
				// Coincide valor
				if(cartasCPUValor[i] == cartaMesaValor) {
					juegoCPU = 1;
					cartaValidaCPU = i;
					break;
				}
			}
			for(i = 0; i < contCPU; i++) {
				// Coincide color
				if(cartasCPUColor[i] == cartaMesaColor && cartasCPUColor[i] != 0) {
					juegoCPU = 1;
					cartaValidaCPU = i;
					break;
				}
			}
			for(i = 0; i < contCPU; i++) {
				// Carta especial (+4 o cambio color)
				if(cartasCPUValor[i] == 13 || cartasCPUValor[i] == 14) {
					juegoCPU = 1;
					cartaValidaCPU = i;
					break;
				}
			}
			//Proceso de eliminar carta de CPU
			if(cartaValidaCPU != -1) {
				//Detecta carta especial de la CPU
				especialCPU = cartasCPUValor[cartaValidaCPU];
				if(especialCPU == 10) {bloqueoCPU = 1;}
				if(especialCPU == 11) {cambioSentidoCPU = 1;}
				if(especialCPU == 12) {suma2CPU = 1;}
				if(especialCPU == 13) {
					suma4CPU = 1;
					cartaMesaColor = (rand() % 4) + 1;
					colorEspecial = 1;
				}
				if(especialCPU == 14) {
					cambioColorCPU = 1;
					cartaMesaColor = (rand() % 4) + 1;
					colorEspecial = 1;
				}
				//Actulaizar carta en la mesa
				cartaMesaValor = cartasCPUValor[cartaValidaCPU];
    			if(colorEspecial == 0){
					cartaMesaColor = cartasCPUColor[cartaValidaCPU];
				}
				colorEspecial = 0;
				//Mostrar carta tirada
				printf("CPU ha jugado: ");
    			mostrarCarta(cartaMesaValor, cartaMesaColor);
    			//Eliminar carta de CPU
				for(j = cartaValidaCPU; j < contCPU - 1; j++) {
					cartasCPUValor[j] = cartasCPUValor[j + 1];
					cartasCPUColor[j] = cartasCPUColor[j + 1];
				}
				contCPU--;
				juegoCPU = 1;
			}
			
			if(juegoCPU == 0) {
				//Si la CPU no juega, roba cartas
				cartasCPUValor[contCPU] = sacarCarta();
            	cartasCPUColor[contCPU] = sacarColor(cartasCPUValor[contCPU]);
            	contCPU++;
            	printf("CPU ha robado una carta.\n");
			}
			//Si la CPU ha ganado
			if(contCPU == 0) {
        	    printf("\n¡La CPU ha ganado!\n");
        	    partidaTerminada = 1;
        	}else {
        	    turno = 0;
        	}
		}
        	        
        
	} while(partidaTerminada == 0);
	printf("\nFin de la partida");
}
