Algoritmo proyectov1_2
	
	definir alumno1 Como Caracter
	definir alumno2 Como Caracter
	definir alumno3 Como Caracter
	definir nota1_parcial1 Como Real
	definir nota2_parcial1 Como Real
	definir nota3_parcial1 Como Real
	definir nota1_parcial2 Como Real
	definir nota2_parcial2 Como Real
	definir nota3_parcial2 Como Real
	definir nota1_parcial3 Como Real
	definir nota2_parcial3 Como Real
	definir nota3_parcial3 Como Real
	definir prom1, prom2, prom3 Como Real
	definir datos_capturados Como Logico
	definir opcion Como Entero
	
	datos_capturados <- falso
	
	Repetir
		Escribir "MENÚ :)"
		Escribir "1. Capturar datos."
		Escribir "2. Mostrar promedios."
		Escribir "3. Mostrar el mejor promedio."
		Escribir "4. Salir."
		Leer opcion
		
		Segun opcion Hacer
			1:
				Escribir "Alumno 1, escriba su nombre"
				Leer alumno1
				Escribir "Ingrese sus calificaciones de los tres parciales"
				Leer nota1_parcial1
				Leer nota2_parcial1
				Leer nota3_parcial1
				
				Escribir "Alumno 2, escriba su nombre"
				Leer alumno2
				Escribir "Ingrese sus calificaciones de los tres parciales"
				Leer nota1_parcial2
				Leer nota2_parcial2
				Leer nota3_parcial2
				
				Escribir "Alumno 3, escriba su nombre"
				Leer alumno3
				Escribir "Ingrese sus calificaciones de los tres parciales"
				Leer nota1_parcial3
				Leer nota2_parcial3
				Leer nota3_parcial3
				
				datos_capturados <- verdadero
				
			2:
				Si datos_capturados = falso Entonces
					Escribir "Primero debes capturar los datos"
				SiNo
					prom1 <- calcularpromedio(nota1_parcial1,nota2_parcial1,nota3_parcial1)
					
					prom2 <- calcularpromedio(nota1_parcial2,nota2_parcial2,nota3_parcial2)
					
					prom3 <- calcularpromedio(nota1_parcial3,nota2_parcial3,nota3_parcial3)
					
					Escribir "Promedio de: ", alumno1 ", ", prom1
					Escribir "Promedio de: ", alumno2 ", ", prom2
					Escribir "Promedio de: ", alumno3 ", ", prom3
				Fin Si
				
			3:
				Si datos_capturados = falso Entonces
					Escribir "Primero debes capturar los datos"
				SiNo
					
					prom1 <- calcularpromedio(nota1_parcial1,nota2_parcial1,nota3_parcial1)
					
					prom2 <- calcularpromedio(nota1_parcial2,nota2_parcial2,nota3_parcial2)
					
					prom3 <- calcularpromedio(nota1_parcial3,nota2_parcial3,nota3_parcial3)
					
					Si prom1 > prom2 y prom1 > prom3 Entonces
						Escribir "El promedio más alto es ", prom1 " de ", alumno1 
					SiNo
						Si prom2 > prom1 y prom2 > prom3 Entonces
							Escribir "El promedio más alto es ", prom2 " de ", alumno2
						SiNo
							Si prom3 > prom1 y prom3 >prom2 Entonces
								Escribir "El promedio más alto es ", prom3 " de ", alumno3
							SiNo
								Si prom1 = prom2 y prom1 = prom3 y prom2 = prom3 Entonces
									Escribir "Todos los alumnos sacaron el promedio máximo de ", prom1
								SiNo
									Si prom1 = prom3 Entonces
										Escribir "Ambos promedios de ", prom1 " de ", alumno1, ", " alumno3 " son los más altos"
									SiNo
										Si prom1 = prom2 Entonces
											Escribir "Ambos promedios de ", prom1 " de ", alumno1, ", " alumno2 " son los más altos"
										SiNo
											Si prom2 = prom3 Entonces
												Escribir "Ambos promedios de ", prom2 " de ", alumno2, ", " alumno3 " son los más altos"
											SiNo
												Escribir "Error"
											Fin Si
										Fin Si
									Fin Si
								Fin Si
							Fin Si
						Fin Si
	Fin Si
				Fin Si
				
			4:
				Escribir "Saliendo..."
				
			De Otro Modo:
				Escribir "Opción no valida"
				
		Fin Segun
		
	Hasta Que opcion = 4
	
FinAlgoritmo
SubProceso resultado<- calcularpromedio(nota1,nota2,nota3)
	resultado<- (nota1+nota2+nota3)/3
FinSubProceso