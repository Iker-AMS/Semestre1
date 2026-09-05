Algoritmo calificaciones_del_grupo
	
	Definir alumno Como Caracter
	Definir respuesta Como Caracter
	Definir calificacion_parcial1 Como Real
	Definir calificacion_parcial2 Como Real
	Definir calificacion_parcial3 Como Real
	Definir total_de_alumnos Como Entero
	Definir promedio_alumno Como Real
	Definir promedio_general Como Real
	Definir promedio_grupo Como Real
	
	total_de_alumnos = 0
	promedio_general = 0
	
	Escribir "Escriba su nombre"
	Leer respuesta
	
	Mientras respuesta <> "listo" Hacer
		
		Escribir "Ingresa tus calificaciones de sus tres parciales"
		Leer calificacion_parcial1
		Leer calificacion_parcial2
		Leer calificacion_parcial3
		promedio_alumno = (calificacion_parcial1 + calificacion_parcial2 + calificacion_parcial3) / 3
		Escribir " Tu promedio es de: ", promedio_alumno
		total_de_alumnos = total_de_alumnos + 1
		promedio_general = promedio_general + promedio_alumno
		
		Escribir "Escriba su nombre o listo cuando desee terminar"
		Leer respuesta
		
	Fin Mientras
	
	promedio_grupo = promedio_general / total_de_alumnos
	Escribir "El promedio general del grupo es de: ", promedio_grupo
	
FinAlgoritmo
