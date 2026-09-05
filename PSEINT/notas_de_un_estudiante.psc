Algoritmo notas_de_un_estudiante
	Definir contador Como Entero
	Definir notas Como Entero
	Definir reprobadas Como Entero
	Definir aprobadas Como Entero
	Definir promedio Como Real
	Definir nota_actual Como Real
	Definir suma_total Como Real
	Definir suma_aprobadas Como Real
	Definir suma_reprobadas Como Real
	Definir promedio_general Como Real
	Definir promedio_aprobadas Como Real
	Definir promedio_reprobadas Como Real
	
	contador = 0
	aprobadas = 0
	reprobadas = 0
	suma_aprobadas = 0
	suma_reprobadas = 0
	suma_total = 0
	
	Escribir "¿Cuantas notas quieres ingresar?"
	Leer notas
	Escribir "Escriba sus notas:"
	Mientras contador < notas Hacer
		leer nota_actual
		contador = contador + 1
		si nota_actual >= 6 Entonces
			aprobadas = aprobadas + 1
			suma_aprobadas = suma_aprobadas + nota_actual
			suma_total = suma_total + nota_actual
		SiNo
			reprobadas = reprobadas + 1
			suma_reprobadas = suma_reprobadas + nota_actual
			suma_total = suma_total + nota_actual
		FinSi
	Fin Mientras
	
	si reprobadas > 0 Entonces
		promedio_reprobadas = suma_reprobadas / reprobadas
		Escribir "Tu promedio de reprobadas es de: ", promedio_reprobadas
	SiNo
		Escribir "No hay materias reprobadas"
	FinSi
	
	Si aprobadas > 0 Entonces
		promedio_aprobadas = suma_aprobadas / aprobadas
		Escribir "Tu promedio de aprobadas es de: ", promedio_aprobadas
	SiNo
		Escribir "No hay materias aprobadas"
	Fin Si
	
	promedio_general = suma_total / notas
	
	Escribir "Tu promedio general es de: ", promedio_general
	Escribir "Tus notas aprobadas son: ", aprobadas
	Escribir "Tus notas reprobadas son: ", reprobadas
	
FinAlgoritmo