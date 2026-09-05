Algoritmo subproceso_reutilizable
	
	Definir name1, name2 Como Caracter
	Definir nota1_1, nota2_1, nota3_1 Como Real
	Definir nota1_2, nota2_2, nota3_2 Como Real
	Definir prom1, prom2 Como Real
	
	Escribir "Ingrese su nombre: "
	Leer name1
	Escribir "Ingrese sus calificaciones: "
	Leer nota1_1
	Leer nota2_1
	Leer nota3_1
	prom1 <- calcularpromedio(nota1_1,nota2_1,nota3_1)
	
	Escribir "Ingrese su nombre: "
	Leer name2
	Escribir "Ingrese sus calificaciones: "
	Leer nota1_2
	Leer nota2_2
	Leer nota3_2
	prom2 =calcularpromedio(nota1_2,nota2_2,nota3_2) 
	
	Escribir "El promedio del alumno 1 es: ", prom1
	Escribir "El promedio del alumno 2 es: ", prom2
	
	
	
FinAlgoritmo

SubProceso resultado<- calcularpromedio(nota1,nota2,nota3)
	resultado<- (nota1+nota2+nota3)/3
	FinSubProceso
