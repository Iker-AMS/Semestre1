Algoritmo promedio_y_status
	Definir calificacion1, calificacion2, calificacion3 Como Real
	Definir promedio Como Real
	
	Escribir "Ingrese su calificacion de matemáticas"
	Leer calificacion1
	Escribir "Ingrese su calificacion de español"
	Leer calificacion2
	Escribir "Ingrese su calificacion de ciencias"
	Leer calificacion3
	
	promedio = (calificacion1 + calificacion2 + calificacion3) / 3
	
	Si promedio >= 6 Entonces
		Escribir "Su promedio es: ", promedio
		Escribir "Cuenta con un promedio aprobatorio, felicidades"
	SiNo
		Escribir "Su promedio es: ", promedio
		Escribir "No cuenta con un promedio aprobatorio, debe presentar extraordinario"
	Fin Si
	
	
FinAlgoritmo
